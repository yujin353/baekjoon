import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a.sort()

cnt = 0
for i in range(n):
    start = 0
    end = n-1
    while start < end:
        if a[start] + a[end] == a[i]:
            if start != i and end != i:
                cnt += 1
                break
            elif start == i:
                start += 1
            elif end == i:
                end -= 1
        elif a[start] + a[end] < a[i]:
            start += 1
        else:
            end -= 1
print(cnt)
