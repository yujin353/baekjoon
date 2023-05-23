N = int(input())

s = []
for i in range(N):
    word = input()
    sort = ''.join(sorted(word))
    s.append(sort)

print(len(set(s)))
