import sys
input = sys.stdin.readline

n, m = map(int, input().split())
prefix_sum = [0]
for i in range(n):
    nums = list(map(int, input().split()))
    for j in nums:
        prefix_sum.append(prefix_sum[-1] + j)

for i in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    answer = 0
    for j in range(x1-1,x2):
        answer += prefix_sum[n*j+y2] - prefix_sum[n*j+(y1-1)]
    print(answer)
