import sys
input = sys.stdin.readline

n = int(input())
s = []
for i in range(n):
    s.append(int(input()))

stack = []
i = 1
calc = []
flag = 1
for j in range(n):
    if s[j] >= i:
        while s[j] >= i:
            stack.append(i)
            calc.append('+')
            i += 1
        stack.pop()
        calc.append('-')
    else:
        tmp = stack.pop()
        if tmp > s[j]:
            print("NO")
            flag = 0
            break
        else:
            calc.append('-')

if flag == 1:
    for c in calc:
        print(c)
