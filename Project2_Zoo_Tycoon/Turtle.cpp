/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/

#include "Turtle.hpp"

Turtle::Turtle()
{
	Age = 1;
	Cost = 100;
	numberOfBabies = 10;
	feedingCost = baseFoodCost / 2;
	Payoff = Cost * 0.05;

}

Turtle::Turtle(int a)
{
	Age = a;
	Cost = 100;
	numberOfBabies = 10;
	feedingCost = baseFoodCost/2;
	Payoff = Cost * 0.05;


}

int Turtle::getFeedingCost()
{
	if (this != nullptr)
		return this->feedingCost;
	else
		return 0;
}
