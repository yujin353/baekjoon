import sys
import math
input = sys.stdin.readline

def dif(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]

    return math.sqrt(x ** 2 + y ** 2)

T = int(input())
for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    
    if (x1 == x2) and (y1 == y2) and (r1 == r2):
        print(-1)
    else:
        distance = dif([x1,y1], [x2,y2])
        if distance >= max(r1, r2):
            if distance == r1 + r2:
                print(1)
            elif distance > r1 + r2:
                print(0)
            else:
                print(2)
        else:
            if distance == abs(r1 - r2):
                print(1)
            elif distance < abs(r1 - r2):
                print(0)
            else:
                print(2)
