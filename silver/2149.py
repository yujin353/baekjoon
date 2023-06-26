import sys
input = sys.stdin.readline

key = input()[:-1]
n = len(key)
secret = input()[:-1]
tot_n = len(secret)
clm_n = int(tot_n / n)

key_index = []
for i in range(n):
    key_index.append([i, key[i]])
key_index.sort(key = lambda item: item[1])

cut_secret = []
for i in range(clm_n):
    tmp = secret[i::clm_n]
    c = []
    for j in range(n):
        c.append([key_index[j][0], tmp[j]])
    c.sort(key = lambda item: item[0])
    cut_secret.append(c)

answer = ''
for i in cut_secret:
    for c in i:
        answer += c[1]
print(answer)
