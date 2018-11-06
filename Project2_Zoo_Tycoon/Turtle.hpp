/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/
#pragma once
#ifndef TURT_H
#define TURT_H


#include "Animal.hpp"

class Turtle : public Animal
{
private:
	int feedingCost;
	
public:
	Turtle();
	Turtle(int);
	int getFeedingCost();
	
};
#endif // !TURT_H