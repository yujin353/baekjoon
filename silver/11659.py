import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nums = list(map(int, input().split()))

prefix_sum = [0]
for i in nums:
    prefix_sum.append(prefix_sum[-1] + i)

for i in range(m):
    start, end = map(int, input().split())
    print(prefix_sum[end] - prefix_sum[start-1])
