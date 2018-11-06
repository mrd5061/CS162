
/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Ocean class. A public copy of the Space Class. Contains one unique function, eelDamage.
*/
#include <string>
#include <iostream>
#include <ctime>

using std::string;
using std::cin;
using std::cout;
using std::endl;


#include"Ocean.hpp"
#include "Player.hpp"

//Constructor.
Ocean::Ocean()
{
	Up = NULL;
	Down = NULL;
	Left = NULL;
	Right = NULL;
	visited = false;
	roomName = "Ocean";
	eelPill = false;
}
/*firstTimeIn: Takes a player pointer. Displays text that describes the room. Allows the user to explore or move on.
*/
void Ocean::firstTimeIn(Player* temp)
{
	//get the time when the user 'enters' the ocean. 
	time_t before = time(NULL);

	
	cout << "You step through the portal with a splash and water fills your shoes. You look" << endl;
	cout <<" out over the surroundings to find you are in the middle of what appears to be" << endl;
	cout << "a vast ocean. The water is ankle deep and lukewarm. You look around in all" << endl;
	cout << "directions, hoping to see a beach, but find that you are surrounded by a dense" << endl;
	cout << "white fog." << endl << endl;
	cout << "You take a few steps forward, but your surroundings don't seem to change. You" << endl;
	cout << "glance behind to see that the portal has almost been swallowed by the fog. In" << endl;
	cout << "a panic you race back to it. You don't really want to think about what would" << endl;
	cout << "happen if you got lost here. Suddenly you feel a nip at your ankle. You look" << endl;
	cout << "down to see a large tube like creature, like a cross between an eel and a" << endl; 
	cout << "leech. A mouth appears on the creature and you can see a circle of needle like" << endl;
	cout << "teeth. You jump out of the way before it lunges at you, but you feel another," << endl;
	cout <<" harder nip at your ankles. You turn around and see another eel creature." << endl;
	cout << "These things are going to keep biting you, so you'd better get a move on!" << endl;
	cout << "There' a shadow in the water to your left, do you want to investigate? Y/N" << endl;
	getline(cin, input);

	while (!cin || input.length() > 1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
	{
		cout << "Invalid Input. Enter either Y or N." << endl;
		getline(cin, input);
	}

	if (input[0] == 'y' || input[0] == 'Y')
	{
		
		cout <<  "You step toward the shadow, kicking the eels out of your way. Through the" << endl;
		cout << "clear water you recognize that the thing is human in shape." << endl;
		cout << endl;
		cout << "Looking closer, you realize you know who the body is, or was. Though the skin" << endl;
		cout << "is pale and waxy, and she's wearing a strange while tunic, you would recognize" << endl;
		cout << "Maria, the crew's biologist, anywhere. She's laying straight and stiff under" << endl;
		cout << "the water, her hands meeting at her stomach, clutching what appears to be a" << endl;
		cout << "large crescent wrench. You reach down to grab the wrench. As your hand closes" << endl;
		cout << "around the handle, Her eye's spring open. You pull the wrench out of her hands" << endl;
		cout << "easily, but once your hand is out of the water, her mouth opens." << endl;
		cout << "Maria appears to scream silently as a multitude of the eels swarm her. In seconds" << endl;
		cout << "they're gone again, and no trace of Maria remains." << endl;
		cout << endl;

		temp->addItem(2);

		cout << "You blink in shock and continue to stare at the water until another nip at" << endl;
		cout << "your ankles breaks you out of your trance." << endl;
		cout << "You decide to move on." << endl;


	}

	else
	{
		cout << "The eels are creepy enough as it is, and you don't really want to know what" << endl;
		cout << "could be making a shadow that big." << endl;
		


	}
	//If the player has the white pill, the game allows them to either take, drop it in the water, or put it back in the inventory. 
	if (temp->getItemStatus(4))
	{
		cout << " This biting is getting annowing. Maybe you have something that can get" << endl;
		cout << "rid of these eels for a while." << endl;
		cout << "Do you want to go through your inventory? Y/N" << endl;
		getline(cin, input);

		while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0] != 'N')))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			cout << "You start to pull items out of your pockets and find the white pill." << endl;
			cout << "Do you:" << endl;
			cout << "1. drop it in the water" << endl;
			cout << "2. Take it." << endl;
			cout << "3. Put it Back." << endl;

			getline(cin, input);

			while (!cin || input[0] < 49 || input[0] > 51)
			{
				cout << "Invalid Input. Enter either 1, 2, or 3." << endl;

				getline(cin, input);

			}

			if (input[0] == 49)
			{
				cout << "You drop it in the water and the pill dissolves instantly." << endl;
				cout << "You watch as the eels scatter away from you." << endl;
				//take the pill out of inventory.
				temp->setItemStatus(4, false);
				//no eel damage now!
				eelPill = true;

			}
			if (input[0] == 50)
			{
				cout << " You swallow the pill. For a few moments, nothing happens." << endl;
				cout << "Then it feels like something has hit you hard on the back of the head." << endl;
				cout << "Your vision goes blurry and you feel as if you're going to be sick." << endl;
				cout << endl;
				//do 50 damage.
				temp->doDamage(50);

			}
		}
		else
		{
			cout << "You put the pill back in your pocket. You really should take unknown pills." << endl;
		}
		
	}
		//get the time when the player 'leaves'
		time_t after = time(NULL);
		//subtract the before time from the after time
		double x = difftime(after, before);
		//the difference is the damage.
		eelDamage(temp, x);

		setVisited(true);
}
/* nextTimeIn: Takes a player pointer. Skips most of the descriptive text, but offers the same options as
firstTimeIN and same mechanics for eel damage. 
*/
void Ocean::nextTimeIn(Player *temp)
{
	time_t before = time(NULL);
	if (temp->getItemStatus(2) == false)
	{
		
		cout << "You splash into the ocean and the vista is as foggy as you remember. You also" << endl;
		cout << "feel a familiar bite on your right ankle. " << endl;
		cout << "YOu spot the  shadow in the water to your left, do you want to investigate? Y/N" << endl;
		getline(cin, input);

		while (!cin || input.length() >1 || !(toupper(input[0]) == 'Y' || toupper(input[0]) == 'N'))
		{
			cout << "Invalid Input. Enter either Y or N." << endl;

			getline(cin, input);

		}

		if (input[0] == 'y' || input[0] == 'Y')
		{
			cout << "You step toward the shadow, kicking the eels out of your way. Through the" << endl;
			cout << "clear water you recognize that the thing is human in shape." << endl;
			cout << endl;
			cout << "Looking closer, you realize you know who the body is, or was. Though the skin" << endl;
			cout << "is pale and waxy, and she's wearing a strange while tunic, you would recognize" << endl;
			cout << "Maria, the crew's biologist, anywhere. She's laying straight and stiff under" << endl;
			cout << "the water, her hands meeting at her stomach, clutching what appears to be a" << endl;
			cout << "large crescent wrench. You reach down to grab the wrench. As your hand closes" << endl;
			cout << "around the handle, Her eye's spring open. You pull the wrench out of her hands" << endl;
			cout << "easily, but once your hand is out of the water, her mouth opens." << endl;
			cout << "Maria appears to scream silently as a multitude of the eels swarm her. In seconds" << endl;
			cout << "they're gone again, and no trace of Maria remains." << endl;
			cout << endl;

			temp->addItem(2);

			cout << "You blink in shock and continue to stare at the water until another nip at" << endl;
			cout << "your ankles breaks you out of your trance." << endl;

			if (temp->getItemStatus(4))
			{
				cout << " This biting is getting annowing. Maybe you have something that can get" << endl;
				cout << "rid of these eels for a while." << endl;
				cout << "Do you want to go through your inventory? Y/N" << endl;
				getline(cin, input);

				while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0] != 'N')))
				{
					cout << "Invalid Input. Enter either Y or N." << endl;

					getline(cin, input);

				}

				if (input[0] == 'y' || input[0] == 'Y')
				{
					cout << "You start to pull items out of your pockets and find the white pill." << endl;
					cout << "Do you:" << endl;
					cout << "1. drop it in the water" << endl;
					cout << "2. Take it." << endl;
					cout << "3. Put it Back." << endl;

					getline(cin, input);

					while (!cin || input[0] < 49 || input[0] > 51)
					{
						cout << "Invalid Input. Enter either 1, 2, or 3." << endl;

						getline(cin, input);

					}

					if (input[0] == 49)
					{
						cout << "You drop it in the water and the pill dissolves instantly." << endl;
						cout << "You watch as the eels scatter away from you." << endl;
						//take the pill out of inventory.
						temp->setItemStatus(4, false);
						//no eel damage now!
						eelPill = true;

					}
					if (input[0] == 50)
					{
						cout << " You swallow the pill. For a few moments, nothing happens." << endl;
						cout << "Then it feels like something has hit you hard on the back of the head." << endl;
						cout << "Your vision goes blurry and you feel as if you're going to be sick." << endl;
						cout << endl;
						//do 50 damage.
						temp->doDamage(50);

					}
				}
				else
				{
					cout << "You put the pill back in your pocket. You really should take unknown pills." << endl;
				}

			}

			cout << "You decide to move on." << endl;


		}
		
		else
		{
			cout << "The eels are creepy enough as it is, and you don't really want to know what" << endl;
			cout << "could be making a shadow that big." << endl;
			if (temp->getItemStatus(4))
			{
				cout << " This biting is getting annowing. Maybe you have something that can get" << endl;
				cout << "rid of these eels for a while." << endl;
				cout << "Do you want to go through your inventory? Y/N" << endl;
				getline(cin, input);

				while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0] != 'N')))
				{
					cout << "Invalid Input. Enter either Y or N." << endl;

					getline(cin, input);

				}

				if (input[0] == 'y' || input[0] == 'Y')
				{
					cout << "You start to pull items out of your pockets and find the white pill." << endl;
					cout << "Do you:" << endl;
					cout << "1. drop it in the water" << endl;
					cout << "2. Take it." << endl;
					cout << "3. Put it Back." << endl;

					getline(cin, input);

					while (!cin || input[0] < 49 || input[0] > 51)
					{
						cout << "Invalid Input. Enter either 1, 2, or 3." << endl;

						getline(cin, input);

					}

					if (input[0] == 49)
					{
						cout << "You drop it in the water and the pill dissolves instantly." << endl;
						cout << "You watch as the eels scatter away from you." << endl;
						//take the pill out of inventory.
						temp->setItemStatus(4, false);
						//no eel damage now!
						eelPill = true;

					}
					if (input[0] == 50)
					{
						cout << " You swallow the pill. For a few moments, nothing happens." << endl;
						cout << "Then it feels like something has hit you hard on the back of the head." << endl;
						cout << "Your vision goes blurry and you feel as if you're going to be sick." << endl;
						cout << endl;
						//do 50 damage.
						temp->doDamage(50);

					}
				}
				else
				{
					cout << "You put the pill back in your pocket. You really should take unknown pills." << endl;
				}

			}

			cout << "It's time to move on" << endl;


		}

	}
	else
	{
		cout << "The vista is the same  as before. " << endl;
		
		cout << "and so are the eels." << endl;

		if (temp->getItemStatus(4))
		{
			cout << " This biting is getting annowing. Maybe you have something that can get" << endl;
			cout << "rid of these eels for a while." << endl;
			cout << "Do you want to go through your inventory? Y/N" << endl;
			getline(cin, input);

			while (!cin || !(toupper(input[0]) == 'Y' || toupper(input[0] != 'N')))
			{
				cout << "Invalid Input. Enter either Y or N." << endl;

				getline(cin, input);

			}

			if (input[0] == 'y' || input[0] == 'Y')
			{
				cout << "You start to pull items out of your pockets and find the white pill." << endl;
				cout << "Do you:" << endl;
				cout << "1. drop it in the water" << endl;
				cout << "2. Take it." << endl;
				cout << "3. Put it Back." << endl;

				getline(cin, input);

				while (!cin || input[0] < 49 || input[0] > 51)
				{
					cout << "Invalid Input. Enter either 1, 2, or 3." << endl;

					getline(cin, input);

				}

				if (input[0] == 49)
				{
					cout << "You drop it in the water and the pill dissolves instantly." << endl;
					cout << "You watch as the eels scatter away from you." << endl;
					//take the pill out of inventory.
					temp->setItemStatus(4, false);
					//no eel damage now!
					eelPill = true;

				}
				if (input[0] == 50)
				{
					cout << " You swallow the pill. For a few moments, nothing happens." << endl;
					cout << "Then it feels like something has hit you hard on the back of the head." << endl;
					cout << "Your vision goes blurry and you feel as if you're going to be sick." << endl;
					cout << endl;
					//do 50 damage.
					temp->doDamage(50);

				}
			}
			else
			{
				cout << "You put the pill back in your pocket. You really should take unknown pills." << endl;
			}

		}

		cout << "You decide to move on." << endl;
	}

	time_t after = time(NULL);
	double x = difftime(after, before);
	eelDamage(temp, x);


}
/* eelDamage: Takes an integer and a player pointer as arguments. Checks if the user has used the white pill
on the ocean. If not, displays the damage done by the eels. 
*/
void Ocean::eelDamage(Player *temp, int x)
{
	if (!eelPill)
	{
		cout << "While you were in the ocean, the eels did " << x << " damage." << endl;
		temp->doDamage(x);
		cout << endl;
	}
}