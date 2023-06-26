import sys, math
input = sys.stdin.readline

def prime(num):
    cnt = int(math.sqrt(num)) + 1
    for i in range(2, cnt):
        if num % i == 0:
            return 0
    return 1

m,n = map(int, input().split())
for i in range(m, n+1):
    if i == 1:
        continue
    
    if prime(i) == 1:
        print(i)
