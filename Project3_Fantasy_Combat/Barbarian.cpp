/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function definition file for the barbarian class. Includes a constructor, and
various overrides of the inherited Character functions. Barbarian does not have any unique functions.

*/

#include "Barbarinan.hpp"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/* Barbarian: Constructor. sets the dice roll variables and armor to 0. 
sets the strength points to 12. 
*/
Barbarian::Barbarian()
{
	diceRoll1 = 0;
	diceRoll2 = 0;
	armor = 0;
	strengthPoints = 12;
}
/* attackRoll: Inherited from the Character class. Generates two random numbers
between 1 and 6, representing a six sided dice. 

*/
void Barbarian::attackRoll()
{
	diceRoll1 = rand()%6 + 1;
	diceRoll2 = rand()%6 + 1;

	
}

/* defenseRoll: Inherited from the Character class. Generates two random numbers
between 1 and 6, representing a six sided dice.

*/
void Barbarian::defenseRoll()
{
	diceRoll1 = rand() % 6 + 1;
	diceRoll2 = rand() % 6 + 1;
}

/* printAttackDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the attack result. 

*/
void Barbarian::printAttackDiceRolls()
{
	//print the dice rolls. 
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;

	//set and print the attack total.
	attackTotal = diceRoll1 + diceRoll2;
	cout << "Attack total is: " << attackTotal << endl;

}
/* printDefenseDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the defense result.

*/
void Barbarian::printDefenseDiceRolls()
{
	//print the dice rolls. 
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;

	//set and print the attack total.
	defenseTotal = diceRoll1 + diceRoll2;
	cout << "Defense total is: " << defenseTotal << endl;

}
/* setDamageTake: calculates the total damage taken. takes one argument, the opponenet's 
total attack. 
*/
void Barbarian::setDamageTaken(int a)
{
	/* total damage is the attack, minus the defense dice rolls, minus the character's
	armor. As long as this total is above 0, the damage taken is set to that total. 
	If the total is negative, the damage take is set to 0. 
	*/
	if ((a - defenseTotal - armor) >= 0)
		damageTaken = a - defenseTotal - armor;
	else
		damageTaken = 0;

}

/* strengthCalc: deducts the damage taken from the character's strength. If the result of that calculation
is negative, the character's strength is set to 0. 
*/
void Barbarian::strengthCalc()
{
	if (damageTaken >= 0)
	{
		if (strengthPoints - damageTaken >= 0)
			strengthPoints -= damageTaken;
		else
			strengthPoints = 0;
	}
}