N, M = map(int,input().split())
floor = []  # 바닥 정보
for n in range(N):
    floor.append(list(input()))

visited = [[0 for _ in range(M)] for _ in range(N)]

ans = 0

for n in range(N):
    for m in range(M):
        if visited[n][m] : continue # PASS : 이미 방문한 경우

        visited[n][m]=1
        ans += 1                    # 나무 판자 개수 증가

        # 1) 바닥 장식이 '-'인 경우
        if floor[n][m] == '-':
            x_ = m
            while True:
                x_ += 1                                     # 오른쪽으로 이동
                if x_>=M : break                            # PASS : 바닥을 벗어난 경우
                if visited[n][x_] : break                   # PASS : 이미 방문한 경우
                if floor[n][x_] == '-': visited[n][x_] = 1  # 하나의 나무 판자로 인식
                else : break                                # PASS : 다른 바닥 장식



        # 2) 바닥 장식이 '|'인 경우
        elif floor[n][m] == '|' :
            y_ = n
            while True:
                y_ += 1                                     # 아래쪽으로 이동
                if y_ >= N: break                           # PASS : 바닥을 벗어난 경우
                if visited[y_][m]: break                    # PASS : 이미 방문한 경우
                if floor[y_][m] == '|': visited[y_][m] = 1  # 하나의 나무 판자로 인식
                else : break                                # PASS : 다른 바닥 장식

print(ans)