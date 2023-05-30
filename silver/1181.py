import sys
imput = sys.stdin.readline

N = int(input())
word = []

for i in range(N):
    tmp = input()
    if tmp not in word:
        word.append(tmp)
word.sort()

dic = dict()
for w in word:
    dic[w] = len(w)
    
s_word = sorted(dic.items(), key = lambda item: len(item[0]))

for key, value in s_word:
    print(key)


# n=int(input())
# a=[]
# for i in range(n):
#     a.append(input())
    
# set_a = set(a)
# a=list(set_a)

# a.sort()
# a.sort(key = len)

# for i in a:
#     print(i)
