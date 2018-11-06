/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function definition file for the Vampire class. Includes a constructor, and
various overrides of the inherited Character functions. Vampire does not have any unique functions, but has
a unique implementation of the setDamageTaken function. 

*/

#include "Vampire.hpp"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/* Barbarian: Constructor. sets the dice roll variables to 0 and armor to 1.
sets the strength points to 18.
*/
Vampire::Vampire()
{
	diceRoll1 = 0;
	armor = 1;
	strengthPoints = 18;
}

/* attackRoll: Inherited from the Character class. Generates one random number
between 1 and 6, representing a twelve sided dice.

*/
void Vampire::attackRoll()
{
	diceRoll1 = rand() % 12 + 1;
		
}
/* defenseRoll: Inherited from the Character class. Generates one random number
between 1 and 6, representing a six sided dice.

*/
void Vampire::defenseRoll()
{
	diceRoll1 = rand() % 6 + 1;
	
}
/* printAttackDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the attack result.

*/
void Vampire::printAttackDiceRolls()
{
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	
	attackTotal = diceRoll1;
	cout << "Attack total is: " << attackTotal;

}
/* printDefenseDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the defense result.

*/
void Vampire::printDefenseDiceRolls()
{
	cout << "Dice Roll One is:" << diceRoll1 << endl;

	defenseTotal = diceRoll1;
	cout << "Defense total is: " << defenseTotal;

}
/* setDamageTake: calculates the total damage taken. takes one argument, the opponenet's
total attack. Implements the charm ability, which is a 50/50 chance the character will 
not take any damage from an opponents attack. 
*/
void Vampire::setDamageTaken(int a)
{
	//Random number, generates 50/50 chance. 
	charmBool = rand() % 2 + 1;
	
	//If 2, damage is normal.
	if (charmBool == 2)
	{
		if ((a - defenseTotal - armor) >= 0)
			damageTaken = a - defenseTotal - armor;
		else
			damageTaken = 0;
	}
	//if 1, charm is engaged! 
	else
	{
		cout << "The Vampire charmed his way out of the attack!" << endl;
		damageTaken = 0;
	}
		
}

/* strengthCalc: deducts the damage taken from the character's strength. If the result of that calculation
is negative, the character's strength is set to 0.
*/
void Vampire::strengthCalc()
{

	if (damageTaken >= 0)
	{
		if (strengthPoints - damageTaken >= 0)
			strengthPoints -= damageTaken;
		else
			strengthPoints = 0;
	}
}

