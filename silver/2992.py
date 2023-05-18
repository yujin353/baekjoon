x = input()
x_len = len(x)
nums = []
bigger = []

if x_len == 1:
    print(0)
elif x_len == 2:
    num = int(x[1] + x[0])
    if num > int(x):
        print(num)
    else:
        print(0)
elif x_len == 3:
    for i in range(x_len):
        for j in range(x_len):
            if i == j:
                continue
            for k in range(x_len):
                if i == k or j == k:
                    continue
                nums.append(int(x[i]+x[j]+x[k]))
elif x_len == 4:
    for i in range(x_len):
        for j in range(x_len):
            if i == j:
                continue
            for k in range(x_len):
                if i == k or j == k:
                    continue
                for l in range(x_len):
                    if i == l or j == l or k == l:
                        continue
                    nums.append(int(x[i]+x[j]+x[k]+x[l]))
elif x_len == 5:
    for i in range(x_len):
        for j in range(x_len):
            if i == j:
                continue
            for k in range(x_len):
                if i == k or j == k:
                    continue
                for l in range(x_len):
                    if i == l or j == l or k == l:
                        continue
                    for m in range(x_len):
                        if i == m or j == m or k == m or l == m:
                            continue
                        nums.append(int(x[i]+x[j]+x[k]+x[l]+x[m]))
else:
    for i in range(x_len):
        for j in range(x_len):
            if i == j:
                continue
            for k in range(x_len):
                if i == k or j == k:
                    continue
                for l in range(x_len):
                    if i == l or j == l or k == l:
                        continue
                    for m in range(x_len):
                        if i == m or j == m or k == m or l == m:
                            continue
                        for n in range(x_len):
                            if i == n or j == n or k == n or l == n or m == n:
                                continue
                            nums.append(int(x[i]+x[j]+x[k]+x[l]+x[m]+x[n]))

if x_len > 2:
    for i in nums:
        if i > int(x):
            bigger.append(i)

    if len(bigger) == 0:
        print(0)
    else:
        print(min(bigger))
