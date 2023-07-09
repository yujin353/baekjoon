import sys, math
input = sys.stdin.readline

Min, Max = map(int, input().split())

end = int(math.sqrt(Max))
check = [1] * (Max-Min+1)

for i in range(2, end+1):
    sqr = i*i
    start = Min // sqr

    if Min % sqr != 0:
        start += 1
    for j in range(start, Max//sqr + 1):
        check[j*sqr - Min] = 0


cnt = 0
for i in range(0, Max-Min+1):
    if check[i] == 1:
        cnt += 1

print(cnt)
