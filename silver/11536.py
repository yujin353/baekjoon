import sys

N = int(sys.stdin.readline())
name = [sys.stdin.readline().strip() for _ in range(N)]

inc = sorted(name)
dec = list(reversed(inc))

if name == inc:
    print('INCREASING')
elif name == dec:
    print('DECREASING')
else:
    print('NEITHER')
