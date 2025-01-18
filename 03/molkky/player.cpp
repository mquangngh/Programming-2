#include "player.hh"
#include <string>
using namespace std;
Player::Player(const string& name):
    name_(name), point_(0)
{

}

string Player::get_name()
{
    return name_;
}

int Player::get_points()
{

    return point_;
}

bool Player::has_won()
{
    if (point_==50){

        return true;
    }else{
        return false;
    }
}

void Player::add_points(int pts)
{
    point_+= pts;
    if (point_>50){
        cout<<get_name()<<" gets penalty points!"<<endl;
        point_=25;
    }
}
