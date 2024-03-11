nums = []
n = int(input())
for _ in range(n) :
    nums.append(input())

original_len = len(nums[0])
ans = 0
for i in range(1,original_len+1) :
    check=[]
    for j in range(n) :
        check.append(int(nums[j][-i:]))

    check = set(check)
    if len(check) == n : break
    ans+=1

print(ans+1)
