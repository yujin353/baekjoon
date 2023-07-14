import sys
input = sys.stdin.readline

def binary_search(s, e):
    global candi
    
    if s >= e:
        return

    mid = (s+e) // 2
    N = 0
    for i in cm:
        N += i // mid

    if N >= n:
        binary_search(mid+1,e)
        candi.append(mid)
    else:
        binary_search(s,mid)
    

k, n = map(int, input().split())
cm = [0] * k
tot = 0
for i in range(k):
    cm[i] = int(input())
    tot += cm[i]

cm.sort()
avg = tot // n

candi = []
binary_search(1, 2*avg)
if n == 1:
    print(cm[0])
else:
    print(max(candi))
