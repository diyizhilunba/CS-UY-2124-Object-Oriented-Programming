/*
  rec03.cpp
  Yilun Ma
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Transaction1;
using namespace std;

// Task 1
// Define an Account struct *
struct Account {
    string name;
    int acct_num;
};

// Task 2
// Define an Account class (use a different name than in Task 1)*
class AccountClass{
    friend ostream& operator<<(ostream& os, const AccountClass& acct);

private:
    string name;
    int acct_num;

public:
    //Constructor:*
    AccountClass(const string& nam, int num);

    //Getter and Setters:* mind const
    string getName() const;
    int getAcctNum() const;


};
//*
ostream& operator<<(ostream& os, const AccountClass& acct);


// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Account1 {
    friend ostream& operator<<(ostream& os, const Account1& acct);
    friend void deposit_money(int acct_num, int money, vector<Account1> all_accounts);
    friend void withdraw_money(int acct_num, int money, vector<Account1> all_accounts);
public:
    void deposit(int num);
    void withdraw(int num);
    Account1(string n,int bal, int acct_num);
private:
    string name;
    int balance;
    int acct_num;
    vector<Transaction1> trans;

};

class Transaction1 {
    friend ostream& operator<<(ostream& os, const Transaction1& trans);

public:
    Transaction1(const string& t, int val);

private:
    string type;
    int value;
};

//functions:
//ostream& operator<<(ostream& os, const Transaction1& trans) ;
//ostream& operator<<(ostream os, const Account1& acct);

// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)
class AccountV2 {
    friend ostream& operator<<(ostream& os, const AccountV2 acct);
    friend void deposit_money(int acct_num, int money, vector<AccountV2> all_accounts);
    friend void withdraw_money(int acct_num, int money, vector<AccountV2> all_accounts);
public:
    class TransactionV2 {
        friend ostream& operator<<(ostream& os, const TransactionV2& trans);

    public:
        TransactionV2(const string& t, int val);

    private:
        string type;
        int value;
    };
    void deposit(int num);
    void withdraw(int num);
    AccountV2(string n,int bal, int acct_num);
private:
    string name;
    int balance;
    int acct_num;
    vector<Transaction1> trans;
};



// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)







int main() {

    //variables:
    ifstream ifs;
    string name;
    int acct;
    vector<Account> accounts;
    int val;
    vector<Account1> all_accounts;

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";


    ifs.open("../accounts.txt");
    if(!ifs) {
        cerr << "The file cannot be open" ;
    }
    while(ifs >> name >> acct) {
        Account act;
        act.name = name;
        act.acct_num = acct;
        accounts.push_back(act);
    }
    ifs.close();
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << accounts[it].name << "\t" << accounts[it].acct_num << endl;
    }


    //      1b*
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    accounts.clear();
    ifs.open("../accounts.txt");
    if(!ifs) {
        cerr << "The file cannot be open" ;
    }
    while(ifs >> name >> acct) {
        Account act{name,acct};
        accounts.push_back(act);
    }
    ifs.close();
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << accounts[it].name << "\t" << accounts[it].acct_num << endl;
    }

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";

    vector<AccountClass> acct_classes;
    ifs.open("../accounts.txt");
    if(!ifs) {
        cerr << "The file cannot be open" ;
    }
    while(ifs >> name >> acct) {
        AccountClass act(name,acct);
        acct_classes.push_back(act);
    }
    ifs.close();
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << acct_classes[it].getName() << "\t" << acct_classes[it].getAcctNum() << endl;
    }

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << acct_classes[it] << endl;
    }

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << acct_classes[it] << endl;
    }

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    acct_classes.clear();
    ifs.open("../accounts.txt");
    if(!ifs) {
        cerr << "The file cannot be open" ;
    }
    while(ifs >> name >> acct) {
        acct_classes.push_back(AccountClass(name,acct));
    }
    ifs.close();
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << acct_classes[it].getName() << "\t" << acct_classes[it].getAcctNum() << endl;
    }
    
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";
    acct_classes.clear();
    ifs.open("../accounts.txt");
    if(!ifs) {
        cerr << "The file cannot be open" ;
    }
    while(ifs >> name >> acct) {
        acct_classes.emplace_back(AccountClass(name,acct));
    }
    ifs.close();
    for(size_t it = 0; it < accounts.size(); it ++) {
        cout << acct_classes[it].getName() << "\t" << acct_classes[it].getAcctNum() << endl;
    }
    
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    string operation;

    ifs.open("../transactions.txt");
    if(!ifs) {
        cerr << "The file cannot be open";
    }
    while(ifs >> operation >> name >> val) {
        if(operation == "Account") {
            all_accounts.push_back(Account1(name,0,val));
        }
        else if(operation == "Deposit") {
            deposit_money(stoi(name),val,all_accounts);
        }
        else {
            withdraw_money(stoi(name),val,all_accounts);
        }
    }
    ifs.close();
    for(Account1& acct: all_accounts) {
        cout << acct;
    }


    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";


    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";

    
}

AccountClass::AccountClass(const string& nam, int num):name(nam),acct_num(num) {
}
string AccountClass::getName() const{
    return name;
}
int AccountClass::getAcctNum() const{
    return  acct_num;
}

ostream& operator<<(ostream& os, const AccountClass& acct) {
    //os << acct.getName() << "\t" << acct.getAcctNum();
    os << acct.name << "\t" << acct.acct_num;
    return os;
}

Transaction1::Transaction1(const string& t, int val):type(t),value(val) {

}



//Acount1
void Account1::deposit(int num) {
    balance += num;
    trans.emplace_back(Transaction1("Deposit",num));
}

void Account1::withdraw(int num) {
    if(balance < num) {
        cerr << "You don't have enough money";
    }
    else {
        balance -= num;
        trans.emplace_back(Transaction1("Withdraw",num));
    }
}



void deposit_money(int acct_num, int money, vector<Account1> all_accounts) {
    for(size_t it = 0; it < all_accounts.size(); it++) {
        if(all_accounts[it].acct_num == acct_num) {
            all_accounts[it].deposit(money);

            return;
        }
    }
    cout << "Cannot find the account number" << endl;
}

void withdraw_money(int acct_num, int money, vector<Account1> all_accounts) {
    for(size_t it = 0; it < all_accounts.size(); it++) {
        if(all_accounts[it].acct_num == acct_num) {
            all_accounts[it].withdraw(money);

            return;
        }
    }
    cout << "Cannot find the account number" << endl;
}

Account1::Account1(string n, int bal, int acct_num):name(n), balance(bal),acct_num(acct_num){

}
ostream& operator<<(ostream& os, const Transaction1& trans) {
    os << trans.type << "\t$"<<trans.value;
    return os;
}
ostream& operator<<(ostream& os, const Account1& acct) {
    os << "Account holder:" << acct.name << "\t" << "Account Balance" << acct.balance << endl;
    for(Transaction1 tran: acct.trans) {
        os << tran << endl;
    }
    return os;
}
ostream& operator<<(ostream& os, const AccountV2::TransactionV2& trans) {
    os << trans.type << "\t$"<<trans.value;
    return os;
}

