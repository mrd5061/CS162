/*
 * Author: Meghan Dougherty
 * Date: 06/26/2018
 * This is the source file for the readMatrix function which, when passed an 
 * array pointer and size integer, takes in either 4 or 9 integers from the
 * user ,depending on the array size the user chose, and uses those integers to
 * populate the array.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//Header file. 
#include "readMatrix.hpp" 



void readMatrix(int* arrayPtr[],int size)
{
	//Prompt the user for the correct amount of numbers for the specified array size. 
	cout << "Please Enter " << size * size << " integers one at a time followed by the enter key." << endl;
	
	//Loop through the array to initialize the elements.
 	for (int r = 0; r < size; r++)
	{
		for(int c = 0; c < size; c++) 
		{
			cin >> arrayPtr[r][c];
		}
	}
	
	return;
}









