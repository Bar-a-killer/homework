a,b = input().split()
b = int(b)
c = list(map(int, input().split()))

m = {}
d = 0
for idx,word in enumerate(c):
    m[word] = idx
e = []
for i in range(b):
    a = int(input())
    if a in m:
        e.append(m[a])
    else:
        e.append(-1)
for i in e:
    print(i)
    