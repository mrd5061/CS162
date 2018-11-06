/*
 * Author: Meghan Dougherty
 * Date: 06/26/2018
 * This is the source file for the determinant function which, when passed an 
 * array pointer and size integer, calculates and the returns the determinant 
 * of the matrix.
 */

//Header file. 
#include "determinant.hpp" 
 

int determinant(int* arrayPtr[],int size)
{
	//Check if it's a 2x3 array. 
	if(size ==2)
	{
		//Return the calculation.
		return ((arrayPtr[0][0]) * (arrayPtr[1][1]))- ((arrayPtr[0][1]) * (arrayPtr[1][0]));
	}
	
	//Check if it's a3x3 array. 
	if(size == 3)
	{
		//The calculations for this array have been split into three variables for the sake of readability.
		
		int a = arrayPtr[0][0] * ((arrayPtr[1][1] * arrayPtr[2][2]) - (arrayPtr[1][2] * arrayPtr[2][1]));
		int b = arrayPtr[0][1] * ((arrayPtr[1][0] * arrayPtr[2][2]) - (arrayPtr[1][2] * arrayPtr[2][0]));
		int c = arrayPtr[0][2] * ((arrayPtr[1][0] * arrayPtr[2][1]) - (arrayPtr[1][1] * arrayPtr[2][0]));
		
		//return the final Calcuation
		return a - b + c;
	}	
	
	//Included for formality. Data validation should ensure that either a 2 or a 3 is passed to this function.
	else
		return 0;


}
