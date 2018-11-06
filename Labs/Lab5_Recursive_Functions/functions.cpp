/* Name: Meghan Dougherty
Date: 07/29/1988
Description: The function definition file for three recursive functions. One prints a string in reverse, one calculates the sum of
an array of numbers, and one calculates the triangular number of an integer. Also includes a menu function to tie the three functions
together.


*/
#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

#include "functions.hpp"

/* printReverse: takes one string parameter. Recursively prints the string backward, finishing with a
newline character. 

*/
void printReverse(string s)
{
	//get the size of the string.
	int charNum = s.size();

	//Base Case. The function should stop when there are no more letters
	//and print a newline character.
	if (charNum == 0)
		cout << "\n" << endl;

	else
	{
		//Print out the last character of the string. 
		cout << s[charNum - 1];

		//create a new string that removes the last letter of the previous string
		//and call the print reverse function again. 
		printReverse(s.substr(0,(charNum-1)));
	}
}

/* arraySum: takes two parameters:an array pointer and an array size. Recursively 
sums the contents of the array and returns the result. 
*/
int arraySum(int ptr[], int size)
{
	//Base Case. Recursive function should stop when there are 
	//no more integers to sum.
	if (size <= 0)
	{
		return 0;
	}

	//Call the arraySum with the size minus one and add that result to
	//what's at the end of the array.
	else
	{
		return arraySum(ptr, (size - 1)) + ptr[size - 1];
	}

}

/* triangleNum: takes one argument, an integer. Calculates the triangle number of
that integer, basically a backward summation. 

*/
int triangleNum(int n)
{
	//Base case. End the function when the term is less than 0.
	if (n < 1)
		return 0;
	//Add the current n with n-1. Re-call the function. 
	else
	{
		return n + triangleNum(n-1);
	}



}

/* mainMenu: takes no arguments. Presents the list of choices to the user, then
accepts, validates, and returns their choice.

*/
int mainMenu()
{
	string input; 
	cout << endl;
	//Menu Choices.
	cout << "Please select an option from the following list." << endl;
	cout << "1. Printing Backwards." << endl;
	cout << "2. Summing an Array." << endl;
	cout << "3. Calculate Triangle Number." << endl;
	cout << "4. Quit." << endl;

	//Get user input.
	getline(cin, input);

	//Validate.
	while (input.length()> 1 || !(isdigit(input[0])))
	{
		cout << "Invalid Input. Plese select an option from the list." << endl;
		getline(cin, input);
	}

	//convert to integer and return.
	return stoi(input);
}
