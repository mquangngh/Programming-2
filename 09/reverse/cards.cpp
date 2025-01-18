#include <iostream>
#include <memory>
#include "cards.hh"


using namespace std;


Cards::Cards(): top_( nullptr ) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;




   while( to_be_printed != nullptr ) {

      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}


bool Cards::remove(int &id)
{
    // No cards in the deck
    if (top_ == nullptr)
    {
        return false;
    }
    // Return data in id paramter
    id = top_ ->data;

    //Update the topmost card
    top_ = top_ ->next;
    return true;
}

void Cards::reverse()
{
    shared_ptr<Card_data> reversed_deck_top = nullptr;
    while ( top_ != nullptr)
    {
        // Update the topmost card (of the old deck)
        shared_ptr<Card_data> moved_card = top_;
        top_ = top_ ->next;

        //Adding to the deck for the first time
        if ( reversed_deck_top == nullptr )
        {
            moved_card ->next = nullptr;
            reversed_deck_top = moved_card;
        }
        else
        {
            moved_card ->next = reversed_deck_top;
            reversed_deck_top = moved_card;
        }
    }
    // Update top to match the top of the new deck
    top_ = reversed_deck_top;
}

// Tip for writing code more efficiently:
// Do not write the stubs of the methods remove and reverse by yourself here,
// but open the file cards.hh and click the declaration of the method
// by the right mouse button and select
// Refactor > Add definition in cards.cpp
