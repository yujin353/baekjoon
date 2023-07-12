import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(x):
    if rep[x] == x:
        return x

    rep[x] = find(rep[x])
    return rep[x]

n, m = map(int, input().split())
rep = [i for i in range(n+1)]

for i in range(m):
    calc, A, B = map(int, input().split())
    
    if A == B:
        if calc == 1:
            print("YES")
        continue
    
    if calc == 0:
        rep[find(A)] = find(B) # 대표 노드끼리 연결시켜줘야 함
        rep[A] = find(B)
        
    elif calc == 1:
        if find(A) == find(B):
            print("YES")
        else:
            print("NO")
