/*
*Author: Meghan Dougherty
*Date: 07/10/2018
*Description:The implementation file for the Game class. Contains private member variables and public functions
 *used to play the dice war game, as well as the menu functions for the game. 
*/

#include <iostream>
#include <stdlib.h>   
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
//<using std::atoi;

#include "Game.hpp"
#include "Dice.hpp"
#include "LoadedDice.hpp"

/*  Game: constructor. Takes no arguments, and intializes the integer variables to 0 and the 
 *character variables to a. 
*/
Game::Game()
{
	rounds = 0;
	playChoice = 'a';
	diceChoice1 = 'a';
	diceChoice2 = 'a';
	sideChoice1 = 0;
	sideChoice2 = 0;
	score1 = 0;
	score2 = 0;
}

// getPLayeChoice: takes no arguments, returns the playChoice variable. 

char Game::getPlayChoice()
{
	return playChoice;

}

/* mainMenu: takes no arguments, prints the main menu options and 
validates the users input. 
*/
int Game::mainMenu()
{
	string input; 
	//initial greeting. 
	cout << "Welcome to the Dice War Game" << endl;
	cout << "Please enter Y if you would like to play" << endl;
	cout << "Otherwise, enter Q if you want to quit." << endl;

	//Get the user input and store it in a temporary string.
	getline(cin, input);
	
	/* If the input string is one character long, store the character
	in play choice. Otherwise store an incorrect value. This keeps strings
	that start with Y or Q from being accepted as valid input. 
	*/
	if (input.length() == 1)
		playChoice = toupper(input[0]);
	else
		playChoice = 'a';
	 
	 

	//data validation.
	while( !cin || !(playChoice == 'Y'|| playChoice == 'Q'))
	{	
		cout << endl;	
		cout << "Invalid entry." << endl;
		cout << "Please enter either Y to play or Q to quit." << endl;

		getline(cin, input);

		if (input.length() == 1)
			playChoice = toupper(input[0]);
		else
			playChoice = 'a';
	}

	return 0;
	
}
/* playGameMenu: takes no arguments. Asks the user for the necessary
 variables to play the war game, including dice choice, dice side
 choice, and number of rounds. Validates each input before continuing.

*/
void Game::playGameMenu()
{
	string input;
	cout << endl;
	//Ask for and validate the number of rounds.
	cout << "How many rounds would you like to play?" << endl;

	getline(cin, input);

	/* If the first character in the string is 0 (Ascii value 48), store the rounds as
	0. Otherwise, store the string as the rounds.*/

	if (input[0] == 48)
		rounds = 0;
	else
		rounds = atoi(input.c_str());
	
	
	while (!cin || rounds < 1)
	{
		cout << endl;
		cout << "Invalid Input. Please enter a positive integer with no leading 0's." << endl;
		getline(cin, input);

		if (input[0] == 48)
			rounds = 0;
		else
			rounds = atoi(input.c_str());
	
	}

	//Ask for and validate the dice type for player one. 
	cout << endl;
	cout << "Please Select the type of dice each player will use" << endl;
	cout << "For player one, select R for regular or L for loaded." << endl;

	getline(cin, input);

	/* If the string is one character long, store the character
	Otherwise, store an erroneous value.*/
	if (input.length() == 1)
		diceChoice1 = toupper(input[0]);
	else
		diceChoice1 = 'a';

	while (!cin || !(diceChoice1 == 'R' || diceChoice1 == 'L'))
	{
		cout << endl;
		cout << "Invalid Input. Please enter R for regular or L for loaded." << endl;

		getline(cin, input);

		if (input.length() == 1)
			diceChoice1 = toupper(input[0]);
		else
			diceChoice1 = 'a';
	}

	//Ask for and validate dice 1 sides.
	cout << endl;
	cout << "How many sides would you like this die to have?" << endl;
	getline(cin, input);

	if (input[0]== 48)
		sideChoice1 = 0; 
	else
		sideChoice1 = atoi(input.c_str());

	//Dice cannot have 0 or negative numbers of sides.
	while (!cin || sideChoice1 < 1)
	{
		cout << endl;
		cout << "Invalid Input. Please enter a positive integer." << endl;
		getline(cin, input);

			
		if(input[0]==0)
			sideChoice1 = 0;
		else
		{
			sideChoice1 = atoi(input.c_str());
		}
	}

	
	//Repeat dice process for player 2. 
	cout << endl;
	cout << "For player two, select R for regular or L for loaded." << endl;

	getline(cin, input);

	if (input.length() == 1)
		diceChoice2 = toupper(input[0]);
	else
		diceChoice2 = 'a';

	while (!cin || !(diceChoice2 == 'R' || diceChoice2 == 'L'))
	{
		cout << endl;
		cout << "Invalid Input. Please enter R for regular or L for loaded." << endl;

		getline(cin, input);

		if (input.length() == 1)
			diceChoice2 = toupper(input[0]);
		else
			diceChoice2 = 'a';
	}

	//Ask for and validate dice 1 sides.
	cout << endl;
	cout << "How many sides would you like this die to have?" << endl;
	getline(cin, input);

	if (input[0]==48)
		sideChoice2 = 0;
	else
		sideChoice2 = atoi(input.c_str());

	//Dice cannot have 0 or negative numbers of sides.
	while (!cin || sideChoice2 < 1)
	{
		cout << endl;
		cout << "Invalid Input. Please enter a positive integer." << endl;
		getline(cin, input);

		if (input.length() == 1)
			rounds = atoi(input.c_str());
		else
			sideChoice2 = 0;
	}



}
/* quitMessage: takes no arguments. Prints to indicate that the user either
voluntarily quit the game or that the game has completed. 

*/
void Game::quitMessage()
{
	cout << "Thank you for playing!" << endl;
	cout << "GoodBye!" << endl;

	
}

/* makeRDice: takes the number of sides as an argument. Creates a new 
regular Dice object and returns the pointer to that object. 
*/
Dice* Game::makeRDice(int n)
{
	
	return new Dice(n);

	
}

/* makeLDice: takes the number of sides as an argument. Creates a new
Loaded Dice object and returns the pointer to that object.
*/
LoadedDice* Game::makeLDice(int n)
{
	return new LoadedDice(n);
}

/*playRound: takes no arguments. Rolls the dice, prints the results, and updates and prints
the players scores for each round of the war game. 
*/
void Game::playRound()
{
	//Pointers to the Dice objects. 
	Dice *Dice1;
	Dice *Dice2;
	
	//Create the dice objecs.
	if (diceChoice1 == 'R')
	{
		Dice1 = makeRDice(sideChoice1);
	}
	else
		Dice1 = makeLDice(sideChoice1);

	if (diceChoice2 == 'R')
	{
		Dice2 = makeRDice(sideChoice1);
	}
	else
		Dice2 = makeLDice(sideChoice1);

	//Loop runs for the user designated number of rounds.
	for (int i = 0; i < rounds; i++)
	{
		cout << endl;
		cout << endl;

		//Roll the dice and store the information.
		int currentroll1 = Dice1->diceRoll();
		int currentroll2 = Dice2->diceRoll();
		
		//Print the results of the roll.

		cout << "******Round " << i+1 << "******" << endl;
		cout << "Player one rolled a: " << endl;
		cout << "\t" <<  currentroll1<< endl;
		cout << "with a "; 
		if (diceChoice1 == 'R')
			cout << "regular dice" << endl;
		else
			cout << "loaded dice" << endl;
		cout << endl;
		


		cout << "Player Two rolled a: " << endl;
		cout << "\t" << currentroll2 << endl;
		cout << "with a ";
		if (diceChoice2 == 'R')
			cout << "regular dice" << endl;
		else
			cout << "loaded dice" << endl;
		
		cout << endl;

		/*Update the score but incrementing the score of
		the player that rolled the higher number. 
		If the round was a tie, no incrementation occurs.
		*/
		if (currentroll1 != currentroll2)
		{
			if (currentroll1 > currentroll2)
				score1++;
			if (currentroll1 < currentroll2)
				score2++;
		}
	
		//Print the scores. 
		cout << "The current score is:" << endl;
		cout << "Player one: ";
		cout << score1 << endl;
		cout << "Player two: ";
		cout << score2 << endl;
		cout << endl;
		cout << "********************" << endl;
	}

	delete Dice1;
	delete Dice2;
	
}
/* printFinalScore: takes no arguments. Prints the final results of the war game.
and declares the winner. If the game is a draw, the function prints a draw message.
*/
void Game::printFinalScore()
{
	cout << endl;
	cout << endl;
	cout << "The game is over!" << endl;
	cout << "The final score is: " << endl;
	cout << "Player one: ";
	cout << score1 << endl;
	cout << "Player two: ";
	cout << score2 << endl;
	cout << endl;
	cout << endl;

	//Calculate the winner of the game.
	if (score1 > score2)
		cout << "Player One wins!" << endl;
	if (score2 > score1)
		cout << "Player Two wins!" << endl;

	//See if the game was a draw. 
	if (score2 == score1)
		cout << "The game was a tie!" << endl;
	cout << endl;
	cout << endl;
}
