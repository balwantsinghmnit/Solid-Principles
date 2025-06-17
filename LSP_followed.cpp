#include<iostream>
#include<vector>
using namespace std;

class DepositableAccount{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount:public DepositableAccount{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount:public WithdrawableAccount{
private:
    double balance;
public:
    SavingAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance += amount;
        cout <<"Deposited: " <<amount <<" in Savings Account. New Balance: "<< balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance -= amount;
            cout <<"Withdrawn: "<<amount<<" from Savings Account. New Balance: "<<balance<<endl;
        }
    }
};

class CurrentAccount:public WithdrawableAccount{
private:
    double balance;
public:
    CurrentAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance += amount;
        cout <<"Deposited: " <<amount <<" in Current Account. New Balance: "<< balance<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance -= amount;
            cout <<"Withdrawn: "<<amount<<" from Current Account. New Balance: "<<balance<<endl;
        }
    }

};

class FixedAccount:public DepositableAccount{
private:
    double balance;
public:
    FixedAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance += amount;
        cout <<"Deposited: " <<amount <<" in Fixed Account. New Balance: "<< balance<<endl;
    }
};

class BankClient {
private:
    vector<DepositableAccount*> deposit_accounts;
    vector<WithdrawableAccount*> withdraw_accounts;
public:
    BankClient(vector<DepositableAccount*> deposit_accounts, vector<WithdrawableAccount*> withdraw_accounts){
        this->deposit_accounts = deposit_accounts;
        this->withdraw_accounts = withdraw_accounts;
    }

    void processTransaction(){
        for(WithdrawableAccount* acc: withdraw_accounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(DepositableAccount* acc:deposit_accounts){
            acc->deposit(1000);
        }
    }
};

int main(){
    vector<DepositableAccount*> deposit_accounts;
    vector<WithdrawableAccount*> withdraw_accounts;

    withdraw_accounts.push_back(new SavingAccount());
    withdraw_accounts.push_back(new CurrentAccount());
    deposit_accounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(deposit_accounts, withdraw_accounts);
    client->processTransaction();
    return 0;
}