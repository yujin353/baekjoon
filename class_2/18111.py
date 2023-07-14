import sys
input = sys.stdin.readline

n, m, b = map(int, input().split())

freq = dict()
for i in range(n):
    land = list(map(int, input().split()))
    for j in land:
        if j in freq:
            freq[j] += 1
        else:
            freq[j] = 1

freq = sorted(freq.items(), key = lambda x:x[1], reverse = True)

task = []
high = 256
while high >= 0:
    time = 0
    B = b
    for i in freq:
        if i[0] < high: # 쌓기
            time += 1 * (high - i[0]) * i[1]
            B -= (high - i[0]) * i[1]
        else: # 제거
            time += 2 * (i[0] - high) * i[1]
            B += (i[0] - high) * i[1]
            
    if B >= 0:
        task.append([time, high])
    high -= 1
    
task.sort(key = lambda x:x[0])
print(task[0][0], task[0][1])
