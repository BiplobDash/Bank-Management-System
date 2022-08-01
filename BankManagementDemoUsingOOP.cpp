#include<bits/stdc++.h>
using namespace std;


class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand()%1000000000;
        this->balance = 0;
        cout<<"Your Account no is "<<account_number<<endl;
    }

    int ShowBalance(string password)
    {
        if(this->password == password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }

    void AddMoney(string password, int amount)
    {
        if(amount < 0)
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(this->password == password)
        {
            this->balance += amount;
            cout<<"Add Money Successful"<<endl;
        }
        else
        {
            cout<<"Password Didn't Match"<<endl;
        }
    }

    void DepositMoney(string password, int amount)
    {
        if(amount < 0)
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(this->balance < amount)
        {
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        if(this->password == password)
        {
            this->balance -= amount;
            cout<<"Deposit Money Successful"<<endl;
        }
        else
        {
            cout<<"Password Didn't Match"<<endl;
        }
    }
    friend class MyCash;

};

class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance = 0;
    }
    void AddMoneyFromBank(BankAccount *MyAccount, string password, int amount)
    {
        if(amount < 0)
        {
            cout<<"Invalid Amount"<<endl;
            return;
        }
        if(MyAccount->balance < amount)
        {
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        if(MyAccount->password == password)
        {
            this->balance += amount;
            MyAccount->balance -= amount;
            cout<<"Add Money From Bank is Successful"<<endl;
        }
        else
        {
            cout<<"Password Didn't Match"<<endl;
        }
    }
    int ShowBalance()
    {
        return balance;
    }
};

BankAccount* CreateAccount()
{
    string account_holder, password, address;
    int age;
    cout<<"CREATE ACCOUNT"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *MyAccount = new BankAccount(account_holder, address, age, password);
    return MyAccount;
}
void AddMoney(BankAccount *MyAccount)
{
    string password;
    int amount;
    cout<<"ADD MONEY"<<endl;
    cin>>password>>amount;
    MyAccount->AddMoney(password, amount);
    cout<<"Your Bank Balance is "<<MyAccount->ShowBalance("abc")<<endl;
}
void DepositMoney(BankAccount *MyAccount)
{
    string password;
    int amount;
    cout<<"DEPOSIT MONEY"<<endl;
    cin>>password>>amount;
    MyAccount->DepositMoney(password, amount);
    cout<<"Your Bank Balance is "<<MyAccount->ShowBalance("abc")<<endl;
}

void AddMoneyFromBank(MyCash *myCash, BankAccount *MyAccount)
{
    string password;
    int amount;
    cout<<"ADD MONEY FROM BANK"<<endl;
    cin>>password>>amount;
    myCash->AddMoneyFromBank(MyAccount, password, amount);
    cout<<"Your Bank Balance is "<<MyAccount->ShowBalance("abc")<<endl;
    cout<<"MyCash Balance is "<<myCash->ShowBalance()<<endl;
}
int main()
{
    BankAccount *MyAccount = CreateAccount();
    MyCash *myCash = new MyCash();
    Flag:
        cout<<"Select Option: "<<endl;
        cout<<"1. Add Money to Bank"<<endl;
        cout<<"2. Deposit Money from Bank"<<endl;
        cout<<"3. Add Money to MyCash from Bank"<<endl;
        int option;
        cin>>option;
        if(option == 1)
        {
            AddMoney(MyAccount);
        }
        else if(option == 2)
        {
            DepositMoney(MyAccount);
        }
        else if(option == 3)
        {
            AddMoneyFromBank(myCash, MyAccount);
        }
        else
        {
            cout<<"Invalid Option"<<endl;
        }
        goto Flag;



//    while(true)
//    {
//        cout<<"Select Option: "<<endl;
//        cout<<"1. Add Money to Bank"<<endl;
//        cout<<"2. Deposit Money from Bank"<<endl;
//        cout<<"3. Add Money to MyCash from Bank"<<endl;
//        int option;
//        cin>>option;
//        if(option == 1)
//        {
//            AddMoney(MyAccount);
//        }
//        else if(option == 2)
//        {
//            DepositMoney(MyAccount);
//        }
//        else if(option == 3)
//        {
//            AddMoneyFromBank(myCash, MyAccount);
//        }
//        else
//        {
//            cout<<"Invalid Option"<<endl;
//        }
//    }
    return 0;
}
