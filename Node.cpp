/*
 * Name: Zixin Cheng
 * Course: SENG1120
 * Student number: 3218124
*/

#include "Node.h"
namespace czx_project
{
	Node::Node(const value_type& initialData, Node* initialNext, Node* initialPrevious)
	{
		data = initialData; // Set default data
		next = initialNext; // Set default next
		previous = initialPrevious; // Set default previous
	}
	
	Node::~Node()
	{
		next = NULL;
		previous = NULL;
	}
	
	void Node::setData(const value_type& newData)
	{
		data = newData; // Assign the new value of data
	}
	
	void Node::setNext(Node* newNext)
	{
		next = newNext;  // Assign the new value of next pointer
	}
	
	void Node::setPrevious(Node* newPrevious)
	{
		previous = newPrevious;  // Assign the new value of previous pointer
	}
	
	Node::value_type Node::getData() const
	{
		return data;  // Return the data
	}
	
	const Node* Node::getPrevious () const
	{
		return previous;  // Return the previous pointer in constant
	}
	
	Node* Node::getNext()
	{
		return next;  // Return the next pointer
	}
	
	const Node* Node::getNext () const
	{
		return next;  // Return the next pointer in constant
	}
	
	Node* Node::getPrevious()
	{
		return previous;  // Return the previous pointer
	}
}