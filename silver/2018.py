import sys
input = sys.stdin.readline

n = int(input())

cnt = 1
start = 1
end = 1
tmp = 0
while start < n/2:
    tmp += end
    if tmp > n:
        start += 1
        end = start
        tmp = 0
    elif tmp == n:
        cnt += 1
        start += 1
        end = start
        tmp = 0
    else:
        end += 1
print(cnt)
