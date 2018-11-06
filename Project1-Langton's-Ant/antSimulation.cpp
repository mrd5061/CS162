/*Author: Meghan Dougherty
 *Date: 07/08/2018
 *Description: The function implementation file for the antSimulation function. This function ties together functions
 *from the ant and antBoard class, and ties them together with user input run and print the results of the simulation
 */

#include "antBoard.hpp"
#include "ant.hpp"
#include "antSimulation.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
/*antSimulation: takes  a pointer to an ant object as an argument. Asks user for all the necessary variables to run 
 * the simulation (board size, ant starting location, number of steps) then validates the information. The function
 * then creates an antBoard oject before placing the ant on the board. The function then loops through the ants 
 * movements for the specified number of steps, printing the result of each step. 
 */ 
void antSimulation(Ant *ptr)
{
	int steps = 0; 
	int rows = 0;
	int cols = 0;
	int antStartRow;
	int antStartCol;

	//The following commands ask for the simulation paramemters
	
	/*I limited the number of rows and colums to 80 because that 
	 is the largets board that would cleanly output on my screen.*/
	
	cout << "How many rows would you like the board to have?" << endl;
	cout << "Please enter a number from 2 to 80" << endl;
	cin >> rows; 
	while( rows <2 || rows > 80)
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number from 2 to 1000" << endl; 
		cin >> rows;
	}

	

	cout << "How many columns would you like the board to have?" << endl;
	cout << "Please enter a number from 2 to 80" << endl;
	cin >> cols; 

	while( !cin || cols <2 || cols >80 )
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number from 1 to 1000" << endl; 
		cin >> cols;
	}
	
	//increase the user specified array bounds to include boundary rows and columns

	rows = rows + 2;
	cols = cols + 2;
  
	//ask for starting location.
	cout << "What row would you like your ant to start on?" << endl;
	cout << "Please enter a number from 1 to "<< rows-2 << endl;
	cin >> antStartRow;
	
	while(!cin || antStartRow < 1 || antStartRow > (rows-2))
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number from 1 to " << rows-2 << endl;
		cin >> antStartRow;
		
	}
	
	//Update the ant object
	(*ptr).setAntRow(antStartRow);

	cout << "What column would you like your ant to start on?" << endl;
	cout << "Please enter a number from 1 to "<< cols-2 << endl;
	
	cin >> antStartCol;
	
	while(!cin || antStartCol < 1 || antStartCol > cols-2)
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number from 1 to " << cols-2 << endl;
		
		cin >> antStartCol;
		
	}
	
	//Update the ant object.
	(*ptr).setAntCol(antStartCol);


	cout << "How Many steps would you like the ant to take?" << endl;
	cout << "Please enter a number between 1 and 10,000." << endl;
	cin >> steps; 
	
	while(!cin || steps < 1 || steps >10000 ) 
	{
		cin.clear();	
		cin.ignore();

		cout << " Invalid Input. Please enter a number between 1 and 10000" << endl;
		cin >> steps;
	}
	
	
	//create the antBoard object. 
	antBoard lsBoard(rows, cols); 
	//update the color of the square the ant is on so the info isn't lost during
	//the next step.
	lsBoard.setSquareColor(ptr);
	//Put the ant on the board
	lsBoard.setAnt(ptr);
	//Print the board.
	lsBoard.printBoard();

	//Loop limited to the user specified steps.
	for(int i=0;i<steps; i++)
	{
		//invert the color of the ant's current location
		//referencing the squareColor variable.
		lsBoard.invertSquareColor(ptr);

		//move the ant "forward" one step.
		lsBoard.moveAnt(ptr, rows, cols);

		//store the color of the ant's new location.		
		lsBoard.setSquareColor(ptr);
		
		//turn the ant based on the info from the 
		//previous step
		lsBoard.turnAnt(ptr);
		
		//place teh ant marker on the board.
		lsBoard.setAnt(ptr);
		
		//print the board
		lsBoard.printBoard();
	}

	//de-Allocate the memory after the simulation compeltes. 
	lsBoard.deleteBoard();
	return;
}	
