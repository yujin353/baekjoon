import sys
input = sys.stdin.readline

n = int(input())
num = list(map(int, input().split()))

balloon = []
for i in range(1, n+1):
    balloon.append(i)

index = 0
for i in range(n-1):
    out = balloon[index]
    print(out, end = ' ')
    balloon.remove(out)
    index = (index + num[index]) % len(balloon) - 1
print(balloon[0])
