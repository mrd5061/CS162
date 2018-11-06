/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>
using std::cout;
using std::endl;
using std::string;

#include "Penguin.hpp"
#include"Tiger.hpp"
#include"Turtle.hpp"
#include "Zoo.hpp"



Zoo::Zoo()
{
	bankBalance = 100000;
	totalDailyPayoff = 0;

	penguinArray = new Penguin*[10];
	tigerArray = new Tiger*[10];
	turtleArray = new Turtle*[10];

	for (int i = 0 ; i <10; i++)
	{
		penguinArray[i] = nullptr;
		tigerArray[i] = nullptr;
		turtleArray[i] = nullptr;
	}


	totalPenguins = 0;
	totalTigers = 0;
	totalTurtles = 0;

	penguinArraySize = 10;
	tigerArraySize = 10;
	turtleArraySize = 10;


}


int Zoo::getTotalPenguins()
{
	return totalPenguins;
}

int Zoo::getTotalTigers()
{
	return totalTigers;
}

int Zoo::getTotalTurtles()
{
	return totalTurtles;
}
/* penguinBuy: Takes an integer p as an argument. Increases the number of penguins in the zoo by
p. If the array is too small to fit the new animals, the function doubles the array size and 
re-allocates the existing members. This function works exactly the same as the other animal 
buys. Reference here for function comments for tigerBuy and penguinBuy.

*/
void Zoo::penguinBuy(int p, int q)
{
		
	//If the total penguins plus new penguins will fit in the penguin array.
	if ((totalPenguins + p) <= penguinArraySize)
	{
			
		//If the penguin array isn't empty.
		if (penguinArray[0] != NULL)
		{
			//adjust where the existing penguins are.
			for (int i = 0; i <penguinArraySize; i++)
			{
				penguinArray[i + (p-1)] = penguinArray[i];
				

			}
			//add the new penguins to the front of the array.
			for (int i = 0; i < p; i++)
			{
				//Baby penguin option
				if (q == 1)
				
					penguinArray[i] = new Penguin();
				
				//adult penguin option.
				if (q == 2)
					penguinArray[i] = new Penguin(3);
			}
		}
		//If the array is empty
		else
		{
			//add the penguins
			for (int i = 0; i < p; i++)
			{
				//baby penguin option.
				if (q == 1)
				{
				
					penguinArray[i] = new Penguin();
					
				}
				//adult penguin option. 
				if (q == 2)
					penguinArray[i] = new Penguin(3);
			}
		}
	}
	//if the penguins won't fit in the array.
	else
	{
		
		//create a placeholder array that is double the size.
		int newArraySize = penguinArraySize * 2;
		
		Penguin ** tempArray = new Penguin* [newArraySize];

		for (int i = 0; i < newArraySize; i++)
		{
			tempArray[i] = nullptr;
		}
		//Add the existing penguins to the new array.
		for (int i = 0; i <penguinArraySize; i++)
		{
			
			tempArray[i] = penguinArray[i];
			

			
		}
		//add the new penguins. 
		for (int i = totalPenguins-1; i < totalPenguins + p; i++)
		{
			
			if (q == 1)
				tempArray[i+p] = new Penguin();
			if (q == 2)
				tempArray[i+p] = new Penguin(3);
		}
		

				
				
		//adjust the penguin array size.
		
	
		delete [] penguinArray;
		
		//assign the penguin array to the new array.
		penguinArray = tempArray;
		penguinArraySize = newArraySize;

		//delete the temp array. 
		for (int i = 0; i < penguinArraySize; i++)
		{
			delete tempArray[i];
		}
		delete[] tempArray;
		
		

	}
	
	//Update the total penguins.
	totalPenguins += p;
	
	//update the bank balance.
	bankBalance -= p * 1000;
	
	
}

/* tigerBuy: Takes an integer t as an argument. Increases the number of tigers in the zoo by
p. If the array is too small to fit the new animals, the function doubles the array size and
re-allocates the existing members. Reference penguinBuy for specific function comments. 

*/
void Zoo::tigerBuy(int t, int q)
{
	
	
	if ((totalTigers + t) <= tigerArraySize)
	{

		if (tigerArray[0] != NULL)
		{

			for (int i = 0; i <tigerArraySize; i++)
			{
				tigerArray[i + (t-1)] = tigerArray[i];

			}
			for (int i = 0; i < t; i++)
			{
				if (q == 1)
					tigerArray[i] = new Tiger();
				if (q == 2)
					tigerArray[i] = new Tiger(3);
			}
		}

		else
		{

			for (int i = 0; i < t; i++)
			{

				if (q == 1)
				{

					tigerArray[i] = new Tiger();

				}
				if (q == 2)
					tigerArray[i] = new Tiger(3);
			}
		}
	}
	else
	{


		int newArraySize = tigerArraySize * 2;


		Tiger ** tempArray = new Tiger* [newArraySize];

		for (int i = 0; i < newArraySize; i++)
		{
			tempArray[i] = nullptr;
		}

		for (int i = 0; i <tigerArraySize; i++)
		{

			tempArray[i] = tigerArray[i];
			tigerArray[i] = nullptr;


		}

		for (int i = totalTigers - 1; i < totalTigers + t; i++)
		{

			if (q == 1)
				tempArray[i+t] = new Tiger();
			if (q == 2)
				tempArray[i+t] = new Tiger(3);
		}

		for (int i = 0; i < tigerArraySize; i++)
		{
			delete tigerArray[i];
		}


		delete[] tigerArray;

		tigerArraySize = newArraySize;

		for (int i = 0; i < tigerArraySize; i++)
		{
			delete tempArray[i];
		}
		delete[] tempArray;

		tigerArray = tempArray;


		



	}
	
	totalTigers = totalTigers + t;

	
	bankBalance -= t * 1000;


}

/* turtleBuy: Takes an integer p as an argument. Increases the number of turtles in the zoo by
p. If the array is too small to fit the new animals, the function doubles the array size and
re-allocates the existing members. Reference penguinBuy for specific function comments. 
*/

void Zoo::turtleBuy(int t, int q)
{
	
	if (totalTurtles + t < turtleArraySize)
	{
		if (this->turtleArray[0] != NULL)
		{
			for (int i = 0; i <  turtleArraySize; i++)
			{
				turtleArray[i + (t-1)] = turtleArray[i];

			}
			for (int i = 0; i < t; i++)
			{
				if (q==1)
					turtleArray[i] = new Turtle();
				if (q==2)
					turtleArray[i] = new Turtle(3);
			}
		}

		else
		{
			for (int i = 0; i < t; i++)
			{
				if (q == 1)
					turtleArray[i] = new Turtle();
				if (q == 2)
					turtleArray[i] = new Turtle(3);
			}
		}
	}
	else
	{
		int newArraySize = turtleArraySize * 2;

		Turtle** tempArray = new Turtle*[newArraySize];
		
		for (int i = 0; i <  turtleArraySize; i++)
		{
			tempArray[i+t] = turtleArray[i];

			if (q == 1)
				tempArray[i] = new Turtle();
			if (q == 2)
				tempArray[i] = new Turtle(3);
			
		}
		
		turtleArraySize = newArraySize;

		delete[] turtleArray;

		turtleArray = tempArray;
				
		delete[]tempArray;

	}

	totalTurtles += t;
	//bankBalance -= t * (turtleArray[0]->getCost());
}

/* animalBorn: takes an integer c (either 1, 2, or 3) and uses c to decide which animal type
is giving birth. The function then checks through the type array to see if any animals are adults
(able to give birth). When the loop finds an adult animal, it calls the approriate buy function and
passes the number of babies (1, 5, 10) to the buy function and returns a true value. If no animals
are adults, the function returns a false value. 
*/


int Zoo :: animalBorn(int c)
{
	//Penguins are choice 1. All animalBorn options work the same. 
	if (c == 1)
	{
		//check for adult animals.
		for (int i = 0; i < penguinArraySize; i++)
		{
			//check if there are any penguins (if the first penguin pointer has a value.)
			if (penguinArray[i] != NULL)
			{
				//If an adult animal is found, create the babies. 
				if (penguinArray[i]->getAge() >= 3)
				{				
				
					penguinBuy(5, 1);
					
					return 1;
				}
			}
			//otherwise, return false.
			else 
				return 0;

		}
		//otherwise, return false.
		return 0;

	}
	if (c == 2)
	{
		
		for (int i = 0; i < tigerArraySize; i++)
		{
			if (tigerArray[i] != NULL)
			{
				if (tigerArray[i]->getAge() >= 3)
				{
					tigerBuy(1, 1);
					return 1;
				}
			}
			else
				return 0;
		}
		return 0;

		
	}
	if (c == 3)
	{
		for (int i = 0; i < turtleArraySize; i++)
		{
			if (turtleArray[i] != NULL)
			{
				if (turtleArray[i]->getAge() >= 3)
				{
					turtleBuy(10, 1);
					return 1;
				}
			}
			else
				return 0;
		}
		return 0;

		
	}

}

/* animalDies: takes no arguments. Chooses a random number from 1 to 3 to choose which type of animal 
will die. The function then chooses a random animal within the appropriate array to die and adjusts the
indices of the remaining animals accordingly. 
*/
int Zoo::animalDies(int randAn)
{
	//random animal pointer.
	int randP = 0;

	//All animal Dies options work the same. 
	//If the random animal is a penguin and there are penguins.
	if (randAn = 1 &&  totalPenguins > 0)
	{
		//Generate random number in the penguin array.
		randP = rand() % totalPenguins;
		//If a penguin is found
		if (penguinArray[randP] != nullptr)
		{
			//Kill the penguin and readjust the array.
			for (int i = randP; i < totalPenguins; i++)
			{
				penguinArray[i] = penguinArray[i + 1];

			}
			//decrease the total penguins
			totalPenguins--;
			//inform the user. 
			cout << "One of your Penguins has died!" << endl;
			return 1;
		}
		
	}
	else
	{
		cout << "The grim reaper visited your zoo looking for a tiger. Thankfully you don't have any." << endl;
		return 0;
	}



	if (randAn = 2 && totalTigers > 0)
	{
		randP = rand() % totalTigers;

		if (tigerArray[randP] != nullptr)
		{
			for (int i = randP; i < totalTigers; i++)
			{
				tigerArray[i] = tigerArray[i + 1];
			}
			totalTigers--;
			cout << "One of your Tigers has died!" << endl;
			return 2;
		}
		
	}
	else
	{
		cout << "The grim reaper visited your zoo looking for a tiger. Thankfully you don't have any." << endl;
		return 0;
	}

	if (randAn = 3 && totalTurtles >0)
	{
		
		randP = rand() % totalTurtles;
		
		if (turtleArray[randP] != nullptr)
		{
			for (int i = randP; i < totalTurtles ; i++)
			{
				turtleArray[i] = turtleArray[i + 1];

			}
			totalTurtles--;
			cout << "One of your turtles has died!" << endl;
			return 3;
		}
		
	}
	else
	{
		cout << "The grim reaper visited your zoo looking for a turtle. Thankfully you don't have any." << endl;
		return 0;
	}
}


/* tigerBonus: takes no arguments. Random event in the zoo where an extra payoff bonus is 
added to the total daily payoff. The amount of the bonus is based on the number of tigers
in the zoo
*/
int Zoo::tigerBonus()
{
	//Random bonus amount.
	int bonus = rand() % 250 + 250;

	//add the bonus to the daily payoff
	totalDailyPayoff += (totalTigers * bonus); 
	
	//return the bonus so the game can report it to the user.
	return bonus;

}


/*getBankBalance: takes no arguments. return the amount of money in the bank. 
*/
int Zoo::getBankBalance()
{
	return bankBalance;

}
/* getTotalDailyPayoff: takes no arguments. Calculates and return the total daily payoff. 
*/
void Zoo::setBankBalance(int n)
{
	bankBalance = n;
}
/* getTotalDailyPayoff: takes no arguments. Calculates and return the total daily payoff.
*/
int Zoo::getTotalDailyPayoff()
{
	
	if (penguinArray[0] != NULL)
	{
		for (int i = 0; i < totalPenguins; i++)
		{
			if (penguinArray[i] != nullptr)
				totalDailyPayoff += penguinArray[i]->getPayoff();
		}
	}

	if (tigerArray[0] != NULL)
	{
		for (int i = 0; i < totalTigers; i++)
		{
			if (tigerArray[i] != nullptr)
				totalDailyPayoff += tigerArray[i]->getPayoff();
		}
	}

	if (turtleArray[0] != nullptr)
	{
		for (int i = 0; i < totalTurtles; i++)
		{
			if (turtleArray[i] != nullptr)
				totalDailyPayoff += turtleArray[i]->getPayoff();
		}
	}
	return totalDailyPayoff;

}
/* getTotalDailyPayoff: takes no arguments. Calculates and return the total feeding cost. 
*/

int Zoo::getTotalFeedingCost()
{
	totalFeedingCost = 0;

	if (penguinArray[0] != nullptr)
	{
		for (int i = 0; i < totalPenguins; i++)
		{
			if (penguinArray[i] != NULL)
				totalFeedingCost += penguinArray[i]->getFeedingCost();
			
		}
	}

	if (tigerArray[0] != nullptr)
	{
		for (int i = 0; i < totalTigers; i++)
		{
			if (tigerArray[i] != NULL)
				totalFeedingCost += tigerArray[i]->getFeedingCost();
			
		}
	}

	if (turtleArray[0] != nullptr)
	{
		for (int i = 0; i < totalTurtles; i++)
		{
			if(turtleArray[i]!= NULL)
				totalFeedingCost += turtleArray[i]->getFeedingCost();
		}
	}
	return totalFeedingCost;

}
void Zoo::deductCost()
{	
	int purchaseCost = (totalTigers*tigerArray[0]->getCost()) + (totalPenguins*penguinArray[0]->getCost()) + (totalTurtles*turtleArray[0]->getCost());
	bankBalance -= purchaseCost;

}
void Zoo::dailyProgram(Zoo* ptr)
{
	


	
	//Choose the random action for the day.
	choice1 = rand() %4 +1 ;
	
	//Choose the animal affected (only valid for birth and death.)
	choice2 = rand() %3 + 1;
	
	string animalName;
	

	if (choice2 == 1)
		animalName = "Penguin";
	if (choice2 == 2)
		animalName = "Tiger";
	if (choice2 == 3)
		animalName = "Turtle";
	
	switch (choice1)
	{
	case 1:
		ptr->animalDies(choice2);
	
		break;
	case 2:
		if (ptr->animalBorn(choice2)==1)
		{
			cout << "Contragulations! One of your " << animalName << " has given birth!" << endl;
			break;
		}
		else
		{
			cout << "Looks like the stork was all set to visit your zoo, but none of your "<< animalName << " is old enough to give birth. Oh well. " << endl;
			break;
		}
	case 3:
		
		if (totalTigers > 0)
		{
			bonus = ptr->tigerBonus();
			cout << "Today is National Tiger Day! Tigers generate money today! You made: " << bonus << " extra dollars for each tiger you own" << endl;
			break;
		}
		else
		{
			cout << "Today is National Tiger Day! Tigers generate money today! Unfortunately, you don't own any tigers and so didn't recieve a bonus!" << endl;
			break;
		}
	case 4:
		cout << "Today was uneventful." << endl;
		break;


	}
	
	
	//Add the daily payoff
	ptr->setBankBalance(bonus + (ptr->getBankBalance()) + (ptr->getTotalDailyPayoff()));
	//Deduct the feeding cost.
	ptr->setBankBalance(ptr->getBankBalance() - (ptr->getTotalFeedingCost()));
	

	//Increase the animal's age

	for (int i = 0; i < totalPenguins; i++)
		if (penguinArray[i] != NULL)
			penguinArray[i]->getOlder();
	for (int i = 0; i < totalTigers; i++)
		if (tigerArray[i] != NULL)
			tigerArray[i]->getOlder();
	for (int i = 0; i <totalTurtles; i++)
		if (turtleArray[i] != NULL)
			turtleArray[i]->getOlder();

	
	cout << "Your profit from your zoo animals was: " << ptr->getTotalDailyPayoff() << endl;
	cout << "Your total feeding cost was: " << ptr->getTotalFeedingCost() << endl;
	cout << "Your bank account balance is: " << ptr->getBankBalance() << endl;
	cout << "You have " << totalTigers << " Tigers, " << totalPenguins << " Penguins, and " << totalTurtles << " Turtles." << endl;

	//reset the tiger bonus and total Daily Feeding Cost.. 
	bonus = 0;
	

}

void Zoo::quit()
{
	cout << "Thank you for playing Zoo Tycoon!" << endl;

	for (int i = 0; i < penguinArraySize; i++)
	{
		delete penguinArray[i];
	}

	for (int i = 0; i < tigerArraySize; i++)
	{
		delete tigerArray[i];
	}
	for (int i = 0; i < turtleArraySize; i++)
	{
		delete turtleArray[i];
	}

	delete [] penguinArray;
	delete [] tigerArray;
	delete [] turtleArray;
}

