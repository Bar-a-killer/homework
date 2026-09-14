lis = []
i = 1
while 1:
    try:
        tmp = int(input())
    except EOFError:
        break
    pos = 0
    while pos < len(lis) and lis[pos] < tmp:
        pos += 1
    lis.insert(pos, tmp)
    if i % 2:
        print(lis[i//2])
    else:
        print((lis[i//2]+lis[i//2-1])//2)
    i += 1




