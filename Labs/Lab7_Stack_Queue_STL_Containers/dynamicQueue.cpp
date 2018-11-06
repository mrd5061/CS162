
#include<iostream>
#include <queue>
#include <stdlib.h>

#include "dynamicQueue.hpp"
using std::cout;
using std::cin;
using std::endl;

/* randNum: takes no arguments. Generates a random number between 1 and 1000 and returns it.

*/
int randNum()
{
	return rand() % 1000 + 1;

}
/* addNum: takes a pointer to an int queue object, an int N (the number to be added), and the chance of appending that number. 
generates a random number between 1 and 100. If that random number is less than the chance of appending, N is added to the end
of the queue object. 

*/
void addNum(queue<int>* ptr, int N, int appendChance)
{
	int check = rand() % 100 + 1;

	
	if (check <= appendChance)
	{
		//push the item onto the queue.
		ptr->push(N);
	}
	else
		return;
}
/* removeNum: takes a pointer to an int queue object, an int N (the number to be added), and the chance of removing a number from the queue.
generates a random number between 1 and 100. If that random number is less than the chance of removal, the front item of the queue is removed.
*/
int removeNum(queue<int>* ptr, int removeChance)
{
	int check = rand() % 100 + 1;

	//make sure the queue isn't empty.
	if (!ptr->empty())
	{
		if (check <= removeChance)
		{
			//pop out the front item.
			ptr->pop();
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
		return 0;
}

/* outputBuffer: takes a pointer to a queue object. Prints the buffer contents and the buffer length.

*/
void outputBuffer(queue<int>* ptr)
{
	//Create a copy of the pointed to queue so the original queue is not lost. 
	queue <int> print (*ptr);

	cout << "The buffer is: " << endl;

	//as long as the buffer is not empty.
	while (!print.empty())
	{
		//Print the front item
		cout << print.front() << " ";
		//pop out the fron item. Second item is now front item. 
		print.pop();
		
	}
	cout << endl;
	cout << "The size of the buffer is: " << ptr->size() << endl;
}

