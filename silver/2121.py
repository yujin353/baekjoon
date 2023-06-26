import sys
input = sys.stdin.readline

n = int(input())
a, b = map(int, input().split())

p = set()
for i in range(n):
    x, y = map(int, input().split())
    p.add((x, y))

cnt = 0
for i in p:
    if (i[0] + a, i[1]) in p:
        if (i[0], i[1] + b) in p:
            if (i[0] + a, i[1] + b) in p:
                cnt += 1

print(cnt)
