/*
 * Author: Meghan Dougherty
 * Date: 06/26/2018
 * This is the header file for the determinant function which, when passed an 
 * array pointer and size integer, calculates and the returns the determinant 
 * of the matrix.
 */

//Include guard.
#ifndef DETERMINANT_H
#define DETERMINANT_H

//Function prototype. This fuction takes an array pointer and the size of the
//array and returns the calculated determinant. 

int determinant(int* arrayPtr[],int size);

#endif
