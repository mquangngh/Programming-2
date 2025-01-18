/*
 * *
 * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *This is the header file for the class used in this program.
 * */
#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <vector>
#include <string>
using namespace std;


// Type of the elements in the gameboard.
enum Element_type {ZERO, ONE, EMPTY};


// Constants for the size of the gameboard.
const int NUMBER_OF_SYMBOLS = 3;
const int SIZE = 2 * NUMBER_OF_SYMBOLS;


// Constant for the upper bound of probability distribution.
// Zeros and ones have the same probability, say x, and the estimated
// probability of empties is 6x, whereupon their sum is 8x, and thus,
// the interval must have eigth points, as [0..7].
const int DISTR_UPPER_BOUND = 7;


// Width of the left-most column, needed in printing the gameboard.
const unsigned int LEFT_COLUMN_WIDTH = 5;


class GameBoard
{
public:

    // Constructor.
    GameBoard();


    // Prints the gameboard.
    void print() const;



    //Start game by randomly filling the gameboard with input seed value
    void fill_random(unsigned int& seed);

    bool check_seed(unsigned int& seed);    //check whether the seed is bad

    //Start game filling the gameboard with player's input.
    void fill_with_input(string& input);

    bool is_empty(int& i,  int&); //check whether a square
                                                  //is empty to be filled

    //Fill square (i,j) with filled_num
    void fill_square(int& i,int& j, int& filled_num);

    //Check if adding filled_num at square (i,j) satisfies these conditions:
    //At most three identical numbers in a row or column
    bool three_identical_nums(int& i, int& j, int& filled_num);

    //At most two identical numbers next to each other.
    bool two_identical_sequence(int& i, int& j, int& filled_num);

    bool is_game_over(); //check whether the game is over

private:

    // Prints a line with the given length and the given character.
    void print_line(unsigned int length, char fill_character) const;


    // Seed values, from [1..50], producing non-solvable gameboard.
    const std::vector<unsigned int> BAD_SEEDS = { 2, 8, 12, 13, 16, 20, 21, 23,
                                                  26, 29, 31, 32, 34, 41, 42,
                                                  43, 44, 46 };
    //The board is a vector whose elements are vectors.
    vector<vector<Element_type>> board_;
};



#endif // GAMEBOARD_HH
