from collections import deque

N, L, R = map(int, input().split())

board = []  # idx:위치  value:인구 수
# 입력 : 나라 별 초기 인구 수
for _ in range(N):
    board.append(list(map(int, input().split())))

ans = 0 # 정답 : 인구 이동 발생 기간

dr = [-1, 1, 0, 0]  # 상하좌우
dc = [0, 0, -1, 1]
dir = [1,0,3,2]     # 현재 위치에서 i방향의 나라를 탐색할 때, 해당 나라에서의 상하좌우 확인 방향

while True:

    flag = 1    # 인구 이동 종료 여부 1:종료, 0:계속

    visited = [[False] * N for _ in range(N)]                       # 방문 여부
    checked = [[[False] * N for _ in range(N)] for _ in range(4)]   # 상하좌우 확인 여부

    for r in range(N):
        for c in range(N):

            if visited[r][c] : continue     # PASS : 이미 방문한 경우

            # (r,c)를 기준으로 연합 국가 탐색 시작
            q = deque([(r, c)])
            people_cnt, union_cnt = 0, 0    # (r,c) 나라 기준 : 연합 인구 수, 연합 나라 수
            unions = []                     # 연합 나라 좌표

            while q:
                now_r, now_c = q.popleft()  # 현재 위치

                if visited[now_r][now_c]: continue  # PASS : 이미 방문

                visited[now_r][now_c] = True        # now_r, now_c 방문 처리

                people_cnt += board[now_r][now_c]   # UPDATE 연합 인구 수
                union_cnt += 1                      # UPDATE 연합 나라 수
                unions.append((now_r, now_c))       # 연합 나라 좌표 추가

                # 상하좌우 확인
                for i in range(4):
                    if checked[i][now_r][now_c] : continue          # PASS : 현재 위치 (now_r, now_c)에서 i 방향을 이미 탐색한 경우

                    checked[i][now_r][now_c] = True                 # 현재 위치 (now_r, now_c)에서 i 방향 탐색 여부 update

                    r_, c_ = now_r+dr[i], now_c+dc[i]               # i 방향으로 인접한 나라의 위치

                    if r_<0 or r_>=N or c_<0 or c_>=N : continue    # PASS : 지도 밖

                    # 인구 수 차이 확인
                    if L <= abs(board[now_r][now_c]-board[r_][c_]) <= R :
                        q.append((r_, c_))                          # 탐색 큐에 추가
                        checked[dir[i]][r_][c_] = True              # r_,c_ 나라에서 dir[i] 방향 탐색 여부 update

            if union_cnt == 1 : continue    # (r,c) 나라와의 연합 없음

            # 인구 이동 발생
            flag = 0
            cnt = people_cnt//union_cnt # 인구 재 분포
            for pos in unions:
                board[pos[0]][pos[1]] = cnt

    if flag : break # 인구 이동 종료
    ans += 1        # 인구 이동 함

print(ans)