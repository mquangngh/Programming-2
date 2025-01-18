#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>
using namespace std;
class Account
{
public:
    // Constructor
    Account(const string& owner, bool has_credit = false);

    // More methods
    void print() const;
    void set_credit_limit(int money);
    void save_money(int money);
    void take_money(int money);
    void transfer_to(Account& a,int money);

private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban() ;

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
    string owner_;
    string iban_;
    int balance_;
    bool credit_;
    int limit_;
};

#endif // ACCOUNT_HH
