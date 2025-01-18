#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";

    // Write your code here
    int number ;
    cin >> number;
    if (number <=0){
        cout<<"Only positive numbers accepted"<<endl;
    }else {
        for (int i=sqrt(number);i>=1;--i){
            if (number%i==0){
                cout<<number<<" = "<<i<<" * "<<number/i;
                break;
            }
        }
    }

    return 0;
}
