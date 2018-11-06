/*
*Author: Meghan Dougherty
*Date: 07/10/2018
*Description: The implementation file for the dice class. It contains two constructors (a default and a 
 custom), plus one member function inherited from the Dice class. 
*/
#include <cstdlib>

#include "LoadedDice.hpp"
#include "Dice.hpp"

//LoadedDice: Default Constructor. Sets the die's sides to 6.
LoadedDice::LoadedDice() 
{
	n = 6;

}

/* LoadedDice(int): Custom Constructor. Takes an integer n as an 
   argument and sets the objects number of sides to that integer. 
*/

LoadedDice::LoadedDice(int n)
{
	this->n = n;

}

/* diceRoll: Inherited from Dice Class and overloaded. Takes an integer n as an argument. 
   50% of the time will return a random number from the top 2 numbers of it's
   side range. Otherwise, it returns a random number from 
   1 to the number of sides. 
*/
int LoadedDice::diceRoll() 
{	
	int loaded = n - 1;

	if (rand() % 2 + 1 == 1)
		return (rand() %n + 1);
	else
		return (rand() %(n-loaded) + loaded);
}