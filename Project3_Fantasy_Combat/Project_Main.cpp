/*Author: Meghan Dougherty
Date:07/31/2018
Description: The main function to test the Character class and it's subclasses: Barbarian, Blue Men, Harry Potter, Medusa
and Vampire. Simulates battle between two user chosen characters, and displays the results of the attacks and defenses. 

*/


#include "Menu.hpp"
//#include "Character.hpp"
#include "Barbarinan.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//seed the random number generator.
	srand(static_cast<unsigned int> (time(NULL)));

	
	int newGame = 0; //a bool like variable that decides if the player wants to play another round.
	
	// pointers to character objects.
	baseCharacter* Player1; 
	baseCharacter* Player2;

	//create the menu object.
	Menu newMenu;
	
	//repeat the menu battle sequence so long as the player desires.
	do
	{
		//display the main menu and get the character chocies. 
		newMenu.mainMenu();
		
		//Assign the character pointers.
		Player1 = newMenu.getPlayer1();
		Player2 = newMenu.getPlayer2();

		//Repeat combat rounds while the players are "alive"
		while (Player1->getStrengthPoints() > 0 && Player2->getStrengthPoints() > 0)
		{
			/* Round Begins:
			Player 1 attacks. Player 2 defends.
			*/
			cout << "Player One attacks!" << endl;
			Player1->attackRoll();
			Player2->defenseRoll();

			//Print the results of the dice rolls, along with the attack and defense totals.
			Player1->printAttackDiceRolls();
			cout << endl;
			Player2->printDefenseDiceRolls();

			cout << endl;

			//Sett the damage taken, and calculate Player 2's strength post attack.
			Player2->setDamageTaken(Player1->getAttackTotal());
			Player2->strengthCalc();

			//Print the results.
			cout << "Player 2 took: " << Player2->getDamageTaken() << " damage." << endl;
			cout << endl;
			cout << "Player one strength is: " << Player1->getStrengthPoints() << endl;
			cout << "player two strength is: " << Player2->getStrengthPoints() << endl;
			cout << endl;

			/* Round Continues:
			Player 2 attacks. Player 1 defends.
			Process is the same as player 1, so long as player 2 is still alive.  
			*/
			if (Player2->getStrengthPoints() > 0)
			{
				cout << "Player Two attacks!" << endl;
				Player2->attackRoll();
				Player1->defenseRoll();

				//Print the results of the dice rolls, along with the attack and defense totals.
				Player2->printAttackDiceRolls();
				cout << endl;
				Player1->printDefenseDiceRolls();

				cout << endl;
				//Sett the damage taken, and calculate Player 2's strength post attack.
				Player1->setDamageTaken(Player2->getAttackTotal());
				Player1->strengthCalc();

				//Print the results.
				cout << "Player 1 took: " << Player1->getDamageTaken() << " damage." << endl;
				cout << endl;

				cout << "Player one strength is: " << Player1->getStrengthPoints() << endl;
				cout << "player two strength is: " << Player2->getStrengthPoints() << endl;

		
			}
			//Pause the game to review the round information, mostly for testing purposes.
			do
			{
				cout << '\n' << "Press a key to continue...";
			} while (cin.get() != '\n');
		}
		cout << endl;

		//Print the winner. 
		if (Player1->getStrengthPoints() > 0)
			cout << "Player One wins!" << endl;
		else
			cout << "Player Two wins!" << endl;

		//ask if the player wants to play again.
		newGame = newMenu.returnMenu();

	} while (newGame == 1); // 1 signals the player does not want to play again.
	
	newMenu.deleteCharacters();

	Player1 = NULL;
	Player2 = NULL;
	
	return 0;
}

