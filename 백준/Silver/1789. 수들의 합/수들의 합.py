S = int(input())

n = 2
while True:
    if S-n*(n-1)/2 <= n-1 : break
    n+=1

print(n-1)