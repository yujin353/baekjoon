word = input()
w_len = len(word)

mixed = []
for i in range(1, w_len - 1):
    for j in range(i + 1, w_len):
        first = word[:i]
        second = word[i:j]
        third = word[j:]

        first = "".join(reversed(first))
        second = "".join(reversed(second))
        third = "".join(reversed(third))

        mixed.append(first+second+third)
        
mixed.sort()
print(mixed[0])
