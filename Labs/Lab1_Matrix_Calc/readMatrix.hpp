/*
 * Author: Meghan Dougherty
 * Date: 06/26/2018
 * This is the header file for the readMatrix function which, when passed an 
 * array pointer and size integer, takes in either 4 or 9 integers from the
 * user ,depending on the array size the user chose, and uses those integers to
 * populate the array.
 */

//Include guard. 
#ifndef READMATRIX_H
#define READMATRX_H

//Function prototype. This function takes an array pointer and the size
//of the array as arguments, but does not return aything.

void readMatrix(int* arrayPtr[],int size);

#endif
