import random
import sys

t = 5
print(t)
for _ in range(t):
    n = random.randint(2, 8)
    p = list(range(1, n+1))
    random.shuffle(p)
    print(n)
    print(*p)