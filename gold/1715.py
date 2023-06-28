import sys
input = sys.stdin.readline

n = int(input())
card = [0] * n
for i in range(n):
    card[i] = int(input())
card.sort()

tot = 0
for i in range(n-1):
    min_sum = min(card[0] + card[1], card[0] + card[n-1-i*2])
    tot += (min_sum)
    del card[0:2]
    card.append(min_sum)
print(tot)
