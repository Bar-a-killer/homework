m,n,q = map(int, input().split())
mapp = {}
for i in range(0,m):
    t = list(map(int, input().split()))
    for j in range(0,n):
        mapp[t[j]] = [i,j]

for _ in range(q):
    t = int(input())
    if t in mapp:
        print(mapp[t][0]," ",mapp[t][1])
    else:
        print(-1)