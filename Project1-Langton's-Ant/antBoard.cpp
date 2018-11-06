/*Author: Meghan Dougherty
 *Date: 7/01/2018
  Description: The function definition file for the antBoard class. THis class
  contains functions that create the board the ant moves on as well as functions
  that govern the ant's movement and when square colors change.
*/  

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "antBoard.hpp"
#include "ant.hpp"


/* antBoard: the constructor for the antBoard class. dynamically allocates
 * the simBoard as a 2d array, and initializes a border( eitehr '|' or '-') 
 * as well as a ' ' in the "playable" field.
*/

antBoard::antBoard(int row, int col)
{	
	

	boardRows = row;
	boardCols = col;
	
	//allocated the memory for the board based on user inputs. 
	simBoard = new char*[row];
	for(int i = 0; i < row; i++)
		simBoard[i] = new char[col];
	
	for(int k=0; k<row; k++)
	{
		for(int m=0; m < col; m++)
		{
			// Top and Bottom Borders.
			if (k==0||k == (row-1))
				simBoard[k][m] = '-';
			//Left and Right Borders.
			else if ((m == 0 && k > 0) || (m==(col-1) && k > 0))
				simBoard[k][m] = '|';  
			//"Playable" space.
			else	simBoard[k][m] = ' ';
		}
	}
}

/* deleteBoard: deletes the contents of simBoard. This frees up the allocated
 * memeory as well as removing any lingering data in case the user wants to
 * run the simulation again
*/ 

void antBoard::deleteBoard()
{
	for(int i = 0; i < boardRows; i++)
		delete [] simBoard[i];
	delete [] simBoard;

}

/* setSquareColor: takes a pointer to an ant object and stores the character
 * located at the ants current location on the simBoard.
*/
 
void antBoard::setSquareColor(Ant *ptr)
{
	int r = (*ptr).getAntRow();
	int c = (*ptr).getAntCol();

	squareColor = simBoard[r][c];
}

// getSquareColor: returns the info stored at the squareColor variable.	
//
char antBoard::getSquareColor()
{	
	return squareColor;
}

/* invertSquareColor: takes a pointer to an Ant Object and retrieves 
 * the location of the ant on the board. The function then checks
 * what character is stored in the squareColor variable and changes 
 * it to '#' if its a ' ' and vice versa. 
*/
   
void antBoard::invertSquareColor(Ant *ptr)
{

	int r = (*ptr).getAntRow();
	int c = (*ptr).getAntCol();
	if(squareColor == '#')
		simBoard[r][c]= ' ';
	else
		simBoard[r][c] = '#';
				
}

/* setAnt: taks a pointer to an At Object and places the ant character
 * '*' on the board based on the row and column of the ant object. 
*/
 
void antBoard::setAnt(Ant *ptr)
{
	int r = (*ptr).getAntRow();
	int c = (*ptr).getAntCol();

	
	simBoard[r][c] = '*';
	
}

// printBoard: Prints the current contets of the simBoard..

void antBoard::printBoard()

{
	for(int i=0; i<boardRows; i++)
	{
		for(int k=0; k<boardCols; k++)
		{
			cout << simBoard[i][k]<< " ";
		}
		cout << endl;		
	}
	cout << endl;
}

/*moveAnt: takes a pointer to an Ant Object, then moves the
 *ant forward one space based on the ant's orientation. If
 *the ant is on the edge of the playable space, the ant's
 *the ant's orientation is flipped 180 degrees and the 
 *ant does not move forward.  
*/
void antBoard::moveAnt(Ant *ptr, int r, int c)
{
	int antR = (*ptr).getAntRow();
	int antC = (*ptr).getAntCol();
	char o = (*ptr).getAntOrient();
	
	/* The ant's orientation is represented using
 	 * characters that represent the cardinal directions.
 	 */
 		
	if(o == 'N')
	{
		if(antR > 1)
		{	
			(*ptr).setAntRow(antR - 1);
		}

		else
		{
			(*ptr).setAntOrient('S');
			(*ptr).setAntRow(antR + 1);
		}
	}
	if(o == 'E')
	{
		if (antC < (c - 2))
			(*ptr).setAntCol(antC+1);
		else
		{
			(*ptr).setAntOrient('W');
			(*ptr).setAntCol(antC-1);
		}
	}	

	if(o == 'S')
	{
		if (antR < (r-2))
			(*ptr).setAntRow(antR+1);
		else
		{
			(*ptr).setAntOrient('N');
			(*ptr).setAntRow(antR-1);
		}
	}
	if(o == 'W')
	{
		if (antC > 1)
			(*ptr).setAntCol(antC-1);
		else
		{
			(*ptr).setAntOrient('E');
			(*ptr).setAntCol(antC+1);
		}
	}
}

/*turnAnt: takes a pointer to an Ant Object and retireves
 * the ant's orientation. The ant's orientation is then 
 * rotated either 90 degrees right or left depending on
 * what is stored in the squareColor variable. 
*/
 
void antBoard::turnAnt(Ant *ptr)
{
	char o = (*ptr).getAntOrient();
	
	/* If the ant is on a black or '#' space, it turns
	   left. If the ant is on a white or ' ' space, it
	   turns right.
	*/

	if(o == 'N')
	{	
		if(squareColor == '#')
			(*ptr).setAntOrient('W');
		if(squareColor == ' ')	
			(*ptr).setAntOrient('E');
	}

	if(o == 'E')
	{	
		if(squareColor == '#')
			(*ptr).setAntOrient('N');
		if(squareColor == ' ')	
			(*ptr).setAntOrient('S');
	}

	if(o == 'S')
	{	
		if(squareColor == '#')
			(*ptr).setAntOrient('E');
		if(squareColor == ' ')	
			(*ptr).setAntOrient('W');
	}

	if(o == 'W')
	{	
		if(squareColor == '#')
			(*ptr).setAntOrient('S');
		if(squareColor == ' ')	
			(*ptr).setAntOrient('N');
	}

}
