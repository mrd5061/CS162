

#include <string>
#include <iostream>
#include <ctime>

using std::string;
using std::cin;
using std::cout;
using std::endl;


#include"Repeat.hpp"
#include "Player.hpp"

//Constructor
Repeat::Repeat()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = "Repeat";
}
/*firstTimeIn: Takes a player pointer. Displays text that describes the room. Allows the user to explore or move on.
*/
void Repeat::firstTimeIn(Player* temp)
{

	cout << "You step through the portal and, somehow, into a living room. You realize" << endl;
	cout << "quickly that this is the first apartment you rented. You lived in this tiny" << endl;
	cout << "studio during your last two years of college with your fat black cat muffin." << endl;
	cout << "You had a lot of good memories here. Sun streams through the open windows," << endl;
	cout << "lighting up the white curtains which ruffle in the breeze. Desipte all the" << endl;
	cout << "nostalgia, the longer you spend here, the more creeped out you fell. You can't" << endl;
	cout << "quite put your finger on it, but something is wrong." << endl << endl;
	cout << "Out of the corner of your eye, you see something small dart behind the couch." << endl;
	cout << "Do you want to investigate? Y/N" << endl;
	
	//get and validate input.
	getline(cin, input);

	while (!cin || input.length() >1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
	{
		cout << "Invalid Input. Enter either Y or N." << endl;

		getline(cin, input);

	}

	if (input[0] == 'y' || input[0] == 'Y')
	{
		cout << "You walk toward the couch and look behind. There's nothign there! You're" << endl;
		cout << "about to turn around when Muffin slinks behind the couch. You watch as he" << endl;
		cout << "stops, lays down, then disappears into thin air. Confused, you glance back" << endl;
		cout << "toward where the cat came from and find him ambling toward you again." << endl << endl;
		cout << "That's when you realize what was wrong with the room. You glance back at" << endl;
		cout << "the curtains and watch as they ruffle, halt, then ruffle again. Youre unsure" << endl;
		cout << "why, but it seems like this room is looping through the same thirty seconds" << endl;
		cout << "or so of time. And, after a little thought, you realize what time this is." << endl;
		cout << "One day, toward the end of your senior year, you came home to this studio to" << endl;
		cout << "find that Muffin wasn't anywhere to be seen. It wasn't like he greeted you" << endl;
		cout << "at the door, but it wasn't like him to hide. You tore the room apart and" << endl;
		cout << "finally found his body, cold and stiff, behind the couch. You had heard of" << endl;
		cout << "cats often hide when they're dying, but knowing that didn't prepare you for" << endl;
		cout << "finding Muffin. With tears in your eyes, you turn around and watch as he" << endl;
		cout << "slinks behind the couch again. You almost want to just sit and watch him" << endl;
		cout << "for a while." << endl;

		cout << "How many times do you want to watch Muffin?" << endl;
		cout << "Pick a number between 1 and 9." << endl;
		
		//get and validate input.
		getline(cin, input);

		while (!cin || input.length() > 1 || (input[0] < '1' || input[0]>'9'))
		{
			cout << "Invalid Input. Enter a number between 1 and 9" << endl;

			getline(cin, input);

		}
		//The amount of times the user opts to watch the cat decides how much damage is done to the user.
		cout << "You sat and watched Muffin for " << input[0] - 48 << "cycles. You feel" << endl;
		cout << "something wet in your left ear. You reach up, feel your ear, and inspect" << endl;
		cout << "your hand." << endl;
		cout << "It's blood. Something about the way time works in this room isn't good for you." << endl;
		temp->doDamage((input[0] - 48));

		cout << "You're about to jump back through the portal when you notice a book on the" << endl;
		cout << "coffee table. It's a mechanical handbook for the space ship. What's it doing" << endl;
		cout << "here though? On instinct, you grab it before jumping back through the portal." << endl;

		//get the textbook.
		temp->addItem(1);


	}

	else
	{
		cout << "This room is seriously creepy. Maybe you'll explore more later" << endl;
		cout << "You hop back through the portal." << endl;


	}

	setVisited(true);

}
/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as
firstTimeIN and the same mechanics for the cat damage.
*/
void Repeat::nextTimeIn(Player *temp)
{
	if (temp->getItemStatus(2) == 0)
	{
		cout << "The room is the same as you remember, and you feel more uneasy with every passing second." << endl;
		cout << "Out of the corner of your eye, you see something small dart behind the couch." << endl;
		cout << "Do you want to investigate? Y/N" << endl;

		getline(cin, input);

		while (!cin || input.length() > 1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			cout << "You walk toward the couch and look behind. There's nothign there! You're" << endl;
			cout << "about to turn around when Muffin slinks behind the couch. You watch as he" << endl;
			cout << "stops, lays down, then disappears into thin air. Confused, you glance back" << endl;
			cout << "toward where the cat came from and find him ambling toward you again." << endl << endl;
			cout << "That's when you realize what was wrong with the room. You glance back at" << endl;
			cout << "the curtains and watch as they ruffle, halt, then ruffle again. Youre unsure" << endl;
			cout << "why, but it seems like this room is looping through the same thirty seconds" << endl;
			cout << "or so of time. And, after a little thought, you realize what time this is." << endl;
			cout << "One day, toward the end of your senior year, you came home to this studio to" << endl;
			cout << "find that Muffin wasn't anywhere to be seen. It wasn't like he greeted you" << endl;
			cout << "at the door, but it wasn't like him to hide. You tore the room apart and" << endl;
			cout << "finally found his body, cold and stiff, behind the couch. You had heard of" << endl;
			cout << "cats often hide when they're dying, but knowing that didn't prepare you for" << endl;
			cout << "finding Muffin. With tears in your eyes, you turn around and watch as he" << endl;
			cout << "slinks behind the couch again. You almost want to just sit and watch him" << endl;
			cout << "for a while." << endl;

			cout << "How many times do you want to watch Muffin?" << endl;
			cout << "Pick a number between 1 and 9." << endl;

			getline(cin, input);

			while (!cin || input.length() > 1 || (input[0] < '1' || input[0]>'9'))
			{
				cout << "Invalid Input. Enter a number between 1 and 9" << endl;

				getline(cin, input);

			}

			cout << "You sat and watched Muffin for " << input[0] - 48 << "cycles. You feel" << endl;
			cout << "something wet in your left ear. You reach up, feel your ear, and inspect" << endl;
			cout << "your hand." << endl;
			cout << "It's blood. Something about the way time works in this room isn't good for you." << endl;
			temp->doDamage((input[0] - 48));

			cout << "You're about to jump back through the portal when you notice a book on the" << endl;
			cout << "coffee table. It's a mechanical handbook for the space ship. What's it doing" << endl;
			cout << "here though? On instinct, you grab it before jumping back through the portal." << endl;

			temp->addItem(1);

		}
	}
	else
	{
		cout << "This room is seriously creepy. Maybe you'll explore more later" << endl;
		cout << "You hop back through the portal into the hallway." << endl;
	}


	




}

