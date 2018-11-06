/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function definition file for the Harry Potter class. Includes a constructor, and
various overrides of the inherited Character functions. Harry Potter does not have any unique functions, but does
implement a unique override of the strength Calc and a unique variable. 


*/

#include "HarryPotter.hpp"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/* BlueMen: Constructor. sets the dice roll and hogwartsBool variables to 0.
sets the strength points to 109 and the armor to 0.
*/
HarryPotter::HarryPotter()
{

	armor = 0;
	strengthPoints = 10;
	hogwartsBool = 0;
}

/* attackRoll: Inherited from the Character class. Generates two random numbers
between 1 and 6, representing a six sided dice.

*/
void HarryPotter::attackRoll()
{
	diceRoll1 = rand() % 6 + 1;
	diceRoll2 = rand() % 6 + 1;
	
}

/* defenseRoll: Inherited from the Character class. Generates two random numbers
between 1 and 6, representing a six sided dice.

*/
void HarryPotter::defenseRoll()
{
	diceRoll1 = rand() % 6 + 1;
	diceRoll2 = rand() % 6 + 1;
}

/* printAttackDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the attack result.

*/
void HarryPotter::printAttackDiceRolls()
{
	//print the dice rolls.
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;

	//total and print the attack result.
	attackTotal = diceRoll1 + diceRoll2;
	cout << "Attack total is: " << attackTotal;

}

/* printDefenseDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the defense result.

*/
void HarryPotter::printDefenseDiceRolls()
{
	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;

	defenseTotal = diceRoll1 + diceRoll2;
	cout << "Defense total is: " << defenseTotal;

}

/* setDamageTake: calculates the total damage taken. takes one argument, the opponenet's
total attack.
*/
void HarryPotter::setDamageTaken(int a)
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
is negative, the character's strength is set to 0. The first time the character's strength equals zero, the function
sets the strength to 20 to "revive" the character and sets the hogwartsBool to 1. 
*/
void HarryPotter::strengthCalc()
{
	//If the hogwartsBool is 0 (and this Harry Potter hasn't been revived)
	if (hogwartsBool == 0)
	{
		//If the character's points are 0 or less after the current attack, Harry is revived. 
		//and his strength is set to 20.
		if (strengthPoints - damageTaken <= 0)
		{
			strengthPoints = 20;
			//set to one to indicate that he's been revived once. 
			hogwartsBool = 1;
			cout << "Harry Potter has come back to life! He now has 20 strength points!" << endl;
		}
		//Otherwise, the calculation happens as normal.
		else
			strengthPoints -= damageTaken;
		
	}
	//If revival has already happened, damage calculation is normal. 
	if (hogwartsBool == 1)
	{
		if (damageTaken >= 0)
		{
			if (strengthPoints - damageTaken > 0)
				strengthPoints -= damageTaken;
			else
				strengthPoints = 0;
		}
	}
}