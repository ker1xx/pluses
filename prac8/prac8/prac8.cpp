#include <iostream>
#include <vector>
#include <ctype.h>
#include <Windows.h>
using namespace std;

class BankAccount {
private:
    int accountNumber; // номер аккаунта
    double balance; // баланс
    double interestRate; // ставка
public:
    // конструктор
    BankAccount(int acctNumber, double initialBalance) 
    {
        this->accountNumber = acctNumber;
        this->balance = initialBalance;
        this->interestRate = 0;
    }

    // функкиця депозита
    void deposit(double amount) {
        if (amount > 0) // проверка суммы
        { 
            this->balance += amount;
            cout << "Пополнение на " << amount << " успешно." << endl;
        }
        else {
            cout << "Введена неверная сумма." << endl;
        }
    }

    // функция вывода 
    void withdraw(double amount) 
    {
        if (amount > 0 && amount <= this->balance) // проверка суммы и баланса 
        { 
            this->balance -= amount;
            cout << "Вывод " << amount << " успешен." << endl;
        }
        else {
            cout << "Введена неверная сумма или не хватает баланса." << endl;
        }
    }

    // функция возвращения баланса (const - показывает что ничего не изменяется)
    double getBalance() const 
    {
        return this->balance;
    }

    // функция высчитывает сумму которая выплачивается по ставке
    double getInterest() const 
    {
        double interest = this->balance * this->interestRate * (1 / 12.0);
        return interest;
    }

    // функция установления ставки
    void setInterestRate(double newRate) 
    {
        this->interestRate = newRate;
    }

    // получение номера аккаунта потому что он приватный
    int getAccountNumber() const 
    {
        return this->accountNumber;
    }

    // дружественная функция трансфера
    friend void transfer(BankAccount& fromAcct, BankAccount& toAcct, double amount);
};
// описание дружественной функции
void transfer(BankAccount& fromAcct, BankAccount& toAcct, double amount)
{
    if (amount > 0 && amount <= fromAcct.balance) { // проверка хватает ли баланса для трансфера
        fromAcct.balance -= amount;
        toAcct.balance += amount;
        cout << "Перевод " << amount << " с аккаунта номер " << fromAcct.accountNumber << " на аккаунт номер " << toAcct.accountNumber << "состоялся." << endl;

    }
    else {
        cout << "Неверная сумма или недостаток баланса " << fromAcct.accountNumber << "." << endl;
    }
};

int main()
{
    int number;
    double balance;
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер аккаунта: " << endl;
    cin >> number;
    cout << "Введите балланс аккаунта: " << endl;
    cin >> balance;
    BankAccount acc1(number, balance);
    cout << "Введите номер аккаунта: " << endl;
    cin >> number;
    cout << "Введите балланс аккаунта: " << endl;
    cin >> balance;
    BankAccount acc2(number, balance);
    while (true)
    {
        int picker;
        cout << "Введите номер операции:\n1 - Внести средства\n2 - Снять средства\n3 - Получить баланс \n4 - Получить ставку\n5 - Назначить ставку\n6 - Перевести" << endl;
        cin >> picker;
        if (picker == 1) //внесение средств
        {
            int acnum, getting1, getting2; double amount;
            cout << "Введите номер аккаунта: " << endl;
            cin >> acnum;
            cout << "Введите сумму: " << endl;
            cin >> amount;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum)
                acc1.deposit(amount);
            else if (getting2 == acnum)
                acc2.deposit(amount);
            else
                cout << "Ошибка!" << endl;
        }
        else if (picker == 2) //снятие средств
        {
            int acnum, getting1, getting2; double amount;
            cout << "Введите номер аккаунта: " << endl;
            cin >> acnum;
            cout << "Введите сумму: " << endl;
            cin >> amount;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum)
                acc1.withdraw(amount);
            else if (getting2 == acnum)
                acc2.withdraw(amount);
            else
                cout << "Ошибка!" << endl;
        }
        else if (picker == 3) //получение баланса
        {
            int acnum, getting1, getting2; double gettingamount;
            cout << "Введите номер аккаунта: " << endl;
            cin >> acnum;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum)
                gettingamount = acc1.getBalance();
            else if (getting2 == acnum)
                gettingamount = acc2.getBalance();
            if (gettingamount != NULL)
                cout << "Ставка счёта " << acnum << ": " << gettingamount << endl;
            else
                cout << "Ошибка!" << endl;
        }
        else if (picker == 4) //получение ставки
        {
            int acnum, getting1, getting2; double rate, gettingrate;
            cout << "Введите номер аккаунта: " << endl;
            cin >> acnum;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum)
                gettingrate = acc1.getInterest();
            else if (getting2 == acnum)
                gettingrate = acc2.getInterest();
            if (gettingrate != NULL)
                cout << "Счет " << acnum << " получил за последний месяц: " << gettingrate << endl;
            else
                cout << "Ошибка!" << endl;
        }
        else if (picker == 5) //назначение ставки
        {
            int acnum, getting1, getting2; double rate;
            cout << "Введите номер аккаунта: " << endl;
            cin >> acnum;
            cout << "Введите ставку: " << endl;
            cin >> rate;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum)
                acc1.setInterestRate(rate);
            else if (getting2 == acnum)
                acc2.setInterestRate(rate);
            else
                cout << "Ошибка!" << endl;
        }
        else if (picker == 6) //трансфер
        {
            int acnum1, acnum2, getting1, getting2; double amount;
            cout << "Введите номер аккаунта, с которого хотите перевести: " << endl;
            cin >> acnum1;
            cout << "Введите номер аккаунта, на который хотите перевести: " << endl;
            cin >> acnum2;
            cout << "Введите сумму: " << endl;
            cin >> amount;
            getting1 = acc1.getAccountNumber();
            getting2 = acc2.getAccountNumber();
            if (getting1 == acnum1 && getting2 == acnum2)
            {
                transfer(acc1, acc2, amount);
            }
            else
                cout << "Ошибка!" << endl;
        }
        else
            cout << "Ошибка!" << endl;
    }
}