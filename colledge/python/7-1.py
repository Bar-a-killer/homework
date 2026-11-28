class Account:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        self.balance = self.balance + amount

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds")
        else:
            self.balance = self.balance - amount


accounts = {}

while True:
    data = input().split()
    cmd = data[0]

    if cmd == "stop":
        break

    name = data[1]

    if cmd == "create":
        accounts[name] = Account(name, int(data[2]))
    elif name not in accounts:
        print("Account not found")
    elif cmd == "deposit":
        accounts[name].deposit(int(data[2]))
    elif cmd == "withdraw":
        accounts[name].withdraw(int(data[2]))
    elif cmd == "balance":
        print(accounts[name].balance)
