/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#ifndef CZX_LINKEDLIST
#define CZX_LINKEDLIST

#include <cstdlib>
#include "Node.h"
using namespace std;
namespace czx_project
{
	class LinkedList
	{
		public:
        
			typedef string value_type;  // Define the type if string as value_type
			
			// Constructors
			LinkedList(); // Constructor which accept 0 argument			
			LinkedList(value_type& data); // Constructor which accept 1 argument
			
			// Descructors 
			~LinkedList();
			
			// Member function
			/*
			 * Member function: Add a new Node to head
			 * Precondition:    None
			 * Postcondition:   A new Node storing the supplied entry is created and linked in to be the new head of the linkedlist
			 */
			void addToHead(const value_type& data);
			
			/*
			 * Member function: Add a new Node to tail
			 * Precondition:    None
			 * Postcondition:   A new Node storing the supplied entry is created and linked in to be the new tail of the linkedlist
			 */
			void addToTail(const value_type& data);
			
			/*
			 * Member function: Add a new Node after current
			 * Precondition:    Current points to the Node just before the insertion position
			 * Postcondition:   A new Node is containing entry is inserted after the Node pointed to by current;
                                Current points to the new Node
			 */
			void addToCurrent(const value_type& data);
			
			/*
			 * Member function: Remove head Node
			 * Precondition:    The list is not empty
			 * Postcondition:   The first Node is removed and returned to the heap
             */         
			void removeFromHead();
			
			/*
			 * Member function: Remove tail Node
			 * Precondition:    The list is not empty
			 * Postcondition:   The last Node is removed and returned to the heap
             */    
			void removeFromTail();
			
			/*
			 * Member function: Remove current Node
			 * Precondition:    The list is not empty;
			                    Current Node has a valid pointer
			 * Postcondition:   The current Node is removed and returned to the heap
             */
			void removeCurrent();
			
            /*
             * Member function: Clean the entire linked list
             * Precondition:    None
             * Postcondition:   The list is empty and head pointer and tail pointer are both NULL
             */
            void cleanList();
        
			/*
			 * Member function: Current forward
			 * Precondition:    Current has a valid pointer
             * Postcondition:   Current move one Node forward
			 */
			void forward();
        
            /*
             * Member function: Current backward
             * Precondition:    Current has a valid pointer
             * Postcondition:   Current move one Node backward
             */
            void back();
        
            /*
             * Member function: Current move to head
             * Precondition:    Current has a valid pointer
             * Postcondition:   Current move to head pointer
             */
            void moveToHead();
        
            /*
             * Member function: Current move to tail
             * Precondition:    Current has a valid pointer
             * Postcondition:   Current move to tail pointer
             */
			void moveToTail();
        
            /*
             * Member function: Get current node
             * Precondition:    Current node has a valid pointer
             * Postcindition:   Current node returned back
             */
            value_type getCurrent() const;
        
            /*
             * Member function: Get the length of linked list
             * Precondition:    None
             * Postcondition:   Length of the linked list returned back
             */
            size_t getSize() const;
        
            /*
             * Member function: Search a particular node and return back the position;
             *                  If node not found, return -1
             * Precondition:    None
             * Postcondition:   The result had been returned
             */
            int search (const string data);
        
            /*
             * Member function: Swap data between two nodes
             * Precondition:    At least 2 valid node in the linked list;
             *                  The index of two nodes provided
             * Postcondition:   The data in the two nodes swapped;
             * Notice:          This function will not swap the next and previous pointers
             */
            void swap (const int index1, const int index2);
        
		private:
			Node* head;     // Pointer variable to indicate head pointer
			Node* tail;     // Pointer variable to indicate tail pointer
			Node* current;  // Pointer variable to indicate current pointer
			size_t length;	// Variable to store the length of the linked list
	};
}
#endif