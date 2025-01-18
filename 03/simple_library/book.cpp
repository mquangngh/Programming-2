#include "book.hh"
#include <iostream>
#include "date.hh"
using namespace std;

Book::Book(const std::string& author, const std::string& title, bool is_loaned):
    author_(author), title_(title),is_loaned_(is_loaned)
{
}
void Book::print() const
{
    cout <<author_<<" : "<<title_<<endl;
    if (is_loaned_){
        cout <<"- loaned: ";
        loaned_.print();
        cout <<"- to be returned: ";
        due_date_.print();
    }else {
        cout <<"- available"<<endl;

    }
}

void Book::loan(Date& day)
{

    if (is_loaned_){
        cout <<"Already loaned: cannot be loaned"<<endl;
    }
    else{
        is_loaned_=true;
        loaned_=day;
        due_date_=day;
        due_date_.advance(28);
    }
}

void Book::renew()
{
    if (is_loaned_){
        due_date_.advance(28);
    }else{
        cout<<"Not loaned: cannot be renewed"<<endl;
    }

}

void Book::give_back()
{
    if (is_loaned_)
    {
        is_loaned_=false;
    }else{
        cout<<"Not loaned: cannot be returned"<<endl;
    }
}


