n = int(input())

def binary_search(s,e, n):
    if s>=e :
        print(s)
        exit(0)
    mid = (s+e)//2
    if mid**2 == n :
        print(mid)
        exit(0)
    if mid**2 > n :
        binary_search(s, mid,n)
    else:
        binary_search(mid+1, e,n)

binary_search(0,n,n)