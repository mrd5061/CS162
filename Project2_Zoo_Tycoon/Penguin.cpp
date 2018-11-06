/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/

#include "Penguin.hpp"

Penguin::Penguin()
{
	Age = 1;
	Cost = 1000;
	numberOfBabies = 5;
	feedingCost= baseFoodCost;
	Payoff = Cost * 0.10;

}

Penguin::Penguin(int a)
{
	Age = a;
	Cost = 1000;
	numberOfBabies = 5;
	feedingCost = baseFoodCost;
	Payoff = Cost * 0.10;
		

}
int Penguin::getFeedingCost()
{
	if (this != nullptr)
		return this->feedingCost;
	else
		return 0;
}
