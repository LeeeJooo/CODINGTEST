N, M = map(int, input().split())

studio = [ list(map(int, input().split())) for _ in range(N) ]

queue = []  # value : CCTV 좌표
room_map = [[0 for _ in range(M)] for _ in range(N)]    # value : 해당 위치를 감시하고 있는 CCTV 개수
min_ans = 100   # 정답 : 사각지대 최소 크기

dy = [-1,1,0,0] # 상하좌우
dx = [0,0,-1,1]
cctv_dir=[                              # 각 CCTV가 감시할 수 있는 경우의 수
    [],
    [[0],[1],[2],[3]],                  # 1번 : 상 | 하 | 좌 | 우
    [[0,1], [2,3]],                     # 2번 : 상하 | 좌우
    [[0,2],[0,3],[1,2],[1,3]],          # 3번 : 상좌 | 상우 | 하좌 | 하우
    [[0,1,2],[0,1,3],[0,2,3],[1,2,3]],  # 4번: 상하좌 | 상하우 | 상좌우 | 하좌우
    [[0,1,2,3]]                         # 5번 : 상하좌우
]

# CCTV 정보
wall_cnt = 0
cctv_cnt = 0
for y in range(N):
    for x in range(M):
        if studio[y][x] == 0 : continue # PASS : 빈 칸
        if studio[y][x] == 6 :
            room_map[y][x] = 1  # 사각지대 제외 : 벽
            wall_cnt += 1       # 벽 개수
            continue
        room_map[y][x] = 1      # 사각지대 제외 : CCTV
        cctv_cnt += 1           # CCTV 개수
        queue.append((y,x))     # CCTV 위치 저장

def dfs(cnt):
    global cctv_cnt, min_ans

    # 종료 조건 : 모든 CCTV 감시 범위 체크 완
    if cctv_cnt == cnt:
        ans = 0
        for n in range(N):
            for m in range(M):
                if room_map[n][m] == 0 : ans += 1  # 사각지대 감지

        if ans < min_ans: min_ans = ans         # UPDATE : 사각지대 최소 크기
        return  # 종료

    # 현재 CCTV 위치
    y, x = queue[cnt]       # 현재 CCTV 위치
    cctv_num = studio[y][x] # 현재 CCTV의 번호

    # CCTV 별 감시가 가능한 경우의 수
    for dirs in cctv_dir[cctv_num]:
        # 감시하기
        for d in dirs:
            # 감시
            y_, x_ = y, x
            while True:
                y_ += dy[d]
                x_ += dx[d]

                if y_<0 or y_>=N or x_<0 or x_>=M : break   # 감시 끝 : MAP 벗어난 경우
                if studio[y_][x_]==6 : break                # 감시 끝 : 벽인 경우
                room_map[y_][x_] += 1                       # UPDATE 해당 위치를 감시하는 CCTV 개수

        # 다음 CCTV로 넘어가기
        dfs(cnt+1)

        # 감시 취소
        for d in dirs:
            # 감시
            y_, x_ = y, x
            while True:
                y_ += dy[d]
                x_ += dx[d]

                if y_ < 0 or y_ >= N or x_ < 0 or x_ >= M: break  # 감시 끝 : MAP 벗어난 경우
                if studio[y_][x_] == 6: break  # 감시 끝 : 벽인 경우
                room_map[y_][x_] -= 1  # UPDATE 해당 위치를 감시하는 CCTV 개수


if cctv_cnt == 0:       # CCTV가 없는 경우
    print(N*M-wall_cnt) # 벽을 제외한 모든 칸이 사각지대
    exit(0)

dfs(0)  # 첫 번째 CCTV부터 시작

print(min_ans)