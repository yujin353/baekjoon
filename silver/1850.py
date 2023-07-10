import sys
input = sys.stdin.readline

a, b = map(int, input().split())

while a > 0 and b > 0:
    if a > b:
        a %= b
    else:
        b %= a
        
if a == 0:
    lcm = b
else:
    lcm = a

lcm = min(lcm, 10000000-1)

print('1' * lcm)
