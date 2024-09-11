/*
Author: Yilun Ma
Assignment: HW2
Date due: 06-13
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/
#include <iostream>
#include <vector>
#include <string>
#include "Money.h"

using namespace std;

//Classes:
class Check{
    //input and output
    friend istream& operator>>(istream& is, Check& chk);
    friend ostream& operator<<(ostream& os, const Check& chk);
public:
    //constructors:
    Check(int num, double amt, int sts);
    Check();

    //getter and setter:
    int getNumber() const;
    Money getMoney() const ;
    bool getStatus() const;
    void setNumber(int num);
    void setMoney(double amt);
    void setStatus(bool sts);



private:
    int checkNumber;
    Money checkAmount;
    bool isCashed;

};

//vector<Money> splitDeposits(string& deposit, int num);


int main() {
    //variables:
    vector<Check> checks;
    vector<Money> deposits;
    double old_balance,  new_balance, var = 0.00;
    Money cashed_money, total_deposit;
    int deposit_num, check_num;
    string deposit_str;

    //input:
    cout << "Enter old account balance:";
    cin >> old_balance;

    cout << "Enter the number of deposits:";
    cin >> deposit_num;


    cout << "Enter deposit amounts:";
    for(int ind = 0; ind < deposit_num; ++ind) {
        double one_time;
        cin >> one_time;
        deposits.push_back(Money(long(one_time),100 * (one_time - long(one_time))));
    }
    //getline(cin,deposit_str);
    //cout << deposit_str;

    //deposits = splitDeposits(deposit_str,deposit_num);
    cout << "Enter the number of checks:";

    cin >> check_num;


    cout << "Enter check details (number, amount, cashed status) one by one" << endl;
    for(int it = 0; it < check_num; it++) {
        Check chk;
        cin >> chk;
        //cout << chk;
        checks.push_back(chk);
    }


    cout << "Enter the new account balance reported by the bank:";
    cin >> new_balance;

    //output:
    cout << "Total value of cashed checks: ";
    for(Check& chk: checks) {
        //cout << chk << chk.getStatus();
        if(chk.getStatus() == true) {
            //cout << "j";
            //cout << chk.getMoney().getValue();
            cashed_money = add(cashed_money, chk.getMoney());
            //cout << cashed_money;
        }
    }
    cashed_money.output(cout) ;
    cout << endl;

    cout << "Total deposit amount: ";
    for(Money& mny: deposits) {
        //mny.output(cout);
        total_deposit = add(total_deposit,mny.getValue());
    }
    total_deposit.output(cout);
    cout << endl;

    cout << "Projected new balance: ";
    double projected;
    projected = add(old_balance,total_deposit).getValue() - cashed_money.getValue();
    if(projected > 0) {
        cout << "$" << projected;
    }
    else {
        cout << "-$" << -projected;
    }
    cout << endl;
    cout << "Variance from the bank's reported new balance: ";
    var = new_balance - projected;
    //formating
    if(var >= 0) {
        if(int(var * 100) % 100 == 0) {
            cout << "$" << var << ".00" << endl;
        }
        else if(int(var * 100) % 10 == 0) {
            cout << "$" << var << "0" << endl;
        }
        else {
            cout << "$" << var << endl;
        }

    }
    else {
        if(int(var * 100) % 100 == 0) {
            cout << "-$" << -var << ".00" << endl;
        }
        else if(int(var * 100) % 10 == 0) {
            cout << "-$" << -var << "0" << endl;
        }
        else {
            cout << "-$" << -var << endl;
        }
    }

    cout << "Cashed checks:" <<endl;
    for(const Check& chk: checks) {
        if(chk.getStatus() == 1) {
            cout << chk << endl;
        }
    }
    cout << "Uncashed checks:" << endl;
    for(const Check& chk: checks) {
        if(chk.getStatus() == 0) {
            cout << chk << endl;
        }
    }



    return 0;
}


istream &operator>>(istream &is, Check &chk) {
    int num;
    double amount;
    bool status;
    is >> num;
    chk.setNumber(num);
    is >> amount;
    chk.setMoney(amount);
    is >> status;
    chk.setStatus(status);
    return is;
}

ostream &operator<<(ostream &os, const Check &chk) {
    os << "Check Number: " << chk.checkNumber << ", Amount: ";
    chk.checkAmount.output(os);
    os << ", Cashed Status: ";
    if(chk.isCashed == 1) {
        os << "Cashed";
    }
    else {
        os << "Uncashed";
    }
    return os;
}
Check::Check(int num, double amt, int sts):checkNumber(num),checkAmount(long(amt),100 * (amt - long(amt))),isCashed(sts) {

}

Check::Check() {

}

Money Check::getMoney() const {
    return checkAmount;
}
int Check::getNumber() const{
    return checkNumber;
}
bool Check::getStatus() const{
    return isCashed;
}

void Check::setMoney(double amt) {
    long dol = long(amt);
    int cent = 100*(amt-long(amt));
    checkAmount = Money(dol,cent);
}
void Check::setNumber(int num) {
    checkNumber = num;
}
void Check::setStatus(bool sts) {
    isCashed = sts;

}





