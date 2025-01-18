#include <iostream>
using namespace std;

int main()
{
    cout << "How many numbers would you like to have? ";

    // Write your code here
    int number = 0;
    cin >> number;
    for (int i=1; i<number+1;++i){
        if (i%3==0 and i%7 !=0 ){
            cout << "zip"<<endl;

        }else if (i%7 == 0 and i%3!= 0){
            cout<<"boing"<<endl;
        }else if (i%3 == 0 and i%7 == 0){
            cout<<"zip boing"<<endl;
        }else {

        cout << i <<endl;
        }
    }
    return 0;
}
