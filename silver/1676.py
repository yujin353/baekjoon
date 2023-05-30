import sys
input = sys.stdin.readline

N = int(input())

x5 = 0
for i in range(1, N+1):
    if i % 5 == 0:
        x5 += 1
        if i % 25 == 0:
            x5 += 1
            if i % 125 == 0:
                x5 += 1

print(x5)
