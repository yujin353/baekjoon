import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))

s = []
tmp = 0
for i in a:
    tmp += i
    s.append(tmp)

cnt = 0
c = [0]*m
for i in s:
    i %= m
    c[i] += 1
    if i == 0:
        cnt += 1

for i in c:
    if i > 1:
        cnt += i * (i-1) // 2
print(cnt)
