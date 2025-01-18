#include <iostream>

using namespace std;

long long cal_numerator(int lottery_ball){
    unsigned long long numerator = 1;
    for (int i = 1; i <= lottery_ball; ++i){
        numerator *= i;
    }
    //cout << numerator;
    return numerator;
}
long long cal_denominator(int lottery_ball,int drawn_ball){
    unsigned long long factor1 = 1;
    unsigned long long factor2 = 1;
    for (int i = 1; i <= lottery_ball - drawn_ball; ++i)
	{
        factor1  *= i;

    }
    for (int i = 1; i <= drawn_ball; ++i)
	{
        factor2  *= i;
    }
    unsigned long long denominator = factor1 * factor2;
    //cout << denominator;
    return denominator;
}


long long cal_comb(int lottery_ball, int drawn_ball){
    unsigned long long combination = cal_numerator(lottery_ball) / cal_denominator(lottery_ball,drawn_ball);

    return combination;
}

int main()
{
    int lottery_ball;
    int drawn_ball;
    cout << "Enter the total number of lottery balls: ";
    cin >> lottery_ball;
    cout << "Enter the number of drawn balls: ";
    cin >> drawn_ball;
    
    if (lottery_ball <= 0 || drawn_ball <= 0){
        cout<<"The number of balls must be a positive number.";
        return 0;
    }else if (drawn_ball > lottery_ball){
        cout << "The maximum number of drawn balls is the total amount of balls.";
        return 0;
    }

    cout << "The probability of guessing all " << drawn_ball <<" balls correctly is " << "1/" << cal_comb(lottery_ball,drawn_ball);
    return 0;
}
