n = input()
lis = list(map(int, input().split()))

print(*lis)
for i in range(len(lis)-1, 0, -1):
    for j in range(0, i):
        if lis[j] > lis[j+1]:
            lis[j], lis[j+1] = lis[j+1], lis[j]
print(*lis)

