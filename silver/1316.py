N = int(input())

answer = 0
for i in range(N):
    count = 0
    s = input()
    for j in s:
        if j in s[s.index(j) + s.count(j):]:
            count += 1
    if count == 0:
        answer += 1

print(answer)        
