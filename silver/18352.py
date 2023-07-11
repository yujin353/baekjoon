import sys
from collections import deque
input = sys.stdin.readline

def bfs(x):
    queue = deque()
    queue.append(x)

    while queue:
        new = queue.popleft()
        visited[new] = True
        for i in road[new]:
            if not visited[i]:
                visited[i] = True
                distance[i] = distance[new] + 1
                queue.append(i)
            


n, m, k, x = map(int, input().split())

visited = [False for _ in range(n+1)]
distance = [0 for _ in range(n+1)]
road = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    road[a].append(b)

bfs(x)

exist = False
for i in range(n+1):
    if distance[i] == k:
        print(i)
        exist = True

if not exist:
    print('-1')
