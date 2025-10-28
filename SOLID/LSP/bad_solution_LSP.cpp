#include <bits/stdc++.h>
using namespace std;

// lsp means liskov substitution principle
// it states that objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program
// kahne ka mtlb ye hai ki agar class B is a subclass of class A, to hum class A ke objects ko class B ke objects se replace kar sakte hain bina program ke behavior ko badle

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};
class SavingsAccount : public Account
{
private:
    double balance;

public:
    SavingsAccount(double initialBalance = 0)
    {
        this->balance = initialBalance;
    }
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Depositing " << amount << " to Savings Account" << endl;
    }
    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds in Savings Account" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawing " << amount << " from Savings Account" << endl;
        }
    }
};
class FixedDepositAccount : public Account
{
private:
    double balance;

public:
    FixedDepositAccount(double initialBalance = 0)
    {
        this->balance = initialBalance;
    }
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Depositing " << amount << " to Fixed Deposit Account" << endl;
    }
    void withdraw(double amount) override
    {
        throw runtime_error("Withdrawals are not allowed from Fixed Deposit Account before maturity");
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount(double initialBalance = 0)
    {
        this->balance = initialBalance;
    }
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Depositing " << amount << " to Current Account" << endl;
    }
    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds in Current Account" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawing " << amount << " from Current Account" << endl;
        }
    }
};

class Client
{
private:
    vector<Account *> accounts;

public:
    void addAccount(Account *account)
    {
        accounts.push_back(account);
    }
    void performTransactions()
    {

        for (auto account : accounts)
        {
            account->deposit(1000);
            if (typeid(*account) == typeid(FixedDepositAccount))
            {
                cout << "Skipping withdrawal for Fixed Deposit Account" << endl;
                continue;
            }
            else
            {
                try
                {
                    account->withdraw(200);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
    }
};

int main()
{
    Client client;
    SavingsAccount sa(500);
    FixedDepositAccount fda(1000);
    CurrentAccount ca(2000);

    client.addAccount(&sa);
    client.addAccount(&fda);
    client.addAccount(&ca);

    client.performTransactions();

    return 0;
}

// bad solution of LSP because client class needs to know about the specific type of account to handle the withdrawal operation correctly. This violates the Liskov Substitution Principle as the FixedDepositAccount cannot be treated as a regular Account without special handling.