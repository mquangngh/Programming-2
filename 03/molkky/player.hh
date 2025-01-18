#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
    Player(const string& name);
    string get_name();
    int get_points();
    bool has_won();
    void add_points(int pts);

private:
    string name_;
    int point_;
};

#endif // PLAYER_H
