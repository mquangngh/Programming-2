#include <iostream>

using namespace std;

int main()
{
    int temp;
    cout << "Enter a temperature: ";
    cin >> temp;
    // Write your code here
                   cout <<temp<< " degrees Celsius is "<<
               temp*1.8+32 <<" degrees Fahrenheit"<<endl;
    cout<< temp<<" degrees Fahrenheit is "<< (temp-32)/1.8<<" degrees Celsius"<<endl;
    return 0;
}
