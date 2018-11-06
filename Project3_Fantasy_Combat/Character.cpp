/*Author: Meghan Dougherty
Date:07/31/2018
Description: Function definition file for the Character class. Consists of the concrete member functions, which are getters and setters 
for the Character variables. 

*/



#include "Character.hpp"

// Character: Generic constructor. Sets all member variables to 0. 

baseCharacter::baseCharacter()
{
	diceRoll1 = 0;
	diceRoll2 = 0;
	diceRoll3 = 0;
	armor = 0;
	strengthPoints = 0;
}

//The following 8 functions are getters that return the appropriate member variables

int baseCharacter::getArmor()
{
	return armor;
}
int baseCharacter::getStrengthPoints()
{
	return strengthPoints;
}
int baseCharacter::getDiceRoll1()
{
	return diceRoll1;
}
int baseCharacter::getDiceRoll2()
{
	return diceRoll2;
}
int  baseCharacter::getDiceRoll3()
{
	return diceRoll3;
}

int baseCharacter::getAttackTotal()
{
	return attackTotal;
}

int baseCharacter::getDefenseTotal()
{
	return defenseTotal;
}

int baseCharacter::getDamageTaken()
{
	return damageTaken;
}

//The following 5 functions are setters for their appropriate member variables. They all take
// one integer as their arguments. 

void baseCharacter::setArmor(int a)
{
	armor = a;
}
void baseCharacter::setStrengthPoints(int s)
{
	strengthPoints = s;
}
void baseCharacter::setDiceRoll1(int r)
{
	diceRoll1 = r;
}
void  baseCharacter::setDiceRoll2(int r)
{
	diceRoll2 = r;
}
void  baseCharacter::setDiceRoll3(int r)
{

	diceRoll3 = r;
}

