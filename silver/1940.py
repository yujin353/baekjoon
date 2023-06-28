import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
nums = list(map(int, input().split()))
nums.sort(reverse = True)

cnt = 0
i = 0
j = n - 1
while i < j:
    if nums[i] + nums[j] == m:
        i += 1
        j -= 1
        cnt += 1
    elif nums[i] + nums[j] > m:
        i += 1
    else:
        j -= 1        
            
print(cnt)
