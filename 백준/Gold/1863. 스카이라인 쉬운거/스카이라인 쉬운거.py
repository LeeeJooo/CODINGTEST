stack = []
cnt = 0
def solve(y):
    global cnt
    while stack:
        # 높이가 낮아지면 건물 개수 증가
        if stack[-1] > y :
            cnt+=1
            stack.pop()
        else : break

    if stack and stack[-1] == y : return

    # 스택이 비어있거나 높이가 높아지면 스택에 추가
    stack.append(y)



for _ in range(int(input())):
    x, y = map(int,input().split())
    solve(y)

while stack:
    # 높이가 0이 아니면 건물 개수 증가
    if stack.pop() : cnt+=1

print(cnt)