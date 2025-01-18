#ifndef BOOK_HH
#define BOOK_HH
using namespace std;
#include <iostream>
#include "date.hh"
class Book
{
public:
    Book(const std::string& author, const std::string& title, bool is_loaned=false);

    void print() const;
    void loan(Date& day);
    void renew();
    void give_back();

private:
    std::string author_;
    std::string title_;
    bool is_loaned_;
    Date loaned_;
    Date due_date_;

};

#endif // BOOK_HH
