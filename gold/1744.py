import sys
input = sys.stdin.readline

n = int(input())

minus = []
plus = []
zero = []
for i in range(n):
    tmp = int(input())
    if tmp > 0:
        plus.append(tmp)
    elif tmp == 0:
        zero.append(tmp)
    else:
        minus.append(tmp)

plus.sort(reverse = True)
minus.sort()
p = len(plus)
m = len(minus)

answer = 0
for i in range(0, m-1, 2):
    answer += (minus[i] * minus[i+1])
for i in range(0, p-1, 2):
    if (plus[i] * plus[i+1]) > (plus[i] + plus[i+1]):
        answer += (plus[i] * plus[i+1])
    else:
        answer += (plus[i] + plus[i+1])
if p % 2 == 1:
    answer += plus[p-1]
if m % 2 == 1:
    if len(zero) == 0:
        answer += minus[m-1]

print(answer)
