import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())

cirque = deque()
for i in range(1, n+1):
    cirque.append(i)

print('<', end = '')
while cirque:
    if len(cirque) == 1:
        print(cirque.popleft(), end = '')
        break
    
    cirque.rotate(1-k)
    print(cirque.popleft(), end =', ')
print('>')
