/*Author: Meghan Dougherty
Date:07/31/2018
Description:The function definition file for the Medusa class. Includes a constructor, and
various overrides of the inherited Character functions. Medusa does not have any unique functions, but has a
unique implementation of the attack roll function.

*/

#include "Medusa.hpp"
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

/* Barbarian: Constructor. sets the dice roll variables to 0.
sets the strength points to 8 and armor to 3.
*/
Medusa::Medusa()
{
	diceRoll1 = 0;
	diceRoll2 = 0; 
	armor = 3;
	strengthPoints = 8;
}
/* attackRoll: Inherited from the Character class. Generates two random numbers
between 1 and 6, representing a six sided dice. If the total of these rolls is 12, 
the dice rolls are each set to 50. This is the implementation of the Glare ability, 
and the high dice rolls ensure that the defending character will be killed no matter 
what their armor or defense dice rolls are. Harry Potter is the only character that
can survive the glare ability, but he can only do so once. 

*/
void Medusa::attackRoll()
{
	diceRoll1 = rand() % 6 + 1;
	diceRoll2 = rand() % 6 + 1;

	//following for testing the glare attack.
	//diceRoll1 = 6;
	//diceRoll2 = 6;

	//If the dice rolls are 12, the glare ability is set.
	if (diceRoll1 + diceRoll2 == 12)
	{
		diceRoll1 = 50;
		diceRoll2 = 50;

		cout << "Medusa glared directly at her opponent, turning them to stone!" << endl;
		cout << endl;
	}
	
}

/* defenseRoll: Inherited from the Character class. Generates one random number
between 1 and 6, representing a six sided dice.

*/
void Medusa::defenseRoll()
{
	diceRoll1 = rand() % 6 + 1;
	
}

/* printAttackDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the attack result.

*/
void Medusa::printAttackDiceRolls()
{
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;

	attackTotal = diceRoll1 + diceRoll2;
	cout << "Attack total is: " << attackTotal;

}
/* printDefenseDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the defense result.

*/
void Medusa::printDefenseDiceRolls()
{
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	
	defenseTotal = diceRoll1;
	cout << "Defense total is: " << defenseTotal;

}
/* setDamageTake: calculates the total damage taken. takes one argument, the opponenet's
total attack.
*/
void Medusa::setDamageTaken(int a)
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
void Medusa::strengthCalc()
{
	if (damageTaken >= 0)
	{
		if (strengthPoints - damageTaken >= 0)
			strengthPoints -= damageTaken;
		else
			strengthPoints = 0;
	}
}