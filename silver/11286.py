import sys
from heapq import heappush, heappop
input = sys.stdin.readline

n = int(input())

heap = []
for i in range(n):
    num = int(input())
    if num != 0:
        heappush(heap, (abs(num), num))
    else:
        if heap == []:
            print(0)
        else:
            tmp = heappop(heap)
            print(tmp[1])
