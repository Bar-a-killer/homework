import sys
import random
 
seed = int(sys.argv[1]) if len(sys.argv) > 1 else 42
rng = random.Random(seed)
 
# 小範圍（m 夠小才能暴力枚舉）
n = rng.randint(1000, 10000)
m = rng.randint(1000, 10000)
print(n, m)
 
ops = ["AND", "OR", "XOR"]
for _ in range(n):
    op = rng.choice(ops)
    k  = rng.randint(0, 63)
    print(op, k)
 