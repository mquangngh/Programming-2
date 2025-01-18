#include "account.hh"
#include <iostream>
using namespace std;
Account::Account(const std::string& owner, bool has_credit):
    owner_(owner),balance_(0),credit_(has_credit),limit_(0)
{
    generate_iban();

}

void Account::print() const
{
    cout << owner_ <<" : " << iban_<<" : "<<balance_<<" euros"<<endl;
}

void Account::set_credit_limit(int money)
{
    if (credit_){
        limit_=money;


    }else {
        cout << "Cannot set credit limit: the account has no credit card" <<endl;
    }
}

void Account::save_money(int money)
{
    balance_+= money;
}

void Account::take_money(int money)
{
    if (credit_){
        if (money<=balance_+limit_){
            balance_-=money;
            cout <<money << " euros taken: new balance of " << iban_
                 <<" is " <<balance_ <<" euros"<<endl;
        }else {
            cout <<"Cannot take money: credit limit overflow"<<endl;
        }


    }else{
        if (money<=balance_){
            balance_-=money;
            cout <<money << " euros taken: new balance of " << iban_
                 <<" is " <<balance_ <<" euros"<<endl;
        }
        else {
            cout << "Cannot take money: balance underflow" <<endl;
        }
    }

}

void Account::transfer_to(Account& a, int money)
{   if (credit_){
        if (money<=balance_+limit_){
            balance_-=money;
            a.balance_ += money;
            cout <<money << " euros taken: new balance of " << iban_
                 <<" is " <<balance_ <<" euros"<<endl;
        }else{
            cout <<"Cannot take money: credit limit overflow" <<endl;
            cout <<"Transfer from " << iban_ <<" failed"<<endl;
        }


    }
    else {
        if (money<=balance_){
            balance_-=money;
            a.balance_ += money;
            cout <<money << " euros taken: new balance of " << iban_
                 <<" is " <<balance_ <<" euros"<<endl;
        }else {
            cout <<"Cannot take money: balance underflow" <<endl;
            cout <<"Transfer from " << iban_ <<" failed"<<endl;
        }
    }







}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);

}
