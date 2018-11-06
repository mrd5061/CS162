/* Author: Meghan Dougherty
 * Date: 07/10/2018
 * Description : The main function that ties together the dice, loaded dice,
 * and game classes into a playable war game.
 *
 */

#include <ctime>
#include <stdlib.h>

#include "Dice.hpp"
#include "LoadedDice.hpp"
#include "Game.hpp"

int main()
{
	//Random number seed.
	srand (static_cast<unsigned int>(time(NULL)));

	//Create the new game object.
	Game newGame;

	//Print the main menu.
	newGame.mainMenu();

	//If the user wants to play.
	if (newGame.getPlayChoice() == 'Y')
	{
		//Print the Game Menu
		newGame.playGameMenu();
		
		//Display the round results.
		newGame.playRound();
		
		//Display the final score
		newGame.printFinalScore();
		
		//End the program.
		newGame.quitMessage();

	}
	else
		//If the user quit.
		newGame.quitMessage();

	return 0;
}
