/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Field class. A public copy of the Space Class. Does not contain any unique functions.
*/

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

#include"Field.hpp"
#include "Player.hpp"

Field::Field()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;

	visited = false;
	roomName = "Field";
}

/*firstTimeIn: Takes a player pointer. Displays text that describes the room. Allows the user to explore or move on. 
*/
void Field::firstTimeIn(Player* temp)
{
	//display intro text. 
	
	cout << "You step out of the portal and are immediately blinded by the bright sunlight." << endl;
	cout << "You hear the sound of a soft breeze rippling through tall grass. When your eyes"<< endl;
	cout << "adjust, you see that you've somehow ended up in a field. The sky is bright blue" << endl;
	cout << "and dotted with cotton ball clouds. A sun bleached wooden barn sits a couple of" << endl;
	cout << "hundred feet away." << endl << endl;
	cout << "You recognize this place. Your grandfather owned a farm before he passed away," << endl;
	cout << "and this part of the property was your favorite to explore as a child." << endl;
	cout << endl;
	cout << "You close your eyes and take a deep breath of fresh air. Suddenly, you hear foot" << endl;
	cout << "steps and feel something pass quickly by your legs." << endl << endl;
	cout << "You open your eyes and see nothing, but you hear a distant shriek and a loud thud" << endl;
	cout << "from somewhere in front of you. You walk forward and see a circular opening in" << endl;
	cout <<"the ground that looks like it was an old well once covered by a piece of plywood" << endl;
	cout << "that is now cracked and splintered." << endl;
	cout << endl;
	cout << "Do you want to look into the well? Y/N" << endl;
	
	//get and validate input.
	getline(cin, input);
	
	while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
	{
		cout << "Invalid Input. Enter either Y or N." << endl;

		getline(cin, input);

	}

	if (input[0] == 'y' || input[0] == 'Y')
	{
		
		cout << "You step forward carefull and peer down into the well. At the bottom lies a" << endl;
		cout << "small child, huddled against one side. The child looks up at you with black" << endl;
		cout << "eyes. With a gasp, you realize the child is you when you were 10, only now the" << endl;
		cout << "child is wearing a terrible, twisted grin. You try to stumble away from the" << endl;
		cout << "well, but your younger self leaps at you with frightening speed. You fall" << endl;
		cout << "backward and feel a blow land on your chest." << endl;
		cout << endl; 
		//do health damage to the player.
		temp->doDamage(5); 
		cout << endl;
		cout << "You lay on your back, looking up at the sky. Memories of that summer wash over" << endl;
		cout << "you. Your mother often let you spend weekeds at your grandfather's farm. He" << endl;
		cout << "would let you explore his property all day long. To this day you don't know if" << endl;
		cout << "he'd fogotten about the old well in this field or if he had never known of" << endl;
		cout << "it's existence. Either way, you had been exploring one day when you" << endl;
		cout << "accidentally stepped on the old, dry-rotted plywood and fallen to the bottom" << endl;
		cout << "of the old well. You don't remember many specifics of the hours you spent down" << endl;
		cout << "in the well, but the terror you felt then is all too clear in your mind." << endl;
		cout << endl;
		cout << "It took until the next afternoon for your grandfather to find you. The doctors" << endl;
		cout << "had told your mother that you were so dehydrated that it was a miracle you had" << endl;
		cout << "survived. You never saw your grandfather much after that, and you never set" << endl;
		cout << "foot on his farm again. He died just a few months before you went into astronaut" << endl;
		cout << "training. With a grunt you sit up and see something white and papery sitting on" << endl;
		cout << "the grass a foot from the edge of the well." << endl << endl;;
		cout << "It is a letter with your name scrawled on the envelope.It looks familiar, but" << endl;
		cout << "now's not the time to inspect it. You shove it in your pocket." << endl;
		
		temp->addItem(3);
		cout << endl;
		cout << "You take one last look at the field before stepping back through the portal." << endl;
		
		

	}

	else
	{
		cout << "You  decide to investigate another time." << endl;
		cout << "You take one last look at the field before stepping back through the portal " << endl;

		
	}
	//set visited bool.
	visited = true;

}
/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as
firstTimeIN.
*/
void Field::nextTimeIn(Player *temp)
{
	if (temp->getItemStatus(3) == 0)
	{
		cout << "The grass tickes your ankle as you step through the portal. Your eyes are drawn" << endl;
		cout << "to the well." << endl << endl;
		cout << "Do you want to investigate ? " << endl;

		//get and validate input.
		getline(cin, input);

		while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			cout << "You step forward carefull and peer down into the well. At the bottom lies a" << endl;
			cout << "small child, huddled against one side. The child looks up at you with black" << endl;
			cout << "eyes. With a gasp, you realize the child is you when you were 10, only now the" << endl;
			cout << "child is wearing a terrible, twisted grin. You try to stumble away from the" << endl;
			cout << "well, but your younger self leaps at you with frightening speed. You fall" << endl;
			cout << "backward and feel a blow land on your chest." << endl;
			cout << endl;
			//do health damage to the player.
			temp->doDamage(5);
			cout << endl;
			cout << "You lay on your back, looking up at the sky. Memories of that summer wash over" << endl;
			cout << "you. Your mother often let you spend weekeds at your grandfather's farm. He" << endl;
			cout << "would let you explore his property all day long. To this day you don't know if" << endl;
			cout << "he'd fogotten about the old well in this field or if he had never known of" << endl;
			cout << "it's existence. Either way, you had been exploring one day when you" << endl;
			cout << "accidentally stepped on the old, dry-rotted plywood and fallen to the bottom" << endl;
			cout << "of the old well. You don't remember many specifics of the hours you spent down" << endl;
			cout << "in the well, but the terror you felt then is all too clear in your mind." << endl;
			cout << endl;
			cout << "It took until the next afternoon for your grandfather to find you. The doctors" << endl;
			cout << "had told your mother that you were so dehydrated that it was a miracle you had" << endl;
			cout << "survived. You never saw your grandfather much after that, and you never set" << endl;
			cout << "foot on his farm again. He died just a few months before you went into astronaut" << endl;
			cout << "training. With a grunt you sit up and see something white and papery sitting on" << endl;
			cout << "the grass a foot from the edge of the well." << endl << endl;;
			cout << "It is a letter with your name scrawled on the envelope.It looks familiar, but" << endl;
			cout << "now's not the time to inspect it. You shove it in your pocket." << endl;

			temp->addItem(3);
			cout << endl;
			cout << "You take one last look at the field before stepping back through the portal." << endl;

			return;


			if (input[0] == 'n' || input[0] == 'n')
			{
				cout << "You decide to investigate another time. " << endl;
				cout << "It's time to move on." << endl;

				return;
			}

		}
	}
	//If the player has the letter, they can look at the well again, but it won't 
	//advance the game. If they player chooses to look at the well, there's a 50/50
	//chance they'll regain 10 health. 
	else
	{
		cout << "The grass tickes your ankle as you step through the portal. Your eyes are drawn to the well." << endl << endl;
		cout << "Do you want to investigate ? " << endl;


		getline(cin, input);

		while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			int chance = rand() % 2 + 1;

			if (chance == 1)
			{
				cout << "You walk over to the well and hesitantly peek inside. Thankfully it's empty," << endl;
				cout << "but you swear you can hear soft crying sounds in the distance." << endl<< endl;
				cout << "YOu decide to move on." << endl;
			}
			else
			{
				cout << "Youre at the edge of the well when you feel a warm breeze blow over you." << endl;
				temp->getHealthBack(10);
				cout << "You decide to move on." << endl;
			}
			return;
		}


		if (input[0] == 'n' || input[0] == 'N')
		{
			cout << "You take one last look at the field before moving on." << endl;
		}
	}
	
	
}



