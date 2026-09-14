n = input()
n = int(n)
if n > 1:
    for i in range(2*n):
        t = abs(n-i)
        for j in range(2*n):
            if abs(n - 1 - i) + abs(n - 1 - j) == n - 1:
                print('*', end='')
            else:
                print(' ', end='')
        print()
else:
    print("Invalid input")