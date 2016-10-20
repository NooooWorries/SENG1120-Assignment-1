/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#include "LinkedList.h"
#include "DeckOfCards.h"

using namespace std;

namespace czx_project
{
    DeckOfCards::DeckOfCards()
    {
        list = new LinkedList();
        string cardNum [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};  // Card number
        string cardSuite [4] = {"S", "H", "C", "D"};  // Card suite
        string* card = new string();  // Combined card string
        int i = 0; int j = 0;
        for (i = 0; i < 4 ; i ++)
        {
            for (j = 0; j < 13; j ++)
            {
                *card = cardNum[j] + "-" + cardSuite[i];  // Create new card, format: number-suite
                list -> addToTail(*card);  // Add card into linked list
            }
        }
        delete card;  // Delete variable, avoid memory leak
    }
    
	DeckOfCards::~DeckOfCards()
	{
		list = NULL;
	}
    void DeckOfCards::shuffle()
    {
        int length = DeckOfCards::length();  // Get the length of linked list
        int random = 0;  // Initialize int variable - random
        
        // Yates algorithms to shuffle card
        for (int i = length - 1; i >= 1; i --)
        {
            random = rand() % i;   // Random number
            list->swap(random,i);  // Swap two cards
        }
    }
    
    size_t DeckOfCards::length() const
    {
        return list->getSize();  // Get the length from linked list
    }
    
    bool DeckOfCards::empty()
    {
        bool isEmpty = false;  // Initialize boolean variable
        if (list -> getSize() == 0)
        {
            isEmpty = true;    // If the size of linked is empty, set boolean to true
        }
        return isEmpty;        // Return the result
    }
    
    int DeckOfCards::position (const string card) const
    {
				
        return list->search(card);  // Search the card from linked list
    }
    
    bool DeckOfCards::remove(const string card)
    {
        // Remove a card based on card string
        bool isSuccess = true;              // Declare a new boolean and initialize it
        int position = list->search(card);  // Get the position of a sppecific card
		int size = static_cast<int>(length());  // Convert size_t to int
        if (position == -1)    				// If card not found
		{
            isSuccess = false;              // Fail to delete if the card that user provided is not exist
		}
		else if (position == 0)				// If card is located at the head of linked list, remove head
		{
			list->removeFromHead();    
		}
		else if (position >=1 && position <= size - 2)
		{			     
            list->moveToHead();                 // Move to the head of the linked list
            for (int i = 0; i < position; i ++)
			{
                list->forward();                // Move forward to the card that user want to delete				
			}		
            list->removeCurrent();              // Delete the card	
		}
		else if (position == size - 1)		// If card is located at the tail of the linked list, remove tail
		{		
			list ->removeFromTail();
		}	
        return isSuccess;                   // Return back the result
    }
    
    string DeckOfCards::value()
    {
        string card;                        // Declare a new string
        list->moveToHead();                 // Move to the head of the linked list
        //For each card
        for (size_t i = 0; i < DeckOfCards::length(); i ++)
        {
            card += list-> getCurrent();    // Get the value of current card
            card += " ";                    // Add to card string
            list -> forward();              // Move one position forward
        }
        return card;                        // Return back the result
    }
    
    // Overload the cout operator
    ostream& operator << (ostream& out, DeckOfCards& cards)
    {
        out << cards.value();  // Output the return string of function value()
        return out;            // Return back the result
    }
    
}