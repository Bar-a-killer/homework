a = int(input())
for _ in range(a):

    b = int(input())

    c = list(map(int, input().split()))
    m = {}

    for word in c:
        if word in m:
            m[word] += 1
        else:
            m[word] = 1

    d = max(m.values())
    e = len(m)

    ans = min(d,e)
    if b <= 1:
        ans = 0
    elif d == e:
        ans -= 1
    print(ans)
    