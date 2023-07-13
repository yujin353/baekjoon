import sys
input = sys.stdin.readline

while True:
    string = list(input()[:-1])
    if string[0] == ".":
        break

    balance = True
    stack = []
    for s in string:
        if s == '(':
            stack.append('(')
        elif s == ')':
            if stack:
                if stack.pop() != '(':
                    balance = False
                    break
            else:
                balance = False
                break
            
        elif s == '[':
            stack.append('[')
        elif s == ']':
            if stack:
                if stack.pop() != '[':
                    balance = False
                    break
            else:
                balance = False
                break

    if balance and stack == []:
        print("yes")
    else:
        print("no")
