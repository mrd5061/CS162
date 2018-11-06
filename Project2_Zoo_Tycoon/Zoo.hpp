/* Name: Meghan Dougherty
Date: 07/15/2018
Description:



*/
#pragma once
#ifndef ZOO_H
#define ZOO_H


#include "Penguin.hpp"
#include"Tiger.hpp"
#include"Turtle.hpp"

class Zoo
{
private:
	Penguin** penguinArray;
	Tiger** tigerArray;
	Turtle** turtleArray;

	int penguinArraySize = 10;
	int tigerArraySize = 10;
	int turtleArraySize = 10;

	int animalType;
	int totalPenguins;
	int totalTigers;
	int totalTurtles;

	int bankBalance;
	int totalDailyPayoff;
	int totalFeedingCost;
	int bonus;

	int choice1;
	int choice2;
	

public:

	Zoo();


	int getTotalPenguins();
	int getTotalTigers();
	int getTotalTurtles();

	void penguinBuy(int, int);
	void tigerBuy(int, int);
	void turtleBuy(int, int);

	int animalDies(int);
	int animalBorn(int c);
	int tigerBonus();
	
	int getBankBalance();
	void setBankBalance(int);
	int getTotalDailyPayoff();


	int getTotalFeedingCost();
	void deductCost();
	void dailyProgram(Zoo* ptr);
	
	void quit();
	
};

#endif // !ZOO_H
