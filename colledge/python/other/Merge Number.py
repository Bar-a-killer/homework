from functools import cmp_to_key

def compare(x, y):
    if x + y > y + x:
        return -1
    elif x + y < y + x:
        return 1
    else:
        return 0
t = int(input())
for _ in range(t):
    n = input()
    a = input().split()
    a.sort(key=cmp_to_key(compare))
    for x in a:
        print(x,end = "")
    print()