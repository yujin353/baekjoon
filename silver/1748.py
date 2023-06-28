import sys
input = sys.stdin.readline

n = input()
itr = len(n) - 1 # total length + 1

ans = 0
ten = 1
for i in range(1, itr):
    ans += i * (9 * ten)
    ten *= 10
ans += (int(n) - (ten - 1)) * itr

print(ans)
