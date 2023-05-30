import sys
input = sys.stdin.readline

N = int(input())
mem = []

for i in range(N):
    mem.append(list(input().split()))

mem.sort(key = lambda item: int(item[0]))

for m in mem:
    print(m[0], m[1])
