import sys, math
input = sys.stdin.readline

A, B = map(int, input().split())
a = int(math.sqrt(A))
b = int(math.sqrt(B))

candi = [0] * (b+1)
for i in range(2, b+1):
    candi[i] = i
   
for i in range(2, int(math.sqrt(b))+1):
    if candi[i] == 0:
        continue
    for j in range(i+i, b+1, i):
        candi[j] = 0

cnt = 0
for c in candi:
    if c != 0:
        n = 2
        while c ** n <= B:
            if c ** n >= A:
                cnt += 1
            n += 1

print(cnt)
