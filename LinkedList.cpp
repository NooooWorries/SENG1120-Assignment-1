/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
 */

#include "LinkedList.h"
#include "Node.h"
using namespace std;

namespace czx_project
{
    // Constructors
    LinkedList::LinkedList()
    {
        head = NULL;    // Initialize head: link to null pointer
        tail = NULL;    // Initialize tail: link to null pointer
        current = NULL; // Initialize current: link to null pointer
        length = 0;     // Initialize the length of linked list, give a value of 0
    }
    
    LinkedList::LinkedList(value_type& data)
    {
        head = new Node(data);  // Create a new head
        tail = head;            // Let tail equals to head
        current = tail;         // Move current to head or tail
        length = 1;             // Set the length of linked list to 1
    }
    
    // Destructor
    LinkedList::~LinkedList()
    {
        // Set all pointer to null, release stack space
        while(head != NULL)    // When head pointer still exist
        {
            removeFromHead();  // Remove head
        }
        tail = NULL;           // Set tail to null
    }
    
    void LinkedList::addToHead(const value_type& data)
    {
        // add head Node for empty list (length has the value of 0)
        if (length == 0)
        {
            head = new Node (data); // Create new Node, and set as a head
            tail = head;            // Let tail equals to head
            current = tail;         // Let current indicate tail (or head)
            length = 1;             // Set the length of linked list to 1
        }
        else
        {
            Node* headInsert = new Node(data); // Create a new Node
            head -> setPrevious (headInsert);  // Set the previous link of old head to new head
            headInsert -> setNext (head);      // Set the next link of new head to old head
            head = headInsert;                 // Set the new head Node as a head
            length++;                          // Length of the linked list plus one
            headInsert = NULL;                 // Set headInsert to null, avoid memory leak
        }
    }
    
    void LinkedList::addToTail(const value_type& data)
    {
        // add tail Node for empty list (length has the value of 0)
        if (length == 0)
        {
            tail = new Node(data); // Create new Node, and set as a tail
            head = tail;           // Let head equals to tail
            current = head;        // Let current indicate head (or tail)
            length = 1;            // Set the length of linked list to 1
        }
        else
        {
            Node* tailInsert = new Node(data); // Create a new Node
            tail -> setNext(tailInsert);       // Set the next link of old tail to new tail
            tailInsert -> setPrevious (tail);  // Set the previous link of new tail to old tail
            tail = tailInsert;                 // Set the new tail Node as a tail
            length++;                          // Length of the linked list plus one
            tailInsert = NULL;                 // Set headInsert to null, avoid memory leak
        }
    }
    
    void LinkedList::addToCurrent(const value_type& data)
    {
        Node* currentInsert = new Node(data);         // Create a new Node
        currentInsert -> setNext(current->getNext()); // Set the next Node of new Node to the next Node of current Node
        current -> setNext (currentInsert);           // Set the next Node of current to new Node
        if (current == tail)                          // If current equals to tail
        {
            tail = current -> getNext();              // Set new Node as a tail Node
        }
        current = current -> getNext();               // Set current to the new Node
        currentInsert = NULL;                         // Set currentInsert to Null, avoid memory leak
    }
    
    void LinkedList::removeFromHead()
    {
        Node* tempHead;      // Assign the value of head to a temporary variable
		tempHead = head;
        head = tempHead->getNext(); // Set the new head Node as the next Node of old head Node
		if (head != NULL)
		{
			head -> setPrevious(NULL);
		}
		else
		{
			tail = NULL;
		}
        delete tempHead;            // Delete old head Node
        length --;                  // Length minus 1
        
    }
    
    void LinkedList::removeFromTail()
    {
        Node* tempTail;      // Assign the value of head to a temporary variable
		tempTail = tail;
        tail = tempTail->getPrevious(); // Set the new head Node as the next Node of old head Node
		if (tail != NULL)
		{
			tail -> setNext(NULL);
		}
		else
		{
			head = NULL;
		}
        delete tempTail;            // Delete old head Node
        length --;                  // Length minus 1
    }
    
    void LinkedList::removeCurrent()
    {
		Node* temp;                             // Create a temporary pointer
        temp = current->getPrevious();          // Assign the previous node of current to temp
        temp -> setNext(current -> getNext());  // Set the next node of temp as the next node of current
		current->getNext()->setPrevious (current->getPrevious());
        delete current;                         // Delete current node
        current = temp -> getNext();            // Set the temp pointer as current node
        length --;                              // Length minus 1
    }
    
    void LinkedList::cleanList()
    {
        while (head != NULL)   // While the head pointer is not null
        {
            removeFromHead();  // Remove the head pointer
        }
    }
    
    void LinkedList::forward()
    {
        current = current -> getNext();  // Set the next node of old current as new current
    }
    
    void LinkedList::back()
    {
        current = current ->getPrevious();  // Set the previous node of old current as new current
    }
    
    void LinkedList::moveToHead()
    {
        current = head;  // Set head as new current
    }
    
    void LinkedList::moveToTail()
    {
        current = tail;  // Set tail as new current
    }
    
    LinkedList::value_type LinkedList::getCurrent() const
    {
        return current->getData();  // Return the data of current node
    }
    
    size_t LinkedList::getSize() const
    {
        return length;  // Return the length of linked list
    }
    
    int LinkedList::search (const string data)
    {	
        int position = -1;
        // For loop, traverse nodes untill achieve the end of linked list or target matched
        for (current = head; current !=NULL; current = current->getNext())
        {		
            position++;  // Count position
            if (data == current->getData())  // If matched, return back the position
			{				
                return position;
			}	
        }
		//cout<<"hehew "<<endl;
        return -1;  // If data not found, return -1
    }
    
    void LinkedList::swap(const int index1, const int index2)
    {
        moveToHead();                          // Move to the head of linked linked list
        for (int i = 0; i < index1; i ++)      // For loop: Go to the node based on index number
            forward();
        Node* node1 = current;                 // Set the node that user indicated to node1
        moveToHead();                          // Move to the head of linked linked list
        for (int j = 0; j < index2; j ++)      // For loop: Go to the node based on index number
            forward();
        Node* node2 = current;                 // Set the node that user indicated to node2
        value_type* data1 = new value_type();  // Create a new value_type for data 1 in heap
        value_type* data2 = new value_type();  // Create a new value_type for data 2 in heap
        *data1 = node1->getData();             // Get the data stored from node1
        *data2 = node2->getData();             // Get the data stored from node2
        node1->setData(*data2);                // Swap the data
        node2->setData(*data1);                // Swap the data
        delete data1;                          // Delete data1, avoid memory leak
        delete data2;                          // Delete data2, avoid memory leak
    }
}