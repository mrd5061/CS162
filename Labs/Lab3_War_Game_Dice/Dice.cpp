/*
 *Author: Meghan Dougherty
 *Date: 07/10/2018
 *Description: The implementation file for the dice class. It contains two constructors (a default and a 
 custom), plus one member function. 
 */

#include <cstdlib>
#include "Dice.hpp"

//Dice(): Default Constructor. Sets the die's number of sides to 0.
Dice::Dice()
{
	n = 6;
}

/* Dice(int):This constructor takes an argument for a user inputted
   number of sides and sets the die's number of sides.*/
Dice::Dice(int n)
{
	this->n = n;

	


}

/* diceRoll: takes the die's number of sides as an argument and returns
   a random number from 1 to the die's number of sides. 
*/
int Dice::diceRoll()
{
	return (rand() % n + 1);
		
}
