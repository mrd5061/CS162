/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/

#include "Tiger.hpp"

Tiger::Tiger()
{
	Age = 1;
	Cost = 10000;
	numberOfBabies = 1;
	feedingCost = 5*baseFoodCost;
	Payoff = Cost * 0.20;

	
}

Tiger::Tiger(int a)
{
	Age = a;
	Cost = 10000;
	numberOfBabies = 1;
	feedingCost = 5*baseFoodCost;
	Payoff = Cost * 0.20;


}
int Tiger::getFeedingCost()
{
	if (this != nullptr)
		return this->feedingCost;
	else
		return 0;
}