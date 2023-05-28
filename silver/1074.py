import sys

def find(N, r, c, answer):
    if N == 1:
        answer += 2 * r + c
        print(answer)
        return
    if r >= 2 ** (N - 1):
        answer += 2 ** (2*N - 1)
        r -= 2 ** (N - 1)
    if c >= 2 ** (N - 1):
        answer += 2 ** (2*N - 2)
        c -= 2 ** (N - 1)
    find(N-1, r, c, answer)

N_, r_, c_ = map(int, sys.stdin.readline().split())

answer_ = 0
find(N_, r_, c_, answer_)
