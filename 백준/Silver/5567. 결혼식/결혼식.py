import sys
input = sys.stdin.readline

n = int(input()) # 동기 수
m = int(input()) # 리스트 길이

graph = [[] for _ in range(n+1)]    #idx:동기번호, value:친구 리스트

# 친구 관계 기록
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 상근이 친구가 없는 경우
if not len(graph[a]) : 
    print(0)
    exit(0)

visited = [False for _ in range(n+1)]
visited[1] = True                   # 본인 체크

# 상근이 친구
ans = len(graph[1])
for friend in graph[1] :
    visited[friend]=True            # 친구 체크

# 상근이 친구의 친구
for friend in graph[1] :
    for f in graph[friend] : 
        if visited[f] : continue    # 이미 체크
        visited[f] = True
        ans += 1

print(ans)