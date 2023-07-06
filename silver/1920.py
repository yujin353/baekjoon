import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a.sort()

m = int(input())
b = list(map(int, input().split()))
for i in range(m):
    start = 0
    end = n - 1
    target = b[i]
    find = False
    
    while start <= end:
        mid = (start+end)//2
        a_mid = a[mid]

        if target < a_mid:
            end = mid - 1
        elif target > a_mid:
            start = mid + 1
        elif target == a_mid:
            find = True
            break
        
    if find == True:
        print(1)
    else:
        print(0)
