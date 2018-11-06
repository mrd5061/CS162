/* Author: Meghan Dougherty
   Date: 7/6/2018
   Description: Function declaration file for the Queue class. Contains functions to add nodes to a linked list
   as well as retrive and remove items and print the list. Also defines the QueueNode struct, it's variables 
   and it's constructor


*/

#ifndef QUEUE_H
#define QUEUE_H

//QueueNode Struct
struct QueueNode
{
	int val;
	QueueNode* next;
	QueueNode* prev;

	//Constructor. 
	QueueNode(int val1, QueueNode* next1 = nullptr, QueueNode* prev1 = nullptr)
	{
		val = val1;
		next = next1;
		prev = prev1;
	}

};

class Queue
{
private:
	QueueNode* head;
	
public:
	Queue();
	~Queue();
	bool isEmpty();
	void addBack(int);
	int getFront();
	void removeFront();
	void printQueue();
};

#endif