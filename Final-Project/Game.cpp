/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Game class. This class implements functions and classes to create a playable escape game.

*/

#include "Game.hpp"
#include "Hallway.hpp"
#include "Ocean.hpp"
#include "Field.hpp"
#include "Kitchen.hpp"
#include "EscapePod.hpp"
#include "Repeat.hpp"
#include "Space.hpp"
#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

// Constructor. Sets custom space pointers to NULL. 
Game::Game()
{
	currentRoom = NULL;
	ocean = NULL;
	hallway = NULL;
	field = NULL;
	escapePod = NULL;
	repeatRoom = NULL;
	kitchen = NULL;

	
	input = " ";
}
// Destructor. De-allocates memory 
Game::~Game()
{
	delete currentRoom;
	delete ocean;
	delete hallway;
	delete field;
	delete escapePod;
	delete repeatRoom;
	delete kitchen;
}
/* startGame: Takes no arguments. Generates the intro text which states the player's objectives and introduces them to the world. 
also asks the player if they want to start the game. 
 */
int Game::startGame()
{
	//Intro text. 

	cout << "Welcome too the Black Hole Escape game." << endl;
	cout << endl << endl;
	cout << "You are an astronaut who wakes up in the middle of your ship with little memory" << endl;
	cout << "of how you got there. A quick look around is enough to tell you that something " << endl;
	cout << "isn't right. Your goal is to open the escape pod door and get off the ship." << endl;
	cout << "You'll need a few items, which are scattered throughout the ship." << endl << endl;;
	cout << "Be careful! The near by black hole has caused some strange things to appear." << endl;
	cout << "There's no timer, but you only have 100 health points and it seems like" << endl;
	cout << "everything's out to get you." << endl;
	cout << endl;
	cout << endl;
	cout << "Are you ready to begin?" << endl << endl;

	cout << "Choose 1 to start the game or 2 to quit." << endl;

	//get and validate data.
	getline(cin, input);

	while (!cin || input.length() > 1 || (input[0] < 49 || input[0]>50))
	{
		cout << "Invalid Input. \n Please Enter 1 or 2." << endl;
		getline(cin, input);
	}

	if (input[0] == '1')
	{
		
		currentRoom = hallway;
	
		return 1;
	}
	else
		return 2;
} 

/* makeBoard: Takes no arguments. Creates new rooms for the custom space pointers and sets the Up/Down/Left/Right spaces appropriately.
Map is: 
			Escape Pod
				|
		field - Hallway  - Ocean - Kitchen
				|
			Repeat Room

*/
void Game::makeBoard()
{
	//create the rooms.
	hallway = new Hallway;
	ocean = new Ocean;
	field = new Field;
	escapePod = new EscapePod;
	repeatRoom = new Repeat;
	kitchen = new Kitchen;

	//set the direction pointers.
	hallway->setUp(escapePod);
	hallway->setDown(repeatRoom);
	hallway->setLeft(field);
	hallway->setRight(ocean);
	
	ocean->setLeft(hallway);
	ocean->setRight(kitchen);
	
	field->setRight(hallway);

	escapePod->setDown(hallway);

	repeatRoom->setUp(hallway);
		
	kitchen->setLeft(ocean);
}
/* changeRooms: Takes a player pointer. Displays the current room and the rooms that are adjacent. Then gets the room the player
would like to 'move' to. If the player chooses a direction that is unavailable in their current room, an error message is displayed
and the user re-chooses.
*/
void Game::changeRooms(Player* temp)
{
	//If the current room is the hallway, and the visited bool is set to false, display 
	//the first time in function for the hallway. 
	if (currentRoom->getRoomName() == "Hallway" && !(currentRoom->getVisited()))
	{
		currentRoom->firstTimeIn(temp);
	}

	//Otherwise, display the current room.
	cout << endl;
	cout << endl;
	cout << "You are currently in the " << currentRoom->getRoomName() << " ." << endl;
	
	//Display what is adjacent to the current room.
	if ((currentRoom->getUp()) != NULL)
	{
		cout << "Ahead of you is the " << (currentRoom->getUp())->getRoomName() << "." << endl;
	}

	if (currentRoom->getDown() != NULL)
	{
		cout << "Behind you is the " << (currentRoom->getDown())->getRoomName() << "." << endl;
	}

	if (currentRoom->getLeft() != NULL)
	{
		cout << "Left of you is the " << (currentRoom->getLeft())->getRoomName() << "." << endl;
	}

	if (currentRoom->getRight() != NULL)
	{
		cout << "Right of you is the " << (currentRoom->getRight())->getRoomName() << "." << endl;
		
	}

	//Ask for input and validate. 
	cout << "Where would you like to go? U/D/L/R" << endl;
	
	getline(cin, input);

	while (!cin || input.length() > 1 || !(toupper(input[0]) == 'U' || toupper(input[0]) == 'D' || toupper(input[0]) == 'L' || toupper(input[0]) == 'R'))
	{
		cout << "Invalid input. Please enter U, D, L, or R." << endl;
		getline(cin, input);
	}
	cout << endl;
	cout << endl;
	//The following displays the rooms based on user input. Choses which function to implement 
	//based on whether or not the player has already visited that room.
	if (toupper(input[0]) == 'U' && currentRoom->getUp() != NULL)
	{
		currentRoom = currentRoom->getUp();

		if(currentRoom->getVisited())
			currentRoom->nextTimeIn(temp);
		else
			currentRoom->firstTimeIn(temp);
		
	}


	else if (toupper(input[0]) == 'D' && currentRoom->getDown() != NULL)
	{
		currentRoom = currentRoom->getDown();

		if (currentRoom->getVisited())
			currentRoom->nextTimeIn(temp);
		else
			currentRoom->firstTimeIn(temp);

	}


	else if (toupper(input[0]) == 'L' && currentRoom->getLeft() != NULL)
	{
		currentRoom = currentRoom->getLeft();

		if (currentRoom->getVisited())
			currentRoom->nextTimeIn(temp);
		else
			currentRoom->firstTimeIn(temp);

	}


	else if (toupper(input[0]) == 'R' && currentRoom->getRight() != NULL)
	{
		currentRoom = currentRoom->getRight();

		if (currentRoom->getVisited())
			currentRoom->nextTimeIn(temp);
		else
			currentRoom->firstTimeIn(temp);

	}

	//Error Message.
	else
	{
		cout << "You can't go that direction." << endl;
		cout << "Make another selection." << endl;

		//re-run the function.
		changeRooms(temp);
	}



}

Space* Game::getCurrentRoom()
{
	return currentRoom;
}

void Game::printFinalMessage(Player* temp)
{
	if (temp->getHealth() <= 0)
	{
		cout << endl;
		cout << endl;
		cout << "Your vision begins to fade and you suddenly feel very weak." << endl;
		cout << "Game Over." << endl;
	}

	else
	{
	
		cout << "You step into the airlock and close your eyes as outer door slides open." << endl;
		cout << "Shift your weight and hear the letter crinckle in your pocket. You remember" << endl;
		cout << "What it says so clearly you don't need to read it. Your grandfather gave it to" << endl;
		cout << "right before he died. He told you how proud of you he was, that he loved ou, and" << endl;
		cout << "how profoundly sorry he was for what happend when you were young. He knew that," << endl;
		cout << "unlike him you would aways make the right choices in life." << endl;
		cout << "Now you have the chance to prove him right." << endl << endl;
		cout << "You open your eyes and the space in front of you is filled with stars. That" << endl; 
		cout << "was one thing you never quite expected. You thought black holes would be dead," << endl;
		cout << "dark spaces. You tear your eyes away and focus on the pod. All you need to do" << endl;
		cout << "is take a wrench to to the docking latch and the pod should detach. You're not" << endl;
		cout << "quite sure what will happen after that, but there's nothing else to do now." << endl << endl;

		cout << " You pull yourself around the pod and grasp onto a part of the main ship. With" << endl;
		cout << "your other hand, you pull the wrench out of your suit pocket." << endl;
		cout << " You take a deep breath, place and turn the wrench. The pod detaches easily." << endl;
		cout << " Suddenly, time seems to start up again. You flatten yourself to the ship as the pod's" << endl;
		cout << "thrusters fire up. In the blink of an eye, the pod is gone." << endl << endl;
		cout << " You had expected to cry, but you only feel strangely at peace." << endl;
		cout << "You wish the crew good luck as you let go of the ship and drift toward the black hole." << endl << endl << endl;
		

		cout << "Congratulations. You escaped the pod." << endl;

	}

}