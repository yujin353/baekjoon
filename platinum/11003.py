import sys
from collections import deque
input = sys.stdin.readline

n, l = map(int, input().split())
a = list(map(int, input().split()))

deque = deque()
for i in range(n):
    while deque and deque[-1][0] > a[i]:
        deque.pop()
    deque.append((a[i], i))

    if deque[0][1] <= i - l:
        deque.popleft()

    print(deque[0][0], end = ' ')
