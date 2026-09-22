n = input()
n = int(n)
while True:
    train = list(map(int, input().split()))
    if train[0] == 0:
        break
    stack = []
    ptr = 0
    for nxt in range(1,n+1):
        if nxt == train[ptr]:
            ptr += 1
            continue
        while stack and train[ptr] == stack[-1]:
            ptr += 1
            stack.pop()
        stack.append(nxt)
    while stack and train[ptr] == stack[-1]:
        ptr += 1
        stack.pop()

    if stack:
        print("NO")
    else:
        print("YES")