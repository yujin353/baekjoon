import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    A, B = map(int, input().split())
    
    a = A
    b = B
    while a > 0 and b > 0:
        if a > b:
            a = a % b
        else:
            b = b % a
            
    if a == 0:
        lcm = b
    else:
        lcm = a

    print(A*B//lcm)
