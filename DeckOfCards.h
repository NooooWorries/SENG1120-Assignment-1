/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#ifndef CZX_DeckOfCards
#define CZX_DeckOfCards
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;
namespace czx_project
{
    class DeckOfCards
    {
        public:
            // Constructor
            DeckOfCards();
			
			// Destructor
			~DeckOfCards();
        
            // Member functions
            /*
             * Member function: Use Yates algorithm to randomizes the sequence of cards
             * Precondition:    Linked list is exist and cards are stored in the linked list
             * Postcondition:   Cards had been shuffled randomly
             */
            void shuffle();
        
            /*
             * Member functio: Return the length of cards linked list
             * Precondition:   None
             * Postcondition:  Return back the length of cards linked list
             */
            size_t length() const;
        
            /*
             * Member function: Whether there are any cards in DeckOfCards or not
             * Precondition:    None
             * Postcondition:   Returned whether there are any cards in DeckOfCards or not
             */
            bool empty();
        
            /*
             * Member function: The position in the list with the first occurrence of the input parameter,
             * Precondition:    None
             * Postcondition:   Returns the position in the list with the first occurrence of the input parameter;
             *                  -1 if the card is not in the deck.
             */
            int position(const string card) const;
        
            /*
             * Member function: Get the sequence of cards in DeckOfCards
             * Precondition:    Cards are exist in the linked list
             * Postcondition:   The sequence of cards stored in DeckOfCards returned
             */
            string value();
        
            /*
             * Member function: Removes the corresponding card in DeckOfCards
             * Precondition:    None
             * Postcondition:   The corresponding card had been removed from the linked list
             */
            bool remove(const string card);
        
        private:
            LinkedList* list;  // Variable for linked list
    };
    ostream& operator << (ostream& out, DeckOfCards& cards); // Overriding cout operator
}

#endif
