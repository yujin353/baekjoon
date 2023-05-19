s = input().split()
if len(s[0]) > len(s[1]):
    A = s[1]
    B = s[0]
else:
    A = s[0]
    B = s[1]

dif = []
len_dif = len(B) - len(A)
for i in range(len_dif + 1):
    prefix = ''
    postfix = ''
    for j in range(i):
        prefix += '_'
    for k in range(len_dif - i):
        postfix += '_'

    dif.append(0)
    A_1 = prefix + A + postfix
    for m in range(i, len(B) - (len_dif - i)):
        if A_1[m] != B[m]:
            dif[i] += 1

print(min(dif))
