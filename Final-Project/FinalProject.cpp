/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The Main function for the Black Hole Escape game. 

*/


#include <ctime>
#include<iostream>
#include "Player.hpp"
#include "Game.hpp"
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
int main()
{
	int choice;
	//seed random number generator. Several damage functions rely on random numbers
	srand(static_cast<unsigned int> (time(NULL)));

	//create the player
	Player player;

	//create the game
	Game newGame;
	
	
	newGame.makeBoard();

	choice = newGame.startGame();

	//if the player wants to play.
	while (choice == 1)
	{
		//continue the game while the user hasn't won or died.
		while (player.getWonBool() == false && player.getHealth()>0)
		{	
			newGame.changeRooms(&player);
	
				
		}		
		choice = 3;
	}

	if (choice == 3)
		newGame.printFinalMessage(&player);
	cout << "Thank you for playing!" << endl;
	return 0;
}

