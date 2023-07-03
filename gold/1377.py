import sys
input = sys.stdin.readline

n = int(input())
a = []
for i in range(n):
    a.append((int(input()), i))

sortA = sorted(a)

maxN = 0
for i in range(n):
    if maxN < sortA[i][1] - i:
        maxN = sortA[i][1] - i

print(maxN + 1)
