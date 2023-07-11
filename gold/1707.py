import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(n):
    global Bipartite

    visited[n] = True
    for i in vertex[n]:
        if not visited[i]:
            # 인접 노드는 같은 집합이 아니므로 다른 집합으로 처리
            check[i] = (check[n]+1)%2
            dfs(i)
        elif check[i] == check[n]:
            # 이미 방문한 노드가 현재 내 노드와 같은 집합이면 이분 그래프 아님
            Bipartite = False

k = int(input())
for i in range(k):
    v, e = map(int, input().split())

    vertex = [[] for i in range(v+1)]
    visited = [False for _ in range(v+1)]
    check = [0 for i in range(v+1)]
    
    for i in range(e):
        a, b = map(int, input().split())
        vertex[a].append(b)
        vertex[b].append(a)

    Bipartite = True
    for i in range(1,v+1):
        if Bipartite == False:
            break
        dfs(i)


    if Bipartite:
        print("YES")
    else:
        print("NO")
