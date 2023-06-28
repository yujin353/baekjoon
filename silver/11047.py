import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))
a.sort(reverse = True)

cnt = 0
for i in range(n):
    if k >= a[i]:
        cnt += int(k/a[i])
        k %= a[i]
    if k == 0 :
        break
print(cnt)
