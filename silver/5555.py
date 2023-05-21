key = input()
N = int(input())

key_len = len(key)
count = 0
for i in range(N):
    s = input()
    s += s[:key_len]
    if key in s:
        count += 1

print(count)
