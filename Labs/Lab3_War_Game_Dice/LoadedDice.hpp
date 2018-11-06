/*
*Author: Meghan Dougherty
*Date: 07/10/2018
*Description:The declaration file for the Loaded Dice class. This class is a child of the Dice class
and inherits the Dice Class member variables. Contains two constructors and overloads the diceRoll
function inherited from the Dice Class. 
*/



#ifndef LOADED_DICE_H
#define LOADED_DICE_H
#include "Dice.hpp"


class LoadedDice : public Dice
{

public:

	LoadedDice();
	LoadedDice(int);
	int diceRoll();


};
#endif 
