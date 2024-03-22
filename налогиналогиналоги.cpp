#include <iostream>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

class BankAccount {
private: 
        int accountNUmber;
        double Balance;
        double interestRate;
        double money;
       
public:

    //конструктор
        BankAccount(int accountNUmber, double Balance, double InterestRate) {
            this->accountNUmber = accountNUmber;
            this->Balance = Balance;
            this->interestRate = 0.0;
            this->money = 0;
        }

        //функция вывода номера аккаунта
        int getAccountNumber() const {
            return accountNUmber;
        }

        //функция вывода баланса аккаунта
        double getBalance() const {
            return Balance;
        }

        //функция изменения процентной ставки
        void setInterestRate(double input) {
            interestRate = input;
        }

        //interest rate
        double getInterest() const {
            return Balance * interestRate * (1.0 / 12.0);
            //остаток?? я совершенно не понимаю бакновскую систему поэтому будет целый баланс *разводит руки*
        }
        //функция вывода денег со счета
        void withdraw(double withdrawal) {

            if (withdrawal <= Balance) {
                Balance -= withdrawal;
                cout << "написанная сумма была снята с счета." << endl;
            }
            else {
                cout << "Не хватает денег на счету." << endl;
            }
        }

        //функция внесения денег на счет
        void deposit(double dep) {
            Balance += dep;
            cout << "На счет было внесено" << dep << " р." << endl;
        }

       //функция перевода денег 
       friend bool transfer(BankAccount& sender, BankAccount& recipient, double money) {
            if (money <= sender.Balance) {
                sender.Balance -= money;
                recipient.Balance += money;
                cout << "На счет " << recipient.accountNUmber << " успешно переведено " << money << " рублей.\n" << endl;
                cout << "Ваш баланс теперь: " << sender.Balance << " рублей." << endl;
                return true;
            }
            else {
                cout << "Невомзможно сделать перевод. Или неправильные введены данные, или сумма, которую вы пытаетесь перевести, больше, чем ваш баланс." << endl;
                return false;
            }  
        }
};


int main()
{

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BankAccount acc1(2333333, 33500.0, 0);
    BankAccount acc2(4555555, 56000.0, 0);

    acc1.setInterestRate(0.75);
    acc2.setInterestRate(0.1);
   
    while (true) {
        cout << "Выберите действие, которые вы хотите совершить, введя его номер в терминал \n" << endl;
        cout << "1. Узнать номер аккаунта\n" << endl; //done
        cout << "2. Узнать баланс аккаунта\n" << endl; //done
        cout << "3. Перевести деньги Вашему другому аккаунту\n" << endl; //done
        cout << "4. Вывести деньги\n" << endl; //done
        cout << "5. Внести деньги\n" << endl; //done
        cout << "6. Узнать процентную ставку\n" << endl; //done
        cout << "7. Выход\n" << endl; //done
        int ActionChoice;
        cin >> ActionChoice;
        switch (ActionChoice) {
        case 1: {
            cout << "\nНомер Вашего аккаунта: " << acc1.getAccountNumber() << "\n" << endl;
            break;
        }
        case 2: {
            cout << "\nБаланс Вашего аккаунта: " << acc1.getBalance() << "\n" << endl;
            break;
        }

        case 3: {
            cout << "\nВведите сумму, которую вы хотите перевести: \n" << "\n" << endl;
            double transfermoney;
            cin >> transfermoney;
            transfer(acc1, acc2, transfermoney);
            break;
        }

        case 4: {

            cout << "\nВведите сумму, которые Вы хотите снять: \n" << endl;
            double withdrawmoney;
            cin >> withdrawmoney;
            acc1.withdraw(withdrawmoney);
            break;
        }

        case 5: {

            cout << "\nВведите сумму, которую Вы хотите внести: \n" << endl;
            double depositmoney;
            cin >> depositmoney;
            acc1.deposit(depositmoney);
            break;
        }
        case 6: {
            cout << "Процентная ставка Вашего аккаунта: " << acc1.getInterest() << "\n" << endl;
            break;
        }
        case 7: {
            exit(0);
        }

        default: {
            cout << "Введенные символы не соответсвуют доступным действиям. Попытайтесь еще раз \n" << endl;
            break;
        }
        }
    }
    




}

