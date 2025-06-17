#include<iostream>
#include<vector>
using namespace std;

class Account{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount:public Account{
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

class CurrentAccount:public Account{
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

class FixedAccount:public Account{
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

    void withdraw(double amount){
        throw logic_error("Withdrawl is not allowed in Fixed account");
    }
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransaction(){
        for(Account* acc:accounts){
            acc->deposit(1000);
            try{
                acc->withdraw(500);
            } catch(const logic_error& e){
                cout <<"Exception: "<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransaction();
    return 0;
}