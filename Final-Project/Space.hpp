/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Space Class. An abstract class that acts as a template for the other rooms. 

*/


#ifndef SPACE_H
#define SPACE_H

#include <string>
#include "Player.hpp"

using std::string;

class Space
{
protected:
	Space *Up, *Down, *Left, *Right;
	bool visited;
	string roomName;
	string input;

public:

	Space();
	string getRoomName();
	bool getVisited();
	
	void setVisited(bool);

	virtual void firstTimeIn(Player*) = 0;
	virtual void nextTimeIn(Player*) = 0;

	void setUp(Space*);
	void setDown(Space*);
	void setLeft(Space*);
	void setRight(Space*);
	
	Space* getUp();
	Space* getDown();
	Space* getLeft();
	Space* getRight();
	


};
#endif // !SPACE_H

