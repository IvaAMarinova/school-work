class BankAccount:
    def __init__(self, balance, first_name, last_name):
        self.__first_name = first_name
        self.__last_name = last_name
        self.__balance = balance
        self.__transaction = []
        self.__number_transaction = 0

    def __str__(self):
        name = self.__first_name + ' ' + self.__last_name
        return name

    def withdraw(self, wanted_sum):
        if self.__balance < wanted_sum:
            return -1
        else:
            self.__balance = self.__balance - wanted_sum
            return wanted_sum

    def deposite(self, given_sum):
        self.__balance = self.__balance + given_sum

    def __save_transaction(self, is_deposite, amount):
        self.__number_transaction += 1
        self.__transaction.append(self.__number_transaction)
        self.__transaction.append(is_deposite)
        self.__transaction.append(amount)

    def transaction(self, is_deposite, amount):
        if is_deposite == 1:
            self.deposite(amount)
        else:
            self.withdraw(amount)
            if(self.withdraw(amount) == -1):
                print('not enough money in bank account')
                return 
        self.__save_transaction(is_deposite, amount)
        print('Name:', self.__first_name, self.__last_name, '; Transaction: [number, type, amount]', self.transaction)

    def print_all_transactions(self):
        print(self.__first_name, self.transaction)

    def return_loan_payment(self, amount):
        self.p[2] = self.p[2] + amount
        print('current account state: ', self.p[2])
