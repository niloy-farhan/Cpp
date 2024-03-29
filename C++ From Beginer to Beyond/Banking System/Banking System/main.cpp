//
//  main.cpp
//  Banking System
//
//  Created by Niloy Farhan on 27/2/24.
//

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstdlib>

#define MIN_BALANCE 500

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::map;

class InsufficientFunds{};

class Account {
private:
    long accountNumber;
    string fName;
    string lName;
    float balance;
    static long int NextAccountNumber;
    
    friend ofstream & operator << (ofstream &ofs, Account &acc);
    friend ifstream & operator>>(ifstream &ifs, Account &acc);
    friend ostream & operator <<(ostream &os, Account &acc);
    
public:
    Account() {}
    Account(string _fname, string _lname, float _balance);
    
    long GetAccount()  { return accountNumber; }
    string GetFName()  { return fName; }
    string GettLName() { return lName; }
    float GetBalance() { return balance; }
    
    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
};

long Account::NextAccountNumber = 0;

class Bank {
private:
    map<long, Account> accounts;
    
public:
    Bank();
    Account openAccount(string _fname, string _lname, float _balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void ColoseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};

int main(int argc, const char * argv[]) {
    Bank b; 
    Account acc;
    
    int choice;
    string fname,lname;
    
    long accountNumber;
    float balance;
    float amount;
    
    cout<<"***Banking System***" <<endl;
    do {
        cout<<"\n\tSelect One Option Below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choise: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter initial Balance: ";
                cin>>balance;
                acc = b.openAccount(fname, lname, balance);
                cout<<endl <<"Congratulations Account is Created! " <<endl;
                cout<<acc;
                break;
            case 2:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                acc=b.BalanceEnquiry(accountNumber);
                cout<<endl<<"Your Account Details" <<endl;
                cout<<acc;
                break;
            case 3:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc=b.Deposit(accountNumber, amount);
                cout<<endl <<"Amount is Deposited" <<endl;
                cout<<acc;
                break;
            case 4:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc=b.Withdraw(accountNumber, amount);
                break;
            case 5:
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                b.ColoseAccount(accountNumber);
                cout<<endl<<"Account is Closed! " <<endl;
                cout<<acc;
                break;
            case 6:
                b.ShowAllAccounts();
                break;
            case 7:
                break;
            default:
                cout<<"\nEnter correct Choice!";
                exit(0);
        }
        
    } while(choice != 7);

    return 0;
}

Account::Account(string _fname, string _lname, float _balance)
{
    NextAccountNumber ++;
    accountNumber=NextAccountNumber;
    fName = _fname;
    lName = _lname;
    balance = _balance;
}

void Account::Withdraw(float amount) {
    if (balance - amount < MIN_BALANCE) {
        //throw InsufficientFunds;
    } else {
        balance -= amount;
    }
}

void Account::Deposit(float amount) {
    balance += amount;
}

void Account::setLastAccountNumber(long accountNumber){
    NextAccountNumber = accountNumber;
}

long Account::getLastAccountNumber() {return NextAccountNumber;}

ofstream & operator<<(ofstream &ofs, Account &acc) {
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.fName <<endl;;
    ofs<<acc.lName <<endl;
    ofs<<acc.balance <<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Account &acc) {
    ifs>>acc.NextAccountNumber;
    ifs>>acc.fName;
    ifs>>acc.lName;
    ifs>>acc.balance;
    return ifs;
}

ostream &operator <<(ostream &os, Account &acc) {
    os<<"First Name: " <<acc.GetFName();
    os<<"Last Name: " <<acc.GettLName();
    os<<"Account Number: " <<acc.GetAccount();
    os<<"Balance: " <<acc.GetBalance();
    return os;
}

Bank::Bank() {
    
    Account account;
    ifstream infile;
    
    infile.open("Bank.data");
    if(!infile){
        cout<<"Error Opening! File Not Found!" <<endl;
        return;
    }
    while(!infile.efo()) {
        
    }
}
