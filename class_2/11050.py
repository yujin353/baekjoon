import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def fact(n):
    if n == 0 or n == 1: ##k가 0인 경우 때문
        return 1

    return n * fact(n-1)

n, k = map(int, input().split())
print(fact(n) // (fact(k) * fact(n-k)))
