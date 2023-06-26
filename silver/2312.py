import sys
input = sys.stdin.readline

def factor(num):
    for p in range(2, num+1):
        cnt = 0
        while True:
            if num % p == 0:
                num = int(num / p)
                cnt += 1
            else:
                break
        if cnt > 0:
            print(p, cnt)

n = int(input())
for i in range(n):
    num = int(input())
    factor(num)
