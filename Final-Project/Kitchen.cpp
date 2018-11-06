/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Kitchen class. A public copy of the Space Class. Does not contain any unique functions.
*/
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

#include"Kitchen.hpp"
#include "Player.hpp"

//Constructor
Kitchen::Kitchen()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = "Kitchen";
}

/*firstTimeIn: Takes a player pointer. Displays text that describes the room. Allows the user to explore or move on.
*/
void Kitchen::firstTimeIn(Player* temp)
{
	//Display the intro text.
	cout << "You step out of the portal and into the kitchen of the ship. Kitchen is a loose" << endl;
	cout << "term, it was really more of a communal room where the crew at their meals and" << endl;
	cout << "held meetings. You can still hear the alarms shrieking, but the sound is" << endl;
	cout << "muffled now. There isn't a spot on the wall that isn't taken up by a shelf, a" << endl;
	cout << "drawer, or some other cluttered storage which always made you feel a little" << endl;
	cout << "claustraphobic. The focal point of the room is the large circular table set in" << endl;
	cout << "the middle of the room. Usually, the top is clear, but now it's a mess." << endl;
	cout << endl;
	cout << "It looks like the crew had jumped up in the middle of a meal." << endl;
	cout << "Half eaten rehydtrated food dot the paper plates and a couple of sporks lay" << endl;
	cout << "scattered on the floor. Just as you bend down to pick up one of the utensiles," << endl;
	cout << "the lights go out. Your stomach turns over and just as you begin to fumble for" << endl; 
	cout << "a switch, the lights come back on." << endl << endl;
	cout << "Nothing is the same, even the light is different. Before it was the normal cool" << endl;
	cout << "white of the ship, but now everything is cast in green, sickly tones. A thin" << endl;
	cout << "film of dust covers everything. The he air is still and the world around you is" << endl;
	cout << "now completely silent. Panic rises in your throat. Because of the ship's life" << endl;
	cout << "support systems, there was always a slight breeze. Still air cannot be good." << endl;
	cout << endl;
	cout << "The table is mostly cleared now, and all the chairs are neatly pushed in." << endl;
	cout << "Before you on the edge of the table are two plates, each with what looks like" << endl;
	cout << "a pill sitting on it. Each plate has a shape roughly carved in front of it." << endl;
	cout << "One is an squiggly line which sits in front of the whitle pill." << endl;
	cout << "The other is a skull and crossbones in front of a black pill." << endl;
	cout << endl;

	cout << "What would you like to do?" << endl;
	cout << " Enter 1 for take White pill or 2 for take Black pill." << endl;

	//get and validate input.
	getline(cin, input);

	while (!cin || input.length() > 1 ||(input[0] < 49|| input[0] > 50))
	{
		cout << "Invalid Input. Enter either 1 or 2." << endl;

		getline(cin, input);

	}
	//If they choose to take the white pill, do 50 damage and force them to leave the room. 
	if (input[0] == '1' )
	{
		cout << "You pick up the white pill and swallow it dry. For a few moments," << endl;
		cout << "nothing happens. Then it feels like something has hit you hard on the" << endl;
		cout << "back of the head. Your vision goes blurry and you feel as if you'" << endl;
		cout << "going to be sick." << endl;
		cout << endl;
		temp->doDamage(50);
		cout << "You have " << temp->getHealth() << " health." << endl;
		cout << endl;
		cout << "You lean against the back of a chair with our eyes closed and, after a" << endl;
		cout << "few minutes, you begin to feel better. When you open your eyes, the room" << endl;
		cout << "is back to normal. Or as normal as it can be since the portal has also" << endl;
		cout << "re-ppeared. Just as you decide to move on, you see the lights flash, and" << endl;
		cout << "for a split second, you see the \"other\" room. You get the feeling that" << endl;
		cout << "there's something to be found here, maybe you should come back." << endl;



	}
	//If they choose black pill, do 20 damage, user gets the key card,  and offer the option to pick up the white pill.
	if (input[0] == '2')
	{
		cout << "You don't know why, but you feel drawn to the black pill despite" << endl;
		cout <<"how ominious it and the carving look" << endl;
		cout << "You swallow it dry and a warm feeling blooms in your stomach. A wave" << endl;
		cout << "of stomach cramps follows, forcing you to double over. " << endl<<endl;
		temp->doDamage(20);
		cout << endl;
		cout << "After a moment, the feeling passes. When you look up, the room is back to" << endl;
		cout << "normal.Or as normal as it can be since the portal has also re-appeared." << endl;
		cout << "You also notice that, on the the table in front of you , is your key card." << endl;
		cout << "You snatch it up." << endl;
		temp->addItem(0);
		cout << "You also eye the white pill. YOu don't know what you'd use it for, but you" << endl;
		cout << "feel like it might come in handy." << endl<< endl;
		cout << "Do you take it? Y/N" << endl;

		getline(cin, input);
		while (!cin || input.length() >1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;
			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			cout << "You slip it in your pocket." << endl;
			temp->addItem(4);
		}
		else
		{
			cout << "You leave it behind." << endl;

		}
		


	}

	setVisited(true);

}

/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as
firstTimeIN.
*/
void Kitchen::nextTimeIn(Player *temp)
{
	if (temp->getItemStatus(1) == 0)
	{
		
		cout << "You enter the room and it is the dark and ominous version of the kitchen. The" << endl;
		cout << "black pill sits there, waiting for you." << endl << endl;
		cout << "This time you have no choice. You must take the black pill" << endl;
		cout << "You swallow it dry and a warm feeling blooms in your stomach. A wave of stomach" << endl;
		cout << "cramps follows, forcing you to double over. " << endl;
		temp->doDamage(20);
		cout << "After a moment, the feeling passes. When you look up, the room is back to" << endl;
		cout << "normal.Or as normal as it can be since the portal has also re - ppeared." << endl;
		cout << "You also notice that, on the the table in front of you , is your key card." << endl;
		cout << "You snatch it up and jump through the portal." << endl;
		temp->addItem(0);


	}
	else
	{
		cout << "You enter the kitchen. This is the messy, real life version. You wait for a" << endl;
		cout << "few minutes but nothing happens." << endl;
		cout << "You should keep exploring." << endl;
	}
		
	

}

