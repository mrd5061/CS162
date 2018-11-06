/* Author: Meghan Dougherty
   Date: 07/09/2018
   Description: The main file/menu to test the palindrome and queue buffer simulator. Includes input validation for all user input. 

*/
#include"FunctionDecs.hpp"
#include"dynamicQueue.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <time.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::queue;


int main()

{
	//seed random number generator
	srand(static_cast <unsigned int>(time(0)));

	string input;
	int rounds;
	int appendChance;
	int removeChance;
	int n;
	int currentL;
	double currentAv = 0;
	double lastAv = 0;

	//create an empty queue object
	queue<int> dynamQueue;


	cout << "Welcome to Lab 7" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1. Buffer simulation." << endl;
	cout << "2. Palindrome." << endl;

	getline(cin, input);

	//input validation. Make sure the input is either 1 or 2.
	while (!cin || input.length() > 1 || (input[0] < 49 || input[0] > 50))
	{
		cout << "Invalid input. Please enter either 1 or 2." << endl;
		getline(cin, input);
	}

	//Buffer Simulator.
	if (input[0] == 49)
	{
		cout << "Please enter the number of rounds you'd like to simulate." << endl;
		getline(cin, input);

		//input validation. Make sure the input is an integer. 
		while (!cin || input.find_first_not_of("0,1,2,3,4,5,6,7,8,9")!=std::string::npos)
		{
			cout << "Invalid input. Please enter an integer." << endl;
			getline(cin, input);
		}
		//convert string to int.
		rounds = atoi(input.c_str());

		cout << "Please enter the percentage chance to put a randomly generated number at the end of buffer." << endl;
		getline(cin, input);

		//input validation. Make sure the input is an integer. 
		while (!cin || input.find_first_not_of("0,1,2,3,4,5,6,7,8,9") != std::string::npos)
		{
			cout << "Invalid input. Please enter an integer." << endl;
			getline(cin, input);
		}

		//convert string to int.
		appendChance = atoi(input.c_str());

		cout << "Please enter the percentage chance to take out a randomly generated number at the front of buffer." << endl;
		getline(cin, input);

		//input validation. Make sure the input is an integer. 
		while (!cin || input.find_first_not_of("0,1,2,3,4,5,6,7,8,9") != std::string::npos)
		{
			cout << "Invalid input. Please enter an integer." << endl;
			getline(cin, input);
		}
		//convert string to int.
		removeChance = atoi(input.c_str());

		for (int i = 1; i <= rounds; i++)
		{
			cout << "Round: " << i << endl;
			//Generate a random number from 1 – 1000 called N.
			n = randNum();
			
			//Append number
			addNum(&dynamQueue, n, appendChance);

			//Remove number
			removeNum(&dynamQueue, removeChance);

			//Output the values in the buffer, and then output the length of the buffer.
			outputBuffer(&dynamQueue);

			//Output the average length of buffer.
			currentL = dynamQueue.size();
			
			currentAv = (lastAv*(i - 1) + currentL) / i;
			cout << "The average buffer size is: " << currentAv << endl;
			
			cout << endl;

			//set the current average to averate-1. 
			lastAv = currentAv;

			//Pause the loop so user can review round information.
			do
			{
				cout << '\n' << "Press a key to continue...";
			} while (cin.get() != '\n');

		}
		return 0;
	}

	//Palindrome
	if (input[0] == 50)
	{
		cout << "Please enter the string you'd like to palindrome-ize!" << endl;

		getline(cin, input);

		//user input. Check for input error.
		while (!cin)
		{
			cout << "Invalid Input. Please enter a string." << endl;
			getline(cin, input);
		}
		//make the palindrome
		palindromePrint(input);
	}
    return 0;
}

