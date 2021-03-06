/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */
#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"
using namespace czx_project;
/**
 * This is an example program that shows how to seed a random number generator
 * using a number provided from the command line and then access those random numbers.
 *
 * It will use a number provided on the command line (e.g. test_random.exe 12321) if one exists
 * otherwise it will seed the random nmber using the current time in seconds
 *
 * @param argc the number of arguments provided to the main function (this includes the program name itself)
 * @param argv an array of strings containing each of the arguments
 *
 * @author Trent Houliston
 */
int main(int argc, char* argv[])
{
    // Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2)
    {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else
    {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }
	
	// Demo program
    DeckOfCards* cards = new DeckOfCards();  // Create a new cards object
    cout<< cards->value() << endl;		     // Print the value of cards
    cards->shuffle();					     // Shuffle (Yates algorithms)
    cout<< *cards <<endl;					 // Print the value of cards (cout operator overriding)
	// Get the position of 4-H, 10-S, Q-C and A-D
    cout<< cards->position("4-H") << " ";
    cout<< cards->position("10-S") << " ";
    cout<< cards->position("Q-C") << " ";
    cout<< cards->position("A-D") << endl;
    cout<< cards->length() << endl; 		 // Get the length of card set
    cards->remove("4-H");					 // Delete card 4-H
    cards->remove("10-S");					 // Delete card 10-S
	// Get the position of 4-H, 10-S, Q-C and A-D
    cout<< cards->position("4-H") << " ";
    cout<< cards->position("10-S") << " ";
    cout<< cards->position("Q-C") << " ";
    cout<< cards->position("A-D") << endl;
    cout<< cards->length() << endl;			// Get the length of card set
    delete cards;
    return 0;
}
