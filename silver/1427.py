import sys
input = sys.stdin.readline

n = list(input()[:-1])

for i in range(len(n)):
    maxIndex = i
    for j in range(i+1, len(n)):
        if n[j] > n[maxIndex]:
            maxIndex = j

    if n[maxIndex] > n[i]:
        tmp = n[i]
        n[i] = n[maxIndex]
        n[maxIndex] = tmp

for i in n:
    print(i, end = '')
