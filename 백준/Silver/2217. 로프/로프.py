import sys, heapq
input = sys.stdin.readline

n = int(input())

w = []
for _ in range(n):
    heapq.heappush(w,-int(input()))

ans = 0
for i in range(n):
    ans = max(ans, heapq.heappop(w)*(i+1)*-1)


print(ans)