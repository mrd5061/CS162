/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Game Class. This class creates a playable escape game where the user can explore a
space ship. 

*/

#ifndef GAME_H
#define GAME_H


#include "Space.hpp"

#include<string>
using std::string;

class Game
{
private:
	
	string input;
	Space* currentRoom;
	Space* ocean;
	Space* hallway;
	Space* field;
	Space* escapePod;
	Space* repeatRoom;
	Space* kitchen;

public:
	Game();
	~Game();
	int startGame();
	void changeRooms(Player* temp);
	void makeBoard();

	Space* getCurrentRoom();
	void printFinalMessage(Player* temp);

};

#endif // DEBUG