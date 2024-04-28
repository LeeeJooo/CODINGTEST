from collections import deque
import sys
input = sys.stdin.readline

R,C,N = map(int,input().split())

isNotBombs = dict() # key: 현재 폭탄이 없는 위치

board = []
timer = [[0]*C for _ in range(R)]
q = deque()
q_now = deque()
for r in range(R):
    board.append(list(input()))
    for c in range(C):
        if board[r][c]=='O':    # 폭탄이 설치된 곳
            q.append((3,r,c))   # 터지는시간, 설치 위치
            timer[r][c] = 3
        else :                  # 폭탄이 없는 곳
            isNotBombs[(r,c)] = True


dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for t in range(2,N+1):  # t : 현재 시간
    if t%2 == 0 :       # 폭탄 설치
        for r,c in isNotBombs.keys():   # 폭탄 없는 곳
            board[r][c] = 'O'           # 설치
            timer[r][c] = t+3
            q.append((t+3, r, c))
        isNotBombs = dict()             # 초기화

    elif t%2 == 1 :              # 폭발
        if q[0][0] != t : continue  # 터질 폭탄이 없음
        while q and q[0][0] == t:         # 터질 폭탄이 있을 때까지
            _, r, c = q.popleft()
            if (r,c) in isNotBombs : continue   # 폭탄이 없는 경우 pass
            if timer[r][c] != t : continue      # 새로 설치된 폭탄일 경우
            q_now.append((r,c))

        while q_now :
            r,c = q_now.popleft()
            isNotBombs[(r,c)] = True    # 현재 위치 폭발
            board[r][c] = '.'
            # 상하좌우
            for i in range(4):
                r_, c_ = r+dr[i], c+dc[i]
                if r_<0 or r_>=R or c_<0 or c_>=C : continue    # map 벗어남
                isNotBombs[(r_, c_)] = True  # 현재 위치 폭발
                board[r_][c_] = '.'

for r in range(R):
    print(''.join(board[r]), end="")