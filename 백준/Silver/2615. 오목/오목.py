# 바둑판 상태 정보 입력 : 19x19
board = [ list(map(int, input().split())) for _ in range(19) ]

# 방문 여부 확인 : 19x19x4
visited = [[[0 for _ in range(4)] for _ in range(19)] for _ in range(19)]   # 1st+2nd : 위치 / 3rd : 방향(가로,세로,좌상우하,좌하우상)
leftX, leftY = -1, -1       # 가장 왼쪽에 있는 좌표

# 이동 : 가좌, 가우, 세위, 세아, 대1좌, 대1우, 대2좌, 대2우
dy = [[0,0],
      [-1,1],
      [-1,1],
      [1,-1]]
dx = [[-1,1],
      [0,0],
      [-1,1],
      [-1,1]]

# 바둑판 탐색 : (0,0) 부터 (18,18)까지 순서대로 탐색
for y in range(19) :
    for x in range(19) :
        # 바둑알 여부 확인
        if not board[y][x] : continue   # PASS : 바둑알이 없는 경우
        nowColor = board[y][x]          # 현재 바둑알 색

        # 방향 별로 확인
        for d in range(4) : # 가로:0, 세로:1, 좌상우하:2, 좌하우상:3
            # 방향 별 탐색 여부 확인
            if (visited[y][x][d]) : continue # 현재 위치에서 해당 방향에 대해 이미 탐색한 경우

            visited[y][x][d] = 1    # 현재 위치의 방향 별 탐색 여부 체크
            cnt = 1                 # 연속적인 바둑알 개수

            # 왼쪽 또는 위쪽 탐색:0 / 오른쪽 또는 아래쪽 탐색:1
            for i in range(2):
                nowY, nowX = y, x
                while True :
                    # 이동
                    nowY += dy[d][i]
                    nowX += dx[d][i]

                    # 탐색 종료 조건 1 : 바둑판을 벗어난 경우
                    if nowY<0 or nowY>=19 or nowX<0 or nowX>=19 :
                        if i == 0 : # 왼쪽/아래쪽 탐색 -> 가장 왼쪽 바둑알 위치 저장
                            leftY = nowY - dy[d][i]
                            leftX = nowX - dx[d][i]
                        break

                    # 탐색 종료 조건 2 : 색이 다르거나, 바둑알이 없는 경우
                    if board[nowY][nowX]!=nowColor :
                        if i == 0 : # 왼쪽/아래쪽 탐색 -> 가장 왼쪽 바둑알 위치 저장
                            leftY = nowY - dy[d][i]
                            leftX = nowX - dx[d][i]
                        break

                    # 탐색 성공
                    cnt+=1  # UPDATE : 연속 바둑알 개수
                    visited[nowY][nowX][d] = 1  # UPDATE : 이동 위치의 현재 방향에 대한 탐색 여부

            # 우승자 결정, 프로그램 종료
            if cnt==5:
                print(nowColor)
                print(f'{leftY+1} {leftX+1}')
                exit(0)

print(0)    # 우승자 미결정