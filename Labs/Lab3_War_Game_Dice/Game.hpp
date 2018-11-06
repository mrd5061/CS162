/*
*Author: Meghan Dougherty
*Date: 07/10/2018
*Description: The definition file for the Game class. Contains private member variables and public functions
 *used to play the dice war game, as well as the menu functions for the game. 
*/

#ifndef MENU_H
#define MENU_H
#include "Dice.hpp"
#include"LoadedDice.hpp"

class Game
{
	private:
		int rounds;
		char playChoice;
		char diceChoice1;
		char diceChoice2;
		int sideChoice1;
		int sideChoice2;
		int score1;
		int score2;
		

	public:

		Game();
		char getPlayChoice();
		int mainMenu();
		void playGameMenu();
		void quitMessage();
		Dice* makeRDice(int);
		LoadedDice* makeLDice(int);

		void playRound();
		void printFinalScore();


};

#endif

