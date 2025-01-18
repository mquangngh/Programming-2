#include "cards.hh"

// TODO: Implement the methods here
using namespace std;
Cards::Cards(): top_(nullptr)
{

}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
    Card_data* new_card = new Card_data();
    new_card -> data = id;
    new_card -> next = top_;

    top_ = new_card;
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data* current = top_;
    int current_num = 1;
    while (current != nullptr)
    {
        s << current_num <<": "<<current -> data << endl;
        current = current -> next;
        ++ current_num;
    }

}

bool Cards::remove(int &id)
{
    if (top_ == nullptr)
    {
        return false;
    }
    id = top_ -> data;
    Card_data* removable = top_;
    top_ = top_ -> next;
    delete removable;

    return true;
}

bool Cards::bottom_to_top()
{   //No card in the deck
    if (top_ == nullptr)
    {
        return false;
    }

    //One card in the deck only
    if (top_ ->next == nullptr)
    {
        return false;
    }

    // Find the last card
    Card_data* movable = top_;
    while (movable -> next != nullptr)
    {
        movable = movable -> next;
    }
    // Find the card previous the last card
    Card_data* new_bottom = top_;
    while (new_bottom -> next != movable)
    {
        new_bottom = new_bottom -> next;
    }
    movable -> next = top_;
    top_ = movable;
    new_bottom -> next = nullptr;
    return true;
}

bool Cards::top_to_bottom()
{
    //No card in the deck
    if (top_ == nullptr)
    {
        return false;
    }

    //One card in the deck only
    if (top_ ->next == nullptr)
    {
        return false;
    }

    Card_data* movable = top_;

    Card_data* old_bottom = top_;
    while (old_bottom -> next != nullptr)
    {
        old_bottom = old_bottom -> next;
    }
    top_ = top_ -> next; // update new top card
    old_bottom -> next = movable;
    movable -> next = nullptr;
    return true;


}

// Prints the content of the data structure with ordinal numbers to the
// output stream given as a parameter starting from the last element.
void Cards::print_from_bottom_to_top(std::ostream &s)
{
    Card_data* card = top_; //Initialize a card that is reached  to the bottom card from the top

    recursive_print(card,s);


}

Cards::~Cards()
{
    Card_data* current = top_;
    Card_data* others = nullptr;

    while ( current != nullptr )
    {
        others = current -> next;
        delete current;
        current = others;
    }

}

int Cards::recursive_print(Card_data *top, std::ostream &s)
{   /*
    //if reaches the bottom card
    if (top -> next == nullptr)
    {
        return top -> data;

    }
    else{
        top = top ->next;
        return recursive_print(top, s);
    }*/
    if (top == nullptr) {
        return 1; // Base case: If the top is null, return 0
    }

    int printed_count = recursive_print(top->next, s); // Recursively call with the next card first

    // Once all the next cards are printed, print the current card
    s << printed_count << ": " << top->data << std::endl;

    return printed_count + 1; // Return the incremented count
}
