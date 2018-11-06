/* Name: Meghan Dougherty
   Date: 07/15/2018
   Description:
	


*/
#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	protected:
		int Age;
		int Cost;
		int numberOfBabies;
		int baseFoodCost = 10;
		double Payoff;


	public:
	
		Animal();
	
		int getAge();
		int getCost();
		int getNumberOfBabies();
		int getBaseFoodCost();
		int getPayoff();
		void getOlder();
	
	
	




};
#endif // !ANIMAL_H
