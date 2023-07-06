import sys
input = sys.stdin.readline

n = int(input())
k = int(input())

start = 1
end = k
while start <= end:
    mid = (start+end)//2
    cnt = 0
    for i in range(1, n+1):
        if k // i == 0:
            break
        cnt += min(mid // i, n)
        
    if cnt > k - 1:
        end = mid - 1
    else:
        start = mid + 1
print(end+1)
