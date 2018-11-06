/* Name: Meghan Dougherty
Date: 07/15/2018
Description: 



*/
#include "Animal.hpp"

/*
	Animal: constructor for the animal Class. Only initializes the base food cost. 
*/
Animal::Animal()
{
	baseFoodCost = 10;
}
	
//The following are getters and setters for the Animal Class variables. 

int Animal :: getAge()
{
	return this ->Age;
}
int Animal::getCost()
{
	return this->Cost;
}
int Animal::getNumberOfBabies()
{
	return this ->numberOfBabies;
}
int Animal::getBaseFoodCost()
{
	return this ->baseFoodCost;
}
int Animal::getPayoff()
{
	return this->Payoff;
}

void Animal::getOlder()
{
	Age ++;
}



