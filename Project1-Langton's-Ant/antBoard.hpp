/*Author: Meghan Dougher
  Date: 7/01/2018
  Description: The header file for the antBoard class. This class holds the 
  variables, constroctors and getter/setter functions for the board the ant 
  moves on as well as functions governing the ants movement and when the
  board spaces change color
*/


#ifndef ANTBOARD_H
#define ANTBOARD_H

#include "ant.hpp"

class antBoard
{
	private: 
		char squareColor;
		int boardRows;
		int boardCols;
		
		//Will become a dynamic 2d array. 
		char** simBoard;	
	public:
		//constructor
		antBoard(int r, int c);
			
		//Setters
		void setBoardRows();
		void setBoardCols();
		void setSquareColor(Ant *ptr);
	
		//getters
		int getBoardRows();
		int getBoardCols();
		char getSquareColor();
		
		//Deletes board and frees allocated memory.
		void deleteBoard();	

		//Changes the square color of the ant's current location
		void invertSquareColor(Ant *ptr);
		
		//Places the ant marker on the board
		void setAnt(Ant*);
	
		//Prints the current state of the board
		void printBoard();

		//Moves the ant
		void moveAnt(Ant*, int, int);
		
		//Rotates the ant
		void turnAnt(Ant*);

};

#endif
