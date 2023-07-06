import sys
input = sys.stdin.readline

n, m = map(int, input().split())
lct = list(map(int, input().split()))

start = 0
end = 0
for i in lct:
    if start < i:
        start = i
    end += i

while start <= end:
    mid = (start+end)//2
    tot = 0
    cnt = 0

    for i in range(n):
        if tot + lct[i] > mid:
            cnt += 1
            tot = 0
        tot += lct[i]

    if tot != 0:
        cnt += 1
    if cnt > m:
        start = mid + 1
    else:
        end = mid - 1

print(start)
