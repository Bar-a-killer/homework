n = input()

a = map(int,input().split())
b = map(int,input().split())
ans = 0
a = set(a)
b = set(b)
anslis = []
for i in a:
    if i in b:
        anslis.append(i)
        ans += 1

print(ans)
anslis.sort()
if ans > 0:
    print(*anslis)