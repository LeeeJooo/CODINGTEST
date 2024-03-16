N = int(input())    # 방 크기 : NxN
room = list(input() for _ in range(N))    # '.':빈칸, 'X':짐
ans = [0,0] # 가로, 세로

for i in range(N):
    cnt = [0,0]
    for j in range(N):
        # i 번 째 행 탐색
        if room[i][j] == '.' :                  # << 빈칸인 경우 >>
            cnt[0]+=1                           # 연속된 빈칸 개수 증가
            if j==N-1 and cnt[0]>=2 : ans[0]+=1 # 마지막 열인 경우 연속된 빈칸 개수 확인
        elif room[i][j] == 'X':                 # << 짐인 경우 >>
            if cnt[0] >= 2:                     # 1) 연속된 빈칸이 2개 이상일 경우
                ans[0] += 1                     #   -> 누울 수 있음
            cnt[0] = 0                          # 2) cnt reset
        # i 번 째 열 탐색
        if room[j][i] == '.' :                  # << 빈칸인 경우 >>
            cnt[1]+=1                           # 연속된 빈칸 개수 증가
            if j==N-1 and cnt[1]>=2 : ans[1]+=1 # 마지막 열인 경우 연속된 빈칸 개수 확인
        elif room[j][i] == 'X':                 # << 짐인 경우 >>
            if cnt[1] >= 2:                     # 1) 연속된 빈칸이 2개 이상일 경우
                ans[1] += 1                     #   -> 누울 수 있음
            cnt[1] = 0                          # 2) cnt reset

print(*ans)