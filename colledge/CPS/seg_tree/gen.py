# gen.py
import random
import sys

random.seed(int(sys.argv[1]))
n = random.randint(1, 5)
m = random.randint(1, 4)
print(n, m)
for _ in range(m):
    l = random.randint(1, n)
    r = random.randint(1, n)
    if l > r:
        l, r = r, l
    q = random.randint(0, 7)
    print(l, r, q)