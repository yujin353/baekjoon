import sys

total = 0
dic = dict()
while 1:
    word = sys.stdin.readline().rstrip()
    if word == '':
        break
    total += 1   
    if word in dic:
        dic[word] += 1
    else:
        dic[word] = 1
sdic = dict(sorted(dic.items()))
for i in sdic:
    a = sdic[i]
    per = round(a / total * 100, 4)
    
    print(i, end = ' ')
    print(per)
