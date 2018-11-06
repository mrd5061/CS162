/*Author: Meghan Dougherty
 * Date:7/01/2018
 * Description: The function definition file for the Ant Class. Defines the
 * getter and setter functions for Ant Objects.
*/ 
#include <iostream>

#include "ant.hpp"


using std::cout;
/*Constructor. The ant's starting location is (0,0) and it's defalt orientation
  is north. 
*/
Ant::Ant()
{
	antRow = 0;
	antCol = 0;
	antOrient = 'N'; 
}

//Getters

int Ant::getAntRow()
{
	return antRow;
}

int Ant::getAntCol()
{
	return antCol;
}

char Ant::getAntOrient()
{
	return antOrient;
}

//Setters
void Ant::setAntRow(int r)
{
	antRow = r;
}

void Ant::setAntCol(int c)
{
	antCol = c;
}

void Ant::setAntOrient(char d)
{
	antOrient = d;
}




 
