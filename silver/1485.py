import sys
import math
input = sys.stdin.readline

def len(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]
    return math.sqrt(x ** 2 + y ** 2)

def check(p):
    leng = []
    for i in range(3):
        for j in range(i+1, 4):
            leng.append(len(p[i], p[j]))
    k = min(leng)
    l = max(leng)
    if leng.count(k) == 4:
        if leng.count(l) == 2:
            print(1)
            return
    print(0)
    return

n = int(input())
for i in range(n):
    point = []
    for i in range(4):
        p = list(map(int, input().split()))
        point.append(p)
    check(point)

#############################################

import sys
input = sys.stdin.readline

t= int(input())

for i in range(t):
    lst = []
    for j in range(4):
        x, y = map(int, input().split()) 
        lst.append([x, y])
    lst.sort()
    x1, y1 = lst[0][0], lst[0][1]
    x2, y2 = lst[1][0], lst[1][1]
    x3, y3 = lst[2][0], lst[2][1]
    x4, y4 = lst[3][0], lst[3][1]
    
    if (x1 - x2)**2 + (y1 - y2)**2 == (x1 - x3)**2 + (y1 - y3)**2 == (x2 - x4)**2 + (y2 - y4)**2 == (x3 - x4)**2 + (y3 - y4)**2 :
        if x1 == x2 and y1 == y2:
            print(0)
        elif (x1 - x4)**2 + (y1 - y4)**2 == (x2 - x3)**2 + (y2 - y3)**2 :   
            print(1)
        else:
            print(0)
    else:
        print(0)
