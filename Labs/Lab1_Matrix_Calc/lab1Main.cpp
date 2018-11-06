/*
 * Author: Meghan Dougherty
 * Date: 06/28/2018
 * Description: THe main function file for lab 1. This file connects the 
 * readMatrix and determinant functions. The user first inputs either a 2
 * or a 3 to create 2x2 or 3x3 matrix. The readMatrix function is called, and
 * after the user inputs their desired integers, the array and determinant 
 * are outputted.
 */ 


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Included manipluators so the matrix output looks cleaner.
#include <iomanip>
using std::setw;
using std::left;


//Header files for the respective functions.
#include "readMatrix.hpp"
#include "determinant.hpp"

int main()
{
	int size; //variable retrieved from user. Either 2 or 3.  

	cout << "Welcome!" << endl;
	cout << "First we will determine the size of the array you wish to create" << endl;
	
	cout << "Please enter 2 for a 2x2 array or 3 for a 3x3 array" <<endl;
	
	cin >> size;
	
	//Data Validation. 
	//Make sure the input is an integer. 
	while(!cin)
	{
		/*first clear the input buffer. Without this, the program will not wait for user 
  		input and,instead, keep outputing the error message.*/  
		cin.clear();
		cin.ignore();
		
		//Print error Message and propmt re-entry. 
		cout << "That wasn't a number. Please enter either 2 or 3" << endl;		
		cin >> size;
	}

	//Data validation Part 2. 
	//Make sure the number entered is either 2 or 3. 
	while (!(size==2||size==3))
	{	
		//same as before.
		cin.clear();
		cin.ignore();

		cout << "That was an invalid number. Please enter either 2 or 3" << endl;
		cin >> size;
	}

	//Dynamically allocate an array of pointers based in the inputted size.  
	int** inputMatrix = new int*[size];
	
	/*Initialize the array. 
	 each element of the original array is a pointer to another array, thus creating
	 a dynamically allocated 2d array.*/
	for (int c = 0; c < size; ++c)
		inputMatrix[c] = new int[size];

	//call the read Matrix function to populate the array.
	readMatrix(inputMatrix, size);
	
	cout << "This is your matrix"<< endl;
	
	//Print the Array.
	for (int r = 0; r < size; r++)
	{	for (int c = 0; c < size; c++)
		{
			cout << setw(4) << left <<  inputMatrix[r][c];
		}
		cout << endl;	  
	}


	cout << "This is the determinant" << endl;

	//calculate and print the determinant. 
	cout << determinant(inputMatrix, size) << endl;

	//Free the allocated memory. 
	for ( int s = 0; s < size; ++s)
	{
		delete []inputMatrix[s];
	}  		
	
	delete [] inputMatrix;

	return 0;
}
