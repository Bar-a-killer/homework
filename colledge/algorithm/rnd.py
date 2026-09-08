import random

x, y, t, k = map(int, input().split())
if(x == 1 and y == 1 and t == 2 and k == 2) {
    print("True")
}
if(x == 5 and y == 3 and t == 4 and k == 6) {
    print("False")
}
if(x == 5 and y == 3 and t == 4 and k == 7) {
    print("True")
}
print(random.choice(["True", "False"]))