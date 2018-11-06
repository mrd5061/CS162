/* Author: Meghan Dougherty
Date: 7/6/2018
Description: Main implementation file to test the Queue class and QueueNode 
Struct. Contains a menu that allows the user to implement the Queue functions. 


*/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;


#include "Queue.hpp"


int main()
{
	//Variables for data validation.
	string input;
	int choice = 0;
	int menuChoice = 0;
	int value = 0;

	//Create Queue object.
	Queue myList;

	cout << "Welcome to my Queue!" << endl;
	
	//Repeat the menu as long as the user does not opt to quit. 
	while (menuChoice != 5)
	{	
		//Display choices. 
		cout << "Please choose from the following options:" << endl;
		cout << " 1. Add a value to the back of queue. " << endl;
		cout << " 2. Display the front value. " << endl;
		cout << " 3. Remove the front node. " << endl;
		cout << " 4. Display the queue’s content. " << endl;
		cout << " 5. Exit. " << endl;

		//get input
		getline(cin, input);

		//validate that input is between 1 and 5
		while (!cin || input.length() > 1 || (input[0] < 49 || input[0] > 53))
		{
			//print error message and reprompt
			cout << "Invalid Input. Please enter a number between 1 and 5." << endl;
			getline(cin, input);
		}

		//convert input to integer
		menuChoice = stoi(input);

		//menu switch statement
		switch (menuChoice)
		{
		case 1:

			//get input for new item
			cout << "Enter a positive integer to add to the list." << endl;
			getline(cin, input);

			//validate input. Must be an integer and not lead with a 0. 
			while (!cin || (input[0] < 48 || input[0] > 57) || (input.length() > 1 && input[0] == 48) || input.find_first_not_of("0123456789") != std::string::npos)
			{
				cout << "Invalid Input. Please Enter a positive integer." << endl;
						
				getline(cin, input);
			}

			//convert input to integer
			value = stoi(input);

			//create the node
			myList.addBack(value);
			break;

		case 2:
			//make sure the list is not empty.
			if (!(myList.isEmpty()))
				cout << myList.getFront() << endl;
			else
				cout << "List is empty!" << endl;
			break;
		case 3:
			//make sure the list is not empty.
			if (!(myList.isEmpty()))
				myList.removeFront();
			else
				cout << "List is empty!" << endl;
			break;
		case 4:
			//make sure the list is not empty.
			if (!(myList.isEmpty()))
				myList.printQueue();
			else
				cout << "List is empty!" << endl;
			break;

		case 5:
			cout << "GoodBye!" << endl;
			break;
		}

	}
	return 0;

}

