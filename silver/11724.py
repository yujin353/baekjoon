import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, m = map(int, input().split())

visited = [0] * (n+1)     #방문여부 확인
vertex = [0] * (n+1)   #인접 리스트

for i in range(m):
    u, v = map(int, input().split())
    if vertex[u] == 0:
        vertex[u] = [v]
    else:
        vertex[u].append(v)

    if vertex[v] == 0:
        vertex[v] = [u]
    else:
        vertex[v].append(u)

def search(u):
    if visited[u] == 1:
        return
    visited[u] = 1
    
    if vertex[u] == 0:
        return

    for i in range(len(vertex[u])):
        search(vertex[u][i])

cnt = 0
for i in range(1, n+1):
    if visited[i] == 0:
        search(i)
        cnt += 1
    
print(cnt)

