/* Author: Meghan Dougherty
Date: 7/6/2018
Description: Function definition file for the Queue class. Contains functions to add nodes to a linked list
as well as retrive and remove items and print the list.


*/
#include <iostream>
using std::cout;
using std::endl;

#include "Queue.hpp"



/* Queue: Constructor. Initializes the head pointer to nullptr.
*/
Queue::Queue()
{
	head = nullptr;
}
/*~Queue: Destructor. Deallocates the memory used by the list
*/
Queue::~Queue()
{
	QueueNode* ptr = head;

	
	while (ptr != nullptr)
	{	
		//put current pointer into a temp pointer
		QueueNode* trash = ptr;
		//re-assign current pointer to next in line
		ptr = ptr->next;
		//delete item pointed to by temp pointer.
		delete trash; 
	}
}
/* isEmpty: No arguments. Checks if the queue is empty. If so, returns true; otherwise, return false.
*/
bool Queue::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}
/* addBack: takes a user-inputted integer as a parameter. creates a QueueNode with user-inputted integer,
and appends it to the back of the list.
*/
void Queue::addBack(int val)
{
	//If the list is empty, make the new item the first in the list. 
	if (head == nullptr)
		head = new QueueNode(val);
	else
	{
		QueueNode* ptr = head;

		//traverse the list until the end is found.
		while (ptr->next != nullptr)
			ptr = ptr->next;
		//When end is found, add a new item to the end. 
		ptr->next = new QueueNode(val, nullptr, ptr);
	}
}
/* getFront: no parameters. returns the value of the node at the front of the queue.
*/
int Queue::getFront()
{
	QueueNode* ptr = head;
	return ptr->val;
}
/* removeFront: no parameters. removes the front QueueNode of the queue and free the memory.
*/
void Queue::removeFront()

{
	QueueNode* ptr;

	//if the list is empty, terminate the function.
	if (head == nullptr)
		return;
	else
	{
		//set a temp pointer to the head. 
		ptr = head;
		//set the head pointer to the second item 
		head = head->next;
		//delete the first item. 
		delete ptr;
	}
}
/* printQueue: no parameters. traverses through the queue from head using next pointers, and prints 
the values of each QueueNode in the queue.
*/
void Queue::printQueue()
{
	QueueNode* ptr = head;

	while (ptr)
	{
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
}
