import sys
input = sys.stdin.readline

def search(li, i):
    global suc
    
    if i in li:
        return
    li.append(i)
    
    if len(li) >= 5:
        suc = 1
        return
    
    if vertex[i] == 0:
        return

    friend = []
    for v in vertex[i]:
        tmp = []
        for i in li:
            tmp.append(i)
        friend.append(tmp)
        
    k = 0
    for v in vertex[i]:
        if suc == 0: #이미 5 넘어서 성공했으면 더 검색 안하게 진행 중지시켜야 시간초과 나지 않음
            search(friend[k], v)
            k += 1


n, m = map(int, input().split())

vertex = [0] * n

for i in range(m):
    a, b = map(int, input().split())
    
    if vertex[a] == 0:
        vertex[a] = [b]
    else:
        vertex[a].append(b)

    if vertex[b] == 0:
        vertex[b] = [a]
    else:
        vertex[b].append(a)

suc = 0
for i in range(n):
    if suc == 0:
        search([], i)

if suc == 1:
    print(1)
else:
    print(0)



#################################################
import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
N, M = map(int, input().split())
arrive = False
A = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)


def DFS(now, depth):
    global arrive
    if depth == 5 or arrive == True:    # 깊이가 5가 되면 종료
        arrive = True
        return
    visited[now] = True
    for i in A[now]:
        if not visited[i]:
            DFS(i, depth + 1)   # 재귀 호출 마다 깊이 증가
    visited[now] = False


for _ in range(M):
    s, e = map(int, input().split())
    A[s].append(e)  # 양방향 에지이므로 양쪽에 에지를 더하기
    A[e].append(s)

for i in range(N):
    DFS(i, 1)
    if arrive:
        break
if arrive:
    print(1)
else:
    print(0)
