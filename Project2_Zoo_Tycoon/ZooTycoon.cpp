// Project 2.cpp : Defines the entry point for the console application.
//

#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>
#include <stdlib.h>   
#include <string>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::atoi;


int main()
{
	//seed the random number generator.
	srand(static_cast<unsigned int>(time(NULL)));

	//create necessary variables for the menu functions
	int animalChoice;
	char yesOrNo;
	int penguinNum=0;
	int tigerNum=0;
	int turtleNum=0;
	string input;

	//Create the Zoo Object.
	Zoo playerZoo;

	//Couter to keep track of # of days.	
	 int counter = 1;

	//Give a short intro to the game and explain the initial purchasing of animals. 
	cout << "Congratulations! You just became the proud owner of the CS 162 Zoo!" << endl;
	cout << "You have a starting budget of: " << playerZoo.getBankBalance() << endl << endl;
	cout << "To get your zoo started, you will need to purchase some animals!" << endl << endl;
	cout << "You have three options:" << endl << endl;
	cout << "*** Tigers ***" << endl;
	cout << "They cost 10,000, have one baby at a time, are  expensive to feed, but their daily payoff is highest" << endl << endl;
	cout << "*** Penguins ***" << endl; 
	cout << "They cost $1,000, have five babies at a time, cost the average amount to feed, and their daily payoff is average" << endl << endl;
	cout << "*** Turtles ***" << endl;
	cout << "They cost $100, have ten babies at a time, cost the least amount to feed, but their daily payoff is low." << endl << endl;
	
	cout << "Please choose either 1 or 2 animals from each type of animal to begin." << endl;
	cout << "You will have the option to buy one adult animal at the end of each day." << endl;
	cout << endl;
	
	//Get and validate the amount of tigers.
	cout << "How many Tigers do you want to purchase?" << endl;

	getline(cin, input);

	if (input.length()==1 && isdigit(input[0]))
		tigerNum = input[0]-48;
	else
		tigerNum=-1;

	while (!cin || tigerNum < 1 || tigerNum >2)
	{
		cout << "Invalid Input. Please enter either 1 or two with no leading 0's" << endl;
		getline(cin, input);

		if (input.length()==1 && isdigit (input[0]))
			tigerNum = input[0]-48;
		else
			tigerNum=-1;


	}
	
	//Get and validate the amount of penguins.
	cout << "How many penguins do you want to purchase?" << endl;

	getline(cin, input);
	if(input.length() == 1 && isdigit(input[0]))
		penguinNum = input[0]-48;
	else
		penguinNum = -1;
	

	while (!cin || penguinNum < 1 || penguinNum >2)
	{
		cout << "Invalid Input. Please enter either 1 or two with no leading 0's" << endl;
		getline(cin, input);
		if(input.length() == 1 && isdigit(input[0]))
			penguinNum = input[0]-48;
		else
			penguinNum = -1;
	
		
	}


	//Get and validate the amount of turtles. 
	cout << "How many Turtles do you want to purchase?" << endl;

	getline(cin, input);

	if(input.length()==1 && isdigit(input[0]))
		turtleNum = input[0]-48 ;
	else
		turtleNum = -1;
	
	while (!cin || turtleNum < 1 || turtleNum >2)
	{
		cout << "Invalid Input. Please enter either 1 or two with no leading 0's" << endl;
		getline(cin, input);
		if(input.length()== 1 && isdigit(input[0]))

			turtleNum =input[0]-48 ;
		else
			turtleNum = -1;
	

	}
	
	//create the purchased animals. 
	
	playerZoo.penguinBuy(penguinNum, 1);
	
	playerZoo.tigerBuy(tigerNum, 1);
	
	playerZoo.turtleBuy(turtleNum,1);
	
		
	cout << "After Purchasing your animals, you have " << playerZoo.getBankBalance() << " dollars left in your account." << endl;
	cout << endl;
	cout << endl;

	//Start the daily program
	cout << "Day " << counter << ":" << endl;

	playerZoo.dailyProgram(&playerZoo);
	
	//Continue the daily program either until user quits or goes bankrupt.
	while (playerZoo.getBankBalance() >= 0)
	{
		counter++;

		//Ask then validate if the user would like another adult animal.
		cout << "Would you like to buy another adult animal? Y/N" << endl;
		getline(cin, input);
		
		if (input.length() == 1)
			yesOrNo = toupper(input[0]);
		else
			yesOrNo = 'a';



		while (!cin || !(yesOrNo == toupper('y') || yesOrNo == toupper('n')))
		{
			cout << "Invalid Input" << endl;
			cout << "Enter Y to buy another animal or N to continue." << endl;
			getline(cin, input);

			if (input.length() == 1)
				yesOrNo = toupper(input[0]);
			else
				yesOrNo = 'a';
		}
		//If yes, ask and validate which animal.
		if (yesOrNo =='Y')
		{
			cout << "Which animal would you like to buy?" << endl;
			cout << "Enter 1 for Tiger, 2 for Penguin, or 3 for Turtle." << endl;
			getline(cin, input);
			animalChoice = atoi(input.c_str());

			while (!cin || isalpha(animalChoice)|| animalChoice <1 || animalChoice > 3)
			{
				cout << "Invalid Input" << endl;
				cout << "Enter 1 for Tiger, 2 for Penguin, or 3 for Turtle." << endl;
				getline(cin, input);
				animalChoice = atoi(input.c_str());
			}

			if (animalChoice == 1)
				playerZoo.tigerBuy(1, 2);
			else if (animalChoice == 2)

				playerZoo.penguinBuy(1, 2);
			else
				playerZoo.turtleBuy(1, 2);

		}

		//Ask and validate if the user would like to play another day or quit. 
		cout << "Would you like to play another day or quit?" << endl;
		cout << "Enter P to continue or Q to quit." << endl;

		getline(cin, input);

		if (input.length() == 1)
			yesOrNo = toupper(input[0]);
		else
			yesOrNo = 'a';
		
		while (!cin || !(yesOrNo == toupper('p') || yesOrNo == toupper('q')))
		{
			cout << "Invalid Input" << endl;
			cout << "Enter P to continue or Q to quit." << endl;
			getline(cin, input);
			if (input.length() == 1)
				yesOrNo = toupper(input[0]);
			else
				yesOrNo = 'a';
		}

		if (toupper(yesOrNo) == 'P')
		{
			cout << "Day " << counter << ":" << endl;
			playerZoo.dailyProgram(&playerZoo);
		}
		else
		{
			playerZoo.quit();
			return 0;
		}
	}
	
	//If the user goes bankrupt, quit the game. 
		cout << "You ran out of money!" << endl;

		cout << "Game Over!" << endl;
		playerZoo.quit();

    return 0;
}

