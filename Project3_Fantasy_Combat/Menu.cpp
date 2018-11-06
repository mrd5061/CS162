/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function definition file for the Menu class. Has two functions,  a main and a return menu
that allow the user to "play" the character battle game. 

*/
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarinan.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

/* Menu: Constructor. creates a menu object and sets the choice variable to 0, the input string to a blank space and the two
character pointers to NULL.
*/
Menu::Menu()
{
	int choice = 0;
	string input = " ";

	baseCharacter* player1 = NULL;
	baseCharacter* player2 = NULL;
}
/* mainMenu: Displays the five characters by name for the user to choose from. Validates the users choice, then uses that
input to assign new character objects to the character pointers. 

*/
int Menu::mainMenu()
{
	//Display user choices and get user input.
	cout << "Welcome to the battle!" << endl;
	cout << "These are the characters:" << endl;
	cout << "1. Barbarian" << endl;
	cout << "2. Blue Men" << endl;
	cout << "3. Harry Potter" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Vampire" << endl;
	cout << "Using their corresponding numbers, select the first opponent." << endl;

	getline(cin, input);
	
	//Validate the input. 
	while (!cin || input.length() > 1 || ((input[0] > 53 || input[0] < 49)))
	{
		cout << "Invalid Input. Please enter a number between 1 and 5." << endl;
		getline(cin, input);
	}

	//convert the input string to an integer.
	choice = stoi(input);

	//Switch statement to create a new character object and assign the pointer. 
	switch (choice)
	{
	case 1:
		player1 = new Barbarian;
		break;
	case 2: 
		player1 = new BlueMen;
		break;
	case 3:
		player1 = new HarryPotter;
		break;
	case 4:
		player1 = new Medusa;
		break;
	case 5:
		player1 = new Vampire;
		break;
	}

	//Repeat the process for player two. 
	cout << "Using their corresponding numbers, select the second opponent." << endl;

	getline(cin, input);

	while (!cin || input.length() > 1 || ((input[0] > 53 || input[0] < 49)))
	{
		cout << "Invalid Input. Please enter a number between 1 and 5." << endl;
		getline(cin, input);
	}

	choice = stoi(input);

	switch (choice)
	{
	case 1:
		player2 = new Barbarian;
		break;
	case 2:
		player2 = new BlueMen;
		break;
	case 3:
		player2 = new HarryPotter;
		break;
	case 4:
		player2 = new Medusa;
		break;
	case 5:
		player2 = new Vampire;
		break;
	}

	return 0;
}
/* returnMenu: asks the player if they want to play again, gets input and validates it before returning either a 1 or a 0. 
*/
int  Menu::returnMenu()
{
	//ask for input
	cout << "Play again?" << endl;
	cout << "Enter Y for yes or N for no." << endl;
	getline(cin, input);

	//validate input. Make sure the input is only y, Y, n, or N. 
	while (!cin || input.length() > 1 || !(input[0] == toupper('y') || input[0] == 'y' || input[0] == 'n' || input[0] == toupper('n')))
	{
		cout << "Invalid Input." << endl;
		cout <<"Enter Y for yes or N for no." << endl;
		getline(cin, input);
	}

	//If the user wants to play again (entered y or Y) return 1.
	if (input[0] == 'y' || input [0] == toupper('y'))
	{
		return 1;
	}
	//otherwise, return 0. 
	else
		return 0; 
}

/* getPlayer1: returns the player 1 pointer.
*/
baseCharacter*  Menu::getPlayer1()
{
	return player1;
}
/* getPlayer2: returns the player 2 pointer.
*/
baseCharacter*  Menu::getPlayer2()
{
	return player2;
}

void Menu::deleteCharacters()
{
	delete player1;
	delete player2;

	player1 = NULL;
	player2 = NULL;
}
