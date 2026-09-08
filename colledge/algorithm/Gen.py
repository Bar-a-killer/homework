import sys
import random
 
seed = int(sys.argv[1])
random.seed(seed)
 
n = random.randint(1, 6)
k = random.randint(1, 8)
arr = [random.randint(1, 30) for _ in range(n)]
 
print(n, k)
print(*arr)
 