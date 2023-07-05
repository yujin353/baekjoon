import sys
import math
input = sys.stdin.readline

def check_prime(num):
    cnt = int(math.sqrt(num)) + 1
    for i in range(2, cnt):
        if num % i == 0:
            return 0
    return 1

def make_candi(origin, a):
    candi = str(origin) + str(a)

    if check_prime(int(candi)) == 0:
        return
    
    if len(candi) == n:
        print(candi)
        return

    for a in add:
        make_candi(candi, a)


n = int(input())

prime = [2, 3, 5, 7]
add = [1, 3, 7, 9]

for p in prime:
    make_candi('', p)
