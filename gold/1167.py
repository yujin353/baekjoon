import sys
from collections import deque
input = sys.stdin.readline

v = None
cv = None

def BFS(n):
    visited = [False] * (v+1)
    visited[n] = True
    diameter = [0] * (v+1)
    
    queue = deque()
    queue.append(n)
    while queue:
        now = queue.popleft()
        
        for i in cv[now]:
            if visited[i[0]] == False:
                visited[i[0]] = True
                diameter[i[0]] = diameter[now] + i[1]
                queue.append(i[0])
    
    return diameter

def main():
    global v, cv
    
    v = int(input())
    cv = [[] for _ in range(v+1)]
    for i in range(v):
        nums = list(map(int, input().split()))
        n = nums[0]
        for j in range(1,len(nums)-1,2):
            cv[n].append([nums[j], nums[j+1]])

    print(max(BFS(BFS(1).index(max(BFS(1))))))

if __name__ == '__main__':
    main()
