import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))

def quickSort(start, end, k):
    global a
    
    if start < end:
        pivot = partition(start, end)
        if pivot == k:
            return
        elif k < pivot:
            quickSort(start, pivot - 1, k)
        else:
            quickSort(pivot + 1, end, k)

def swap(i, j):
    global a
    
    tmp = a[i]
    a[i] = a[j]
    a[j] = tmp

def partition(start, end):
    global a

    if start + 1 == end:
        if a[start] > a[end]:
            swap(start, end)
        return end

    mid = (start + end) // 2
    swap(start, mid)
    pivot = a[start]
    
    i = start + 1
    j = end
    while i <= j:
        while j >= start and pivot < a[j]:
            j -= 1
        while i <= end and pivot > a[i]:
            i += 1

        if i < j:
            swap(i, j)
            i += 1
            j -= 1
        else:
            break

    a[start] = a[j]
    a[j] = pivot

    return j

quickSort(0, n-1, k-1)
print(a[k-1])
