import sys
from collections import deque
input = sys.stdin.readline

sender = [0, 0, 1, 1, 2, 2]
receiver = [1, 2, 0, 2, 0, 1]
now = list(map(int, input().split()))
visited =[[False for _ in range(201)] for _ in range(201)]
answer = [False] * 201

def BFS():
    queue = deque()
    queue.append((0,0))
    visited[0][0] = True
    answer[now[2]] = True

    while queue:
        now_node = queue.popleft()
        a = now_node[0]
        b = now_node[1]
        c = now[2] - a - b

        for k in range(6):
            next = [a,b,c]
            next[receiver[k]] += next[sender[k]]
            next[sender[k]] = 0
            if next[receiver[k]] > now[receiver[k]]:
                next[sender[k]] = next[receiver[k]] - now[receiver[k]]
                next[receiver[k]] = now[receiver[k]]
            if not visited[next[0]][next[1]]:
                visited[next[0]][next[1]] = True
                queue.append((next[0], next[1]))
                if next[0] == 0:
                    answer[next[2]] = True

BFS()

for i in range(len(answer)):
    if answer[i]:
        print(i, end = ' ')
