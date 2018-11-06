/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/
#pragma once
#ifndef TIG_H
#define TIG_H

#include "Animal.hpp"

class Tiger : public Animal
{

	
private:
	int feedingCost;


public:
	Tiger();
	Tiger(int);

	int getFeedingCost();
	

};
#endif // !TIG_H