/*
 * *
 * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *This is the implementation file of the methods used in this program.
 * */
#include "gameboard.hh"
#include <iostream>
#include <random>
using namespace std;
GameBoard::GameBoard()
{
    board_ = vector<vector<Element_type>>(SIZE, vector<Element_type>(SIZE));
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            board_.at(i).at(j) = EMPTY;
        }
    }

}

void GameBoard::print() const
{

    // Printing upper border
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');


    // Printing title row
    std::cout << "|   | ";
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << i + 1 << " ";
    }
    std::cout << "|" << std::endl;


    // Printing line after the title row
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '-');



    // Printing the actual content of the gameboard
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < SIZE; ++j)
        {
            // TODO: Print the gameboard element (i, j)
            if (board_.at(i).at(j) == 2){
                cout << "  "; // because enum element EMPTY equals to 2
            }
            else{
                cout << board_.at(i).at(j) << " ";
            }

        }
        std::cout << "|" << std::endl;
    }



    // Printing lower border
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');
}

void GameBoard::print_line(unsigned int length, char fill_character) const
{
    for(unsigned int i = 0; i < length; ++i)
    {
        std::cout << fill_character;
    }
    std::cout << std::endl;
}

void GameBoard::fill_square(int& i, int& j, int& filled_num)
{
    if (filled_num == 0){
        board_.at(i).at(j) = ZERO;
    }
    else if (filled_num == 1){
        board_.at(i).at(j) = ONE;
    }
    else{
        board_.at(i).at(j) = EMPTY;
    }
}
void GameBoard::fill_random(unsigned int& seed)
{
    default_random_engine generate(seed);
    uniform_int_distribution<int> distr(0,DISTR_UPPER_BOUND);
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            int random_num = distr(generate);
            fill_square(i,j,random_num);

        }
    }
}
bool GameBoard::check_seed(unsigned int& seed)
{
    for (auto i : BAD_SEEDS){
        if (seed == i){
            return true;
        }
    }
    return false;
}
void GameBoard::fill_with_input(string& input)
{
    string::size_type _ = 1; //skip the first one
    for (int i=0;i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {
            int filled_num = input.at(_) - '0';
            fill_square(i,j,filled_num);
            _ ++;

        }
    }
}
bool GameBoard::is_empty(int& i, int& j)
{
    if(board_.at(i).at(j) == EMPTY){
        return true;
    }
    return false;
}
bool GameBoard::three_identical_nums(int & i, int& j,int& filled_num)
{//counter of the number of identical numbers in a column and row
    int col_count = 0;
    int row_count = 0;

    for (unsigned int _ = 0;_<SIZE;_++){
        if (board_.at(_).at(j)== filled_num){
            col_count ++;
        }
    }if (col_count==3){
        return false;
    }
    for (unsigned int _ = 0;_<SIZE;_++){
        if (board_.at(i).at(_)== filled_num){
            row_count ++;
        }
    }if (row_count==3){
        return false;
    }
    return true;
}
//Check if the square is in the last row or column
//that the next square will be out of the board.
bool check_out_of_board(int i, int j)
{
    return (i>= 0 and i<SIZE and j>=0 and j<SIZE);
}
bool GameBoard::two_identical_sequence(int & i,int& j, int& filled_num)
{
    for (int r = j;r <= j+2; r++)
    {
        int counter1 = 1;
        for (int l=r-2;l<=r;l++)
        {   if (l==j)
            {
                continue;
            }
            if (check_out_of_board(i,l) and board_.at(i).at(l)==filled_num)
            {
                counter1 ++;
            }
        }
        if (counter1 == 3)
        {
            return false;
        }


    }
    //Check if square (k,j) is the same as filled num at square(i,j)

    for (int c = i;c<=i+2;c++)
    {
        int counter2 = 1;
        for (int k=c-2;k<=c;k++)
        {
            if (k==i)
            {
                continue;
            }
            if (check_out_of_board(k,j) and board_.at(k).at(j)==filled_num)
            {
                counter2 ++;
            }
        }
        if (counter2 == 3)
        {
            return false;
        }


    }



    return true;
}
bool GameBoard::is_game_over()
{// Check if every square on the gameboard has been filled
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if (board_.at(i).at(j) == 2) //empty square
                return false;
        }
    }
    return true;
}
