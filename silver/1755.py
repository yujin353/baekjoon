M, N = map(int, input().split())
if M > N:
    tmp = N
    N = M
    M = tmp

nums = []
for i in range(M, N + 1):
    nums.append(i)

dic = {}

for i in range(M, N + 1):
    eng = str(i)
    key_ = ''
    for e in eng:
        if e == '0':
            key_ += 'zero'
        elif e == '1':
            key_ += 'one'
        elif e == '2':
            key_ += 'two'
        elif e == '3':
            key_ += 'three'
        elif e == '4':
            key_ += 'four'
        elif e == '5':
            key_ += 'five'
        elif e == '6':
            key_ += 'six'
        elif e == '7':
            key_ += 'seven'
        elif e == '8':
            key_ += 'eight'
        elif e == '9':
            key_ += 'nine'
    dic[key_] = eng
    
result = sorted(dic.items(), key = lambda x : x[0])

count = 0
for key, value in result:
    count += 1
    if count == 10:
        print(value)
        count = 0
    else:
        print(value, end = ' ')
