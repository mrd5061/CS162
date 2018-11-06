/* Author: Meghan Dougherty
   Date: 8/15/2018
   Description: The function definition file for the Escape Pod class. A public copy of the Space Class. Does not contain any unique functions.
*/

#include "EscapePod.hpp"
#include <iostream>
#include <string>
#include <stdlib.h> 

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor. Set pointers to NULL and the visited bool to false.
EscapePod::EscapePod()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = "Escape Pod";
}

/*firstTimeIn: Takes a player pointer. Displays text that describes the room. The player needs a key card. 
to get 'into' the room. After that, the player needs all of the game items (except the white pill) to see
the complete text and finish the game.

*/
void EscapePod::firstTimeIn(Player* temp)
{
	//does the player have the key card?
	if (!temp->getItemStatus(0))
	{
		cout << "You push the button to open the door. Nothing happens. You need to find your" << endl;
		cout << "key card to unlock the door." << endl;
	}

	else
	{
	
		cout << "You swipe your key card and and a green light turns on. You push the button and" << endl;
		cout << "the door slides open. You are unprepared for the sight before you. The entire" << endl;
		cout << "crew sits strapped into the escape pod's seats. They are all frozen with" << endl;
		cout << "expressions ranging from grim acceptance to absolute terror etched into their" << endl;
		cout << "statue like faces. You look to your seat and see yourself staring blankly at" << endl;
		cout << "the back of the seat in front of you. Maria, the biologist, is turned to the" << endl;
		cout <<"statue version of you and appears to be screaming somingthing at you." << endl;
		cout << endl;
		cout << "You remember everything now. During dinner, the alarms started going off." << endl;
		cout << "Everyone rushed to the cockpit to find that the navigation systems had failed" << endl;
		cout << "and the ship was drifting too close to the point of no return. The captain" << endl;
		cout << "tried, in vain, to turn the ship around before rushing everyone to the escape" << endl;
		cout << "pod. You had minutes to get off the ship before it got pulled into the black" << endl;
		cout << "hole." << endl;

		cout << "Inside the pod was chaos. Alarms were still clanging, lights flashing, and" << endl;
		cout << "the captain screaming as he realized the pod wasn't detaching like it should." << endl;
		cout << "Maria had turned to you and begged you to do something. You were the ship's" << endl;
		cout << "engineer and resident mechanic after all. You had known, in the moment," << endl;
		cout << "exactly what had to be done. The schematics had flooded your brain and it" << endl;
		cout << "would have been a simple fix.However, you also knew that fixing the problem" << endl;
		cout << "would mean getting left behind. Once it detached, the pod would have to leave" << endl;
		cout << "immediately to escape the pull of the black hole." << endl;
		cout << "Fear had rooted you in your spot. You were unable to do anything but stare ahead while Maria screamed her pleas at you." << endl;
		cout << endl;
		cout << "Now, though, it seems like the universe has give you a second chance. Maybe" << endl;
		cout << "it was just an anomaly caused by the black hole or maybe there is a God, but" << endl;
		cout << "for some reason it seems like your consciousness has been caugth between " << endl;
		cout << "dimensions. You look at your frozen crew mates. They deserve to live." << endl;

		cout << endl;
		cout << endl;
		cout << "On the far side of the pod is an airlock with a pressurized suit hanging on" << endl;
		cout << "the wall next to it." << endl;
		cout << endl;


		cout << "Do you go outside? Y/N" << endl;
		
		

		//get and validate user choice. 
		getline(cin, input);

		while (!cin || input.length() >1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		//If yes, but user does not have all items, the user cannot win the game.
		if (input[0] == 'y' || input[0] == 'Y')
		{
			if (temp->haveAllItems() == true)
			{
				//user 'wins'
				temp->setWonBool();
				
			}
			else
			{
				cout << "You don't have everything you need to detach the pod." << endl;
			}
		}
		else

		{
			if (!temp->haveAllItems())
			{
				cout << "Not right now. You don't feel quite ready yet." << endl;
				cout << "Maybe you should explore some more." << endl;
			}
			else
			{
				cout << "You have all the resources, but you need a moment to prepare yourself." << endl;
				cout << "Maybe exploring a little more will strengthen your resolve." << endl;
			}
		}
	}
	
	setVisited(true);

}

/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as 
firstTimeIN.
*/
void EscapePod::nextTimeIn(Player* temp)
{
	cout << "You don't think you'll ever get used to seeing your crew mates frozen like that." << endl;
	cout << "The suit hanging on the wall taunts you." << endl;

	if (temp->getItemStatus(0) == true)
		cout << "card" << endl;
	if (temp->getItemStatus(1) == true)
		cout << "book" << endl;
	if (temp->getItemStatus(2) == true)
		cout << "wrnech" << endl;
	if (temp->getItemStatus(3) == true)
		cout << "note" << endl;

	cout << "Do you go outside? Y/N" << endl;

	getline(cin, input);
	while (!cin || input.length() >1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
	{
		cout << "Invalid Input. Enter either Y or N." << endl;

		getline(cin, input);

	}

	if (input[0] == 'y' || input[0] == 'Y')
	{
		if (temp->haveAllItems()==true)
		{
			temp->setWonBool();
		}
		else
		{
			cout << "You don't have everything you need to detach the pod." << endl;
		}
	}
	else

	{
		if (temp->haveAllItems()==false)
		{
			cout << "Not right now. You don't feel quite ready yet." << endl;
			cout << "Maybe you should explore some more." << endl;
		}
		else
		{
			cout << "You have all the resources, but you need a moment to prepare yourself." << endl;
			cout << "Maybe exploring a little more will strengthen your resolve." << endl;
		}
	}
}
