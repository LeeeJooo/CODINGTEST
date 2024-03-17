def bin_search(start, end, num) :
    # 종료 조건
    if start >= end :
        ans.append(0)
        return

    mid = (start + end)//2

    # 발견
    if num==note1[mid]:
        ans.append(1)
        return

    # 미발견
    if num < note1[mid]: bin_search(start,mid,num)
    else : bin_search(mid+1,end,num)

for _ in range(int(input())):   # 입력:Test Case
    N = int(input())
    note1 = sorted(list(map(int,input().split())))
    M = int(input())
    ans=[]  # 정답
    for num in list(map(int,input().split())):
        bin_search(0, N, num)

    print(*ans, sep="\n")