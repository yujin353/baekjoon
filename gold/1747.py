import sys, math
input = sys.stdin.readline

def is_palin(n):
    string = str(n)
    end = len(string)
    
    i = 0
    while i < end//2:
        if string[i] != string[end-i-1]:
            return False
        i += 1
    return True
    

n = int(input())

Max = 1111112
prime = [0] * Max
for i in range(2, Max):
    prime[i] = i

for i in range(2, int(math.sqrt(Max))+1):
    if prime[i] == 0:
        continue
    for j in range(i+i, Max, i):
        prime[j] = 0

for i in range(n, Max):
    if prime[i] != 0 and is_palin(i):
        print(i)
        break
