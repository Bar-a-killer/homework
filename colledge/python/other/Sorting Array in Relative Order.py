t = int(input())
for _ in range(t):
    n = input()
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    m = {}
    l = []
    for i in b:
        m[i] = 0
    for i in a:
        if i in m:
            m[i] += 1
        else:
            l.append(i)
    l.sort()
    for idx,num in m.items():
        for __ in range(num):
            print(idx,end = " ")
    for i in l:
        print(i,end = " ")
