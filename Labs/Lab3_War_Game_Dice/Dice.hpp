/*
*Author: Meghan Dougherty
*Date: 07/10/2018
*Description: The declaration file for the Dice class. It has one protected variable n,
* two constructors, and one member function.
*/

#ifndef DICE_H
#define DICE_H


class Dice
{
protected:
	int n; //Number of Sides of the Die 
	 
public: 
	
	Dice();
	Dice(int);
	
	virtual int diceRoll();
	
};
#endif 
