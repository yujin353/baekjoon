import sys
input = sys.stdin.readline

n = int(input())
card = list(map(int, input().split()))
m = int(input())
need = list(map(int, input().split()))

have = dict()
for i in range(n):
    if card[i] in have:
        have[card[i]] += 1
    else:
        have[card[i]] = 1
        
for i in range(m):
    if need[i] in have:
        print(have[need[i]], end = ' ')
    else:
        print('0', end = ' ')
