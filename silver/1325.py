import sys
from collections import deque
input = sys.stdin.readline

def bfs(num):
    queue = deque()
    queue.append(num)
    visited[num] = True
    
    while queue:
        new = queue.popleft()
        for i in trust[new]:
            if not visited[i]:
                visited[i] = True
                queue.append(i)
                depth[i] += 1
    
n, m = map(int, input().split())

trust = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    trust[a].append(b)


depth = [0 for _ in range(n+1)]
for i in range(1, n+1):
    visited = [False for _ in range(n+1)]
    bfs(i)

for i in range(1,n+1):
    if depth[i] == max(depth):
        print(i, end = ' ')
