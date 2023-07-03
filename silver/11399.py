import sys
input = sys.stdin.readline

n = int(input())
p = list(map(int, input().split()))

for i in range(1, n):
    insert_point = i
    insert_value = p[i]
    
    for j in range(i-1, -1, -1):
        if p[j] < p[i]:
            insert_point = j + 1
            break
        if j == 0:
            insert_point = 0

    for j in range(i, insert_point, -1):
        p[j] = p[j-1]
    p[insert_point] = insert_value

s = [0] * n
s[0] = p[0]

for i in range(1,n):
    s[i] = s[i-1] + p[i]

accum = 0
for i in s:
    accum += i

print(accum)
