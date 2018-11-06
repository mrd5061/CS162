/*Author: Meghan Dougherty
Date:07/31/2018
Description:Description: The function definition file for the Blue Men class. Includes a constructor, and
various overrides of the inherited Character functions. Blue Men does not have any unique functions, but does
implement a unique override of the defense dice functions. 


*/


#include "BlueMen.hpp"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;


/* BlueMen: Constructor. sets the dice roll variables to 0.
sets the strength points to 12 and the armor to 3.
*/
BlueMen::BlueMen()
{
	diceRoll1 = 0;
	diceRoll2 = 0;
	diceRoll3 = 0;
	armor = 3;
	strengthPoints = 12;
}
/* attackRoll: Inherited from the Character class. Generates two random numbers
between 1 and 10, representing a 10 sided dice.

*/
void BlueMen::attackRoll()
{

	diceRoll1 = rand() % 10 + 1;
	diceRoll2 = rand() % 10 + 1;

	}
/* defenseRoll: Inheretied from the character Class. Implements
the mob function of the blue man. For every four strength points
lost, the Blue Men lose a defence dice. Generates between 1 and three 
random numbers between 1 and 6.

*/
void BlueMen::defenseRoll()
{
	if (strengthPoints >8)
	{

		diceRoll1 = rand() % 6 + 1;
		diceRoll2 = rand() % 6 + 1;
		diceRoll3 = rand() % 6 + 1;
	}
	else if (strengthPoints >4 && strengthPoints < 8 )
	{
		diceRoll1 = rand() % 6 + 1;
		diceRoll2 = rand() % 6 + 1;
		diceRoll3 = 0;
	}
	else if (strengthPoints <=4)
	{
		diceRoll1 = rand() % 6 + 1;
		diceRoll2 = 0;
		diceRoll3 = 0;
	}

}
/* printAttackDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the attack result.

*/
void BlueMen::printAttackDiceRolls()
{

	cout << "Dice Roll One is:" << diceRoll1 << endl;
	cout << "Dice Roll Two is:" << diceRoll2 << endl;
	attackTotal = diceRoll1 + diceRoll2;
	cout << "Attack total is: " << attackTotal;

}
/* printDefenseDiceRolls: Prints the results of the dice rolls
as well as totaling and printing the defense result. Implements
the mob function of the blue man. For every four strength points 
lost, the Blue Men lose a defence dice. 

*/
void BlueMen::printDefenseDiceRolls()
{
	//If strength points are between 8 and 12, the blue men have
	// 3 dice. 
	if (strengthPoints >= 8)
	{
		cout << "You have a full mob!" << endl;
		cout << "Dice Roll One is:" << diceRoll1 << endl;
		cout << "Dice Roll Two is:" << diceRoll2 << endl;
		cout << "Dice Roll Three is: " << diceRoll3 << endl;

		defenseTotal = diceRoll1 + diceRoll2 + diceRoll3;
		cout << "Defense total is: " << defenseTotal;
	}
	//If strength points are between 4 and 8 the blue men have
	// 2 dice. 
	if ( strengthPoints >4 && strengthPoints < 8)
	{
		cout << "You Lost One Blue Man!" << endl;
		cout << "Dice Roll One is:" << diceRoll1 << endl;
		cout << "Dice Roll Two is:" << diceRoll2 << endl;
		
		defenseTotal = diceRoll1 + diceRoll2 + diceRoll3;
		cout << "Defense total is: " << defenseTotal;
	}
	//If strength points are 4 or less, the Blue men have 1 dice. 
	if (strengthPoints <= 4)
	{
		cout << "Only One Blue Man Left!" << endl;
		cout << "Dice Roll One is:" << diceRoll1 << endl;
		cout << "Dice Roll Two is:" << diceRoll2 << endl;
		cout << "Dice Roll Three is: " << diceRoll3 << endl;

		defenseTotal = diceRoll1 + diceRoll2 + diceRoll3;
		cout << "Defense total is: " << defenseTotal;
	}

}
/* setDamageTake: calculates the total damage taken. takes one argument, the opponenet's
total attack.
*/
void BlueMen::setDamageTaken(int a)
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
void BlueMen::strengthCalc()
{
	if (damageTaken >= 0)
	{
		if (strengthPoints - damageTaken >= 0)
			strengthPoints -= damageTaken;
		else
			strengthPoints = 0;
	}
}