n = int(input())

cnt7, rest = divmod(n,7)

match rest:
    case 0: # 7원 사용
        print(cnt7)
    case 1: # 7원, 1원 사용
        print(cnt7+1)
    case 2: # 7원, 2원 사용
        print(cnt7+1)
    case 3:
        if cnt7==0: print(2)    # (n=3인 경우) 1원, 2원 사용
        else : print(cnt7+1)    # 7원 하나를 사용하지 않고 7원+3원=10원을 5원 2개로 사용
    case 4: # 7원, 2원 사용
        print(cnt7+2)
    case 5: # 7원, 5원 사용
        print(cnt7+1)
    case 6: # 7원, 2원, 3원 사용
        print(cnt7+2)