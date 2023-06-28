import sys
input = sys.stdin.readline

s = input()[:-1]

sign = []
for i in s:
    if i == '+' or i == '-':
        sign.append(i)

n = len(sign) + 1
nums = [''] * n
cnt = 0
for i in s:
    if i == '+' or i == '-':
        cnt += 1
    else:
        nums[cnt] += i

answer = int(nums[0])
del nums[0]
i = 0
flag = 1
while i < n-1:
    if sign[i] == '-':
        flag = -1
        answer -= int(nums[i])
    else:
        answer += int(nums[i]) * flag
        
    i += 1

print(answer)
