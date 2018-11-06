
/* Author: Meghan Dougherty
Date: 8/15/2018
Description: The function definition file for the Player Class. Works with the Game class to create an object representing the user. 
keeps track of health and inventory item status as well as whether the game has been won or not. 
*/


#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

//constructor.
Player::Player()
{
	for (int i=0; i < 5; i++)
	{
		itemsArry[i] = false;
	}

	health = 100;
	won = 0;
}

//getHealth: No paramenters. Returns the players health.
int Player::getHealth()
{
	return health;
}

/* doDamage: Takes an integer. Subtracts the integer from the player's health. Reports the damage done. 
*/
void Player::doDamage(int h)
{
	health -= h;
	if (h == 1)
	{
		cout << endl;
		cout << "You lost " << h << " health point." << endl;
		cout << "You now have " << health << " health points." << endl<<endl;
	}
	else
	{
		cout << endl;
		cout << "You lost " << h << " health points." << endl << endl;
		cout << "You now have " << health << " health points." << endl << endl;;
	}
}

/*getHealthBack: Takes and integer. If the player's health is not at 100, adds the integer to the health.
reports change. 
*/
void Player::getHealthBack(int h)
{
	if (health < 100 && health + h <= 100 )
	{
		health += h;
		cout << endl;
		cout << "You regained " << h << " health!" << endl << endl;
	}
	
}

// addItem: takes an integer. Uses integer as an index and changes that array item to True.
void Player::addItem(int i)
{
	itemsArry[i] = true;
	
}
//getItemStatus: takes an integer. Uses integer as an index and returns the bool of that item. 
bool Player::getItemStatus(int i)
{
	return itemsArry[i];
}
//setItemStatus: takes an integer and a bool. Uses the integer as an index and sets that item's bool.
void Player::setItemStatus(int i, bool b)
{
	itemsArry[i] = b;
}

//haveAllItems: returns true if all of the essential game items. 
bool Player::haveAllItems()
{
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		if (itemsArry[i] == true)
		{
			
			x=x+1;
			
		}
	}

	if (x == 4)
	{
		return true;
	}
		
	else
		return false;

}
//setWonBool: takes no parameters. sets Won to true. 
void Player::setWonBool()
{
	won = 1;
}
//getWonBool: takes no parameters. returns the won bool. 
bool Player::getWonBool()
{
	return won;
}
