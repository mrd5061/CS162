/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Hallway class. A public copy of the Space Class. Does not contain any unique functions.
*/


#include "Hallway.hpp"
#include <iostream>
#include <string>
#include <stdlib.h> 

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor. 
Hallway::Hallway()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = "Hallway";
}

/*firstTimeIn: Takes a player pointer. Displays text that describes the room. Allows the user to explore or move on.
*/
void Hallway::firstTimeIn(Player* temp)
{
	//Set the visited to true first since this is the room the player starts in
	visited = true;
	
	cout << "You wake up and feel cold, sharp metal pressed against your cheek. Sirens are " << endl;
	cout << "blaring loudly, and you see flashing red lights when you open your eyes." << endl;
	cout << "For a second you wonder where you are, but then all of the memories come" << endl;
	cout << "flooding back. The months of training. The flight simulators. The fear and" << endl;
	cout << "nerves when the rockets started at takeoff. You and the rest of your five" << endl;
	cout << "person crew was sent out into deep space to study a black hole almost a year" << endl;
	cout << "ago.You seem to remeber everything up to, presumably, the last meal you ate." << endl;
	cout << "Afer that, nothing. You're not even sure how you ended up in the hallway." << endl << endl;
	cout << "What do you want to do?" << endl;
	cout << "1. Look around" << endl;
	cout << "2. Get out of the hallway." << endl;

	//get and validate input. 
	getline(cin, input);

	while (!cin || input.length() > 1 || (input[0] < 49 || input[0]>50))
	{
		cout << "Invalid Input. Please enter 1 or 2." << endl;
		getline(cin, input);
	}

	if (input[0] == '1')
	{
		cout << "YOu get up and take a look around the hallway. It's hard to see, since" << endl;
		cout <<"the only light is coming from the red emergency lights." << endl;
		cout << "When you look to the doorways, you can't belive what you're seeing." << endl;
		cout << "Normall there are foor doorways off of the hall. Now, though, the doors" << endl;
		cout << "to your left, right, and rear are gone and have been replaced by what" << endl;
		cout << "appear to be large holes. You look through and see impossible things." << endl;
		cout << "This is definitely weird. Maybe you should start exploring." << endl;
		return;
	}
	else
	{
		cout << "Youre not sure what's going on, but you know you need to get out of " << endl;
		cout << "this hallway. When you look to the doorways, you can't belive what" << endl;
		cout << "you're seeing. Normall there are foor doorways off of the hall. Now," << endl;
		cout << "though, the doors to your left, right, and rear are gone and have been" << endl;
		cout << "replaced by what appear to be large holes. You look through and see" << endl;
		cout << "impossible things." << endl;
		
		
	}
	
	
}

/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as
firstTimeIN.
*/
void Hallway::nextTimeIn(Player* temp)
{
	cout << "You're back in the hallway. There's not much to do or see here." << endl;
	cout << "YOu do feel at ease here though. Maybe a small rest wouldn't be so bad." << endl;
	cout << endl;

	cout << "Do you want to: " << endl;
	cout << "1. move on" << endl;
	cout << "2. sit down" << endl;

	getline(cin, input);

	while (!cin || input.length() > 1 || (input[0] < 49 || input[0]>50))
	{
		cout << "Invalid Input. Please enter 1 or 2." << endl;
		getline(cin, input);
	}

	if (input[0] == 49)
	{
		return;
	}
	//If the player opts to rest, there's a 50/50 chance they'll either regain or lose health.
	else
	{
	
		cout << "You sit down with your back to the wall and close your eyes. You can feel the" << endl;
		cout << "coldness of the metal through your jumsuit and it's quite soothing." << endl << endl;
		cout << "Despite the alarms, you doze off." << endl;

		//random number between 1 and 10
		int x = rand() % 10 + 1; 

		//If the number is even, lose that much health
		if (x % 2 == 0)
		{

			cout << "Caught halfway between sleep and waking, you feel your body start to" << endl;
			cout << "slump. Before you can react, your head hits the ground." << endl;

		
			temp->doDamage(x);

			cout << "You shake it off, and get up. It's time to stop being lazy." << endl;
		}
		//If the number is odd, gain that much health. 
		else
		{
			cout << "You wake up. There's no way to tell how long you were asleep," << endl;
			cout <<" but you feel refreshed." << endl;
			//make sure the player isn't already at 100 health.
			if (temp->getHealth() != 100)
				temp->getHealthBack(x);
			cout << "It's time to move on." << endl;

		}
	}

}

