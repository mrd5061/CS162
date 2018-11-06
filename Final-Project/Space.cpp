/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Space Class. An abstract class that Ocean, Kitchen, Hallway, EscapePod,
and Repeat are based off of. 
*/


#include "Space.hpp"

//Constructor. 
Space::Space()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = " ";
	input = " ";
}

//The following are getters and setters for the class variables. 

void Space::setVisited(bool b)
{
	visited = b;
}
bool Space::getVisited()
{
	return visited;
}

string Space::getRoomName()
{
	return roomName;
}


void Space::setUp(Space* temp)
{
	Up = temp;
}
void Space::setDown(Space* temp)
{
	Down = temp;
}
void Space::setLeft(Space* temp)
{
	Left = temp;
}
void Space::setRight(Space* temp)
{
	Right = temp;
}

Space* Space::getUp()
{
	return Up;
}
Space* Space::getDown()
{
	return Down;
}
Space* Space::getLeft()
{
	return Left;
}
Space* Space::getRight()
{
	return Right;
}
