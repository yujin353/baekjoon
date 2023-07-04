import sys
input = sys.stdin.readline
def merge_sort(s, e):
    global cnt
    
    if e - s < 1: return
    
    m = int(s + (e - s) / 2)
    merge_sort(s, m)
    merge_sort(m + 1, e)
    
    for i in range(s, e + 1):
        tmp[i] = A[i]
        
    k = s
    i = s
    j = m + 1
    while i <= m and j <= e:
        if tmp[i] > tmp[j]:
            A[k] = tmp[j]
            cnt += (j-k)
            k += 1
            j += 1
        else:
            A[k] = tmp[i]
            k += 1
            i += 1
            
    while i <= m:
        A[k] = tmp[i]
        k += 1
        i += 1
        
    while j <= e:
        A[k] = tmp[j]
        k += 1
        j += 1
        

N = int(input())
A = list(map(int, input().split()))
A.insert(0,0)

tmp = [0] * int(N + 1)

cnt = 0
merge_sort(1, N)
print(cnt)
