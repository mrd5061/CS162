/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function declaration file for the Menu class. Allows the user to "play" the battle game with the characters. 
Handles input validation. 

*/
#ifndef MENU_H
#define MENU_H


#include "Character.hpp"
#include <string>
using std::string;

class Menu
{
private:
	int choice;
	string input;

	baseCharacter* player1;
	baseCharacter* player2;
public:
	Menu();
	int mainMenu();
	int returnMenu();

	baseCharacter* getPlayer1();
	baseCharacter* getPlayer2();
	void deleteCharacters();

};

#endif // !MENU_H
