N = input()

num = []
for i in range(len(N)):
    num.append(N[i])

num.sort(reverse = True)

result = ''
for i in num:
    result += i
print(result)



# list_a = list(map(int, str(input())))
# list_a.sort(reverse=True)
# for i in (list_a):
#     print(i,end='')
