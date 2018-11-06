/* Name: Meghan Dougherty
Date: 07/29/1988
Description: Main function file that implements the three recursive functions (printReverse, arraySum, and triangleNum) 
and the main menu function. 


*/

#include "functions.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using std::stoi;
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	string inputString;

	int choice = mainMenu();
	int* inputArray;
	int arraySize;

	//While the user wants to continue, run the mainMenu program. 
	while (choice < 4)
	{
		//A switch menu based on the user's choice from the main menu.
		switch (choice)
		{
		case 1:
			cout << "Please enter the string you would like to reverse." << endl;
			//get the input string.
			getline(cin, inputString);
			//reverse it.
			cout << "Your string backward is: ";
			printReverse(inputString);
			break;
		case 2:
			cout << "Please enter a size for your array." << endl;
			//get array size.
			getline(cin, inputString);
			//validate.
			while (inputString.length() > 1 || !(isdigit(inputString[0])) || stoi(inputString) < 1)
			{
				cout << "Invalid Input. Please enter a positive integer." << endl;
				getline(cin, inputString);
			}
			//convert to int.
			arraySize = stoi(inputString);

			//allocate array. 
			inputArray = new int[arraySize];

			//get the array contents.
			cout << "Please enter the numbers in your array, each followed by enter." << endl;
			for (int i = 0; i < arraySize; i++)
			{
				getline(cin, inputString);
				//validate input.
				//input must be a digit, and if the number is more than one digit long, it should
				//not start with a 0.
				while ((inputString[0]==48 && inputString.length()>1)||!(isdigit(inputString[0])))
				{
					cout << "Invalid Input. Please enter an integer." << endl;
					getline(cin, inputString);
				}
				//convert to integer and store in array.
				inputArray[i] = stoi(inputString);
			}
			cout <<"The sum of your array is: "<< arraySum(inputArray, arraySize) << endl;
			//free the memory.
			delete[] inputArray;
			break;

		case 3:
			cout << "Please enter a number to calculate the triangle number." << endl;
			cout << "The number must be between 1 and 100." << endl;
			//get input.
			getline(cin, inputString);

			//validate. Number must be a number, positive, and if it's two digits, the first digit
			//cannot be 0.
			while ((inputString.length() > 1 && inputString[0]==48) || !(isdigit(inputString[0])) || (stoi(inputString) < 1|| stoi(inputString) >100))
			{
				cout << "Invalid Input. Please enter an integer between 1 and 100." << endl;
				getline(cin, inputString);
			}
			int triangle = stoi(inputString);
			cout << "The triangle sum is: " << triangleNum(triangle) << endl;
			break;

		}
		choice = mainMenu();
	}
	cout << "Goodbye!" << endl;

    return 0;
}

