import sys
from collections import deque
input = sys.stdin.readline

def DFS(v):
    visited[v] = 1
    print(v, end = ' ')

    for i in edge[v]:
        if visited[i] == 0:
            DFS(i)
    

def BFS(v):
    queue = deque()
    queue.append(v)
    visited[v] = 1
    while queue:
        now = queue.popleft()
        print(now, end = ' ')

        for i in edge[now]:
            if visited[i] == 0:
                visited[i] = 1
                queue.append(i)
    

n, m, v = map(int, input().split())
edge = [[] for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

for i in range(1, n+1):
    edge[i].sort()

visited = [0] * (n+1)
DFS(v)
print()
visited = [0] * (n+1)
BFS(v)
