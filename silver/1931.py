import sys
input = sys.stdin.readline

n = int(input())
meeting = []
for i in range(n):
    meeting.append(list(map(int, input().split())))
meeting.sort(key=lambda x:x[0])
meeting.sort(key=lambda x:x[1])

cnt = 1
i = 0
j = 1
while j < n:
    if meeting[i][1] <= meeting[j][0]:
        i = j
        cnt += 1
    j += 1

print(cnt)
