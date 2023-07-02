import sys
input = sys.stdin.readline

s, p = map(int, input().split())
dna = list(input())[:-1]
acgt = list(map(int, input().split()))

answer = 0
cnt = [0] * 4
for i in range(p):
    if dna[i] == 'A':
        cnt[0] += 1
    elif dna[i] == 'C':
        cnt[1] += 1
    elif dna[i] == 'G':
        cnt[2] += 1
    elif dna[i] == 'T':
        cnt[3] += 1
        
check = 0
for j in range(4):
    if acgt[j] <= cnt[j]:
        check += 1
if check == 4:
    answer += 1

for i in range(p, s):    
    if dna[i-p] == 'A':
        cnt[0] -= 1
    elif dna[i-p] == 'C':
        cnt[1] -= 1
    elif dna[i-p] == 'G':
        cnt[2] -= 1
    elif dna[i-p] == 'T':
        cnt[3] -= 1
    
    if dna[i] == 'A':
        cnt[0] += 1
    elif dna[i] == 'C':
        cnt[1] += 1
    elif dna[i] == 'G':
        cnt[2] += 1
    elif dna[i] == 'T':
        cnt[3] += 1

    check = 0
    for j in range(4):
        if acgt[j] <= cnt[j]:
            check += 1
    if check == 4:
        answer += 1

print(answer)
