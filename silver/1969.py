N, M = map(int, input().split())

s = []
for i in range(N):
    s.append(input())

nucleo = []
dist = 0
for i in range(M):
    tmp = []
    for j in range(N):
        tmp.append(s[j][i])
    tmp.sort()
    nu = max(tmp, key = tmp.count)
    nucleo.append(nu)
    dist += (N - tmp.count(nu))
        
for n in nucleo:
    print(n, end = '')
print()
print(dist)
