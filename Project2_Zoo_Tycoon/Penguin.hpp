/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/
#pragma once
#ifndef PEN_H
#define PEN_H
#include "Animal.hpp"

class Penguin : public Animal
{
	private:
		int feedingCost;
	
	
	public:
		Penguin();
		Penguin(int);

		int getFeedingCost();
		


};
#endif