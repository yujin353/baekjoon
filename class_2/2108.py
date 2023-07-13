import sys
input = sys.stdin.readline

n = int(input())
num = [0] * n
tot = 0
cnt = dict()
Min = 4000
Max = -4000

for i in range(n):
    num[i] = int(input())
    tot += num[i] # for avg
    
    if num[i] in cnt: # for mode
        cnt[num[i]] += 1
    else:
        cnt[num[i]] = 1

    if num[i] < Min: # for range
        Min = num[i]
    if num[i] > Max:
        Max = num[i]

# avg
print(round(tot/n))

# mode
num.sort()
print(num[n//2])

# median
cnt = dict(sorted(cnt.items(), key = lambda x: x[0]))
cnt = sorted(cnt.items(), key = lambda x: x[1], reverse = True)
if n == 1:
    print(num[0])
else:
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])

# range
print(Max-Min)
