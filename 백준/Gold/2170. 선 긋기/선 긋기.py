import sys
input = sys.stdin.readline

N = int(input())    # 선을 그은 횟수 (1이상 1,000,000이하)
nums = []
for _ in range(N):
    nums.append(list(map(int, input().split())))    # (시작점, 끝점)

# 시작점을 기준으로 정렬
nums.sort(key=lambda x:x[0])

start, end = nums[0]
ans = 0
for i in range(1,N):
    # 기준 선과 겹치거나 이어지는 선 찾기
    if start<=nums[i][0]<=end :
        end = max(end,nums[i][1])
        continue

    # 선 길이 구하기
    ans += end-start
    start,end = nums[i]  # 기준 시작점, 끝점 update

ans += end-start
print(ans)