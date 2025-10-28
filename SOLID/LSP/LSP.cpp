#include <bits/stdc++.h>
using namespace std;

class NonWithdrawableAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public NonWithdrawableAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount
{
private:
    double balance = 0;

public:
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Saving Account deposit of " << amount << " is successful..." << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawal of " << amount << " is successful..." << endl;
        }
        else
        {
            cout << "Sorryyyyyy.... " << amount << " is not available in your account" << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount
{
private:
    double balance = 0;

public:
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Current Account deposit of " << amount << " is successful..." << endl;
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Current Account Withdrawal of " << amount << " is successful..." << endl;
        }
        else
        {
            cout << "Sorryyyyyy.... " << amount << " is not available in your account" << endl;
        }
    }
};

class FixedTermAccount : public NonWithdrawableAccount
{
private:
    double balance = 0;

public:
    void deposit(double amount) override
    {
        balance += amount;
        cout << "Fixed Term Account deposit of " << amount << " is successful..." << endl;
    }
};

class Client
{
private:
    vector<WithdrawableAccount *> withdrawableAccounts;
    vector<NonWithdrawableAccount *> nonWithdrawableAccounts;

public:
    Client(vector<WithdrawableAccount *> withdrawableAccounts, vector<NonWithdrawableAccount *> nonWithdrawableAccounts)
    {

        this->nonWithdrawableAccounts = nonWithdrawableAccounts;
        this->withdrawableAccounts = withdrawableAccounts;
    }

    void tranactionProcess()
    {

        for (WithdrawableAccount *acc : withdrawableAccounts)
        {
            acc->deposit(1111);
            acc->withdraw(599);
        }

        for (NonWithdrawableAccount *acc : nonWithdrawableAccounts)
        {
            acc->deposit(2990);
        }
    }
};

int main()
{

    vector<WithdrawableAccount *> withdrawableAccounts;

    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<NonWithdrawableAccount *> nonWithdrawableAccounts;

    nonWithdrawableAccounts.push_back(new FixedTermAccount());

    Client *client = new Client(withdrawableAccounts, nonWithdrawableAccounts);

    client->tranactionProcess();

    return 0;
}
