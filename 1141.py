#접두사

N = int(input())
L = []
for i in range(N):
    word = input()
    L.append(word)

L.sort(key = len)
ans=0
for i in range(N):
    nw = L[i]
    ishead = False
    for j in range(i + 1,N):
        try:
            if L[j].index(nw) == 0:
                ishead = True
                break
        except:
            continue
    if not ishead:
        ans += 1
print(ans)