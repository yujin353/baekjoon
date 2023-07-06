import sys
from collections import deque
input = sys.stdin.readline

def BFS():
    queue = deque()
    queue.append([0,0])
    visited = [[0 for _ in range(n)] for _ in range(m)]
    visited[0][0] = 1
    
    while queue:
        now = queue.popleft()
        if now == [m, n]:
            break
        
        i = now[0]
        j = now[1]

        if i+1 < m and miro[i+1][j]:
            if visited[i+1][j] == 0:
                visited[i+1][j] = visited[i][j] + 1
                queue.append([i+1, j])
        if j+1 < n and miro[i][j+1]:
            if visited[i][j+1] == 0:
                visited[i][j+1] = visited[i][j] + 1
                queue.append([i, j+1])
        if i-1 >= 0 and miro[i-1][j]:
            if visited[i-1][j] == 0:
                visited[i-1][j] = visited[i][j] + 1
                queue.append([i-1, j])
        if j-1 >= 0 and miro[i][j-1]:
            if visited[i][j-1] == 0:
                visited[i][j-1] = visited[i][j] + 1
                queue.append([i, j-1])

    print(visited[m-1][n-1])
    return


m, n = map(int, input().split())

miro = []
for i in range(m):
    miro.append(list(map(int,input()[:-1])))

BFS()
