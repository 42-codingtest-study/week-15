import sys
input = sys.stdin.readline

n = int(input())
words = [(input()).rstrip() for _ in range(n)]


words.sort(key=len)
res = 0


for i in range(n):
    flag = False

    for j in range(i + 1, n):
        # 현재 단어가 접두사인지 확인
        if words[i] == words[j][0:len(words[i])]:
            flag = True
            break
    
    if not flag:
        res += 1

print(res)