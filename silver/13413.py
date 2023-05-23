T = int(input())

for i in range(T):
    N = int(input())
    initial = input()
    goal = input()

    switch = 0
    dif = []
    for j in range(N):
        if initial[j] != goal[j]:
            if initial[j] in dif:
                dif.append(initial[j])
                continue
            elif len(dif) != 0:
                del dif[0]
                switch += 1
                continue
            else:
                dif.append(initial[j])
                continue

    print(len(dif) + switch)
