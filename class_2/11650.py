import sys
input = sys.stdin.readline

n = int(input())
point = [[[] for _ in range(2)] for _ in range(n)]
for i in range(n):
    x, y = map(int, input().split())
    point[i][0] = x
    point[i][1] = y

point.sort(key=lambda x:x[1]) ## x[1]부터 정렬해야함
point.sort(key=lambda x:x[0])

for i in range(n):
    print(point[i][0], point[i][1])
