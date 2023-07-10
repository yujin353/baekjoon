import sys
input = sys.stdin.readline

n = int(input())
adj = [[] for _ in range(n)]
visited = [False] * n
d = [0] * n
lcm = 1


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def dfs(n):
    visited[n] = True

    for i in adj[n]:
        new = i[0]
        if visited[new] == False:
            d[new] = d[n] * i[2] // i[1]
            dfs(new)
    


for i in range(n-1):
    a,b,p,q = map(int, input().split())
    adj[a].append([b, p, q])
    adj[b].append([a, q, p])
    
    lcm *= (p * q // gcd(p, q))

d[0] = lcm
dfs(0)
mgcd = d[0]

for i in range(1,n):
    mgcd = gcd(mgcd, d[i])

for i in range(n):
    print(int(d[i] // mgcd), end = ' ')
