

#include <stack>
#include <string>
#include <iostream>
#include "FunctionDecs.hpp"

using std::string;
using std::stack;
using std::cout;
using std::endl;

/* palindromePrint: takes a string as an argument. creates a palindrome by printint the string then printing the string in reverse by utilizing
a stack object. 
*/
void palindromePrint(string input)

{
	//get the size of the string.
	int size = input.length();

	//create an empty stack object.
	stack <char> palindrome;


	for (int i = 0; i < size; i++)
	{
		//put the contents of the string into the stack object. 
		palindrome.push(input[i]);
	}

	cout << input;
	
	while (!palindrome.empty())
	{
		//print the top of the stack
		cout << palindrome.top();
		//remove the top of the stack. 2nd item is now top.
		palindrome.pop();
	}
	cout << endl;
	
}


