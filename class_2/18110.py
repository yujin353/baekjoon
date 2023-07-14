import sys
input = sys.stdin.readline

n = int(input())
if n == 0:
    print(0)
else:
    dif = [0 for _ in range(n)]
    for i in range(n):
        dif[i] = int(input())
    dif.sort()

    fif = round(n*0.15+0.0000001)
    dif = dif[fif:n-fif]

    tot = 0
    for i in dif:
        tot += i
    print(round(tot/(n-2*fif)+0.0000001))
