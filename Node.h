/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#ifndef CZX_Node
#define CZX_Node
#include <cstdlib>
#include <iostream>
using namespace std;
namespace czx_project
{
	class Node
	{
		public:
			typedef string value_type;  // Define the type if string as value_type

			/* Constructor
			 * Precondition:  None
			 * Postcondition: variables data, next and previous had been initialized
			 */
			Node(const value_type& initialData = value_type(), Node* initialNext = NULL, Node* initialPrevious = NULL);
			
			/*
			 * Destructor
			 */
			~Node();

			/*
			 * Mutator: Set data
			 * Precondition:  A valid value had been provided
			 * Postcondition: Data get a value
			 */
			void setData(const value_type& newData);

			/*
			 * Mutator: Set next
			 * Precondition:  A valid next Node had been provided
			 * Postcondition: next get a Node
			 */
			void setNext(Node* newNext);

		   /*
			* Mutator: Set previous
			* Precondition:  A valid previous Node had been provided
			* Postcondition: previous get a Node
			*/
			void setPrevious(Node* newPrevious);

		   /*
			* Accessors: Get data
			* Precondition:  Data has a valid value
			* Postcondition: Returned the value of variable "data"
			*/
			value_type getData() const;
			
			/*
			 * Mutator: Get previous Node
			 * Precondition:  Previous has a valid value (pointer)
			 * Postcondition: Return the value of pointer "previous"
			 */
			const Node* getPrevious () const;
			
			/*
			 * Mutator: Get previous Node (constant)
			 * Precondition:  Previous has a valid value (pointer)
			 * Postcondition: Return the value of pointer "previous"
			 */
			 Node* getNext();
			 
			 /*
			 * Mutator: Get next Node
			 * Precondition:  Next has a valid value (pointer)
			 * Postcondition: Return the value of pointer "next"
			 */
			const Node* getNext () const;
			
			/*
			 * Mutator: Get next Node (constant)
			 * Precondition:  Next has a valid value (pointer)
			 * Postcondition: Return the value of pointer "next"
			 */
			 Node* getPrevious();

		private:
			value_type data;   // Variable to store card information
			Node* next;        // Variable to store the address of next Node
			Node* previous;    // Variable to store the address of previous Node
	};
}

#endif