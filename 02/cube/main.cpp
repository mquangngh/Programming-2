#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int number;
    cin>> number;
    if ((number*number*number)/(number*number)!=number)
    {
        cout <<"Error! The cube of "<<number<<" is not "<<number*number*number;
    }else
    {
        cout << "The cube of "<<number<<" is "<<number*number*number<<".";
    }
    return 0;
}
