while True:
    N = int(input())
    if N == 0:
        break
    word = []
    for i in range(N):
        word.append(input())
    word.sort(key=str.lower)
    print(word[0])



# input을 아래와 같이 바꾸면 시간 감소
#  import sys
#  N = int(sys.stdin.readline())
#  word = [sys.stdin.readline().strip() for _ in range(N)]
