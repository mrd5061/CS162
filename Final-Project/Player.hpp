/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Player Class. This class creates an object representing the user and keeps track of 
health points, inventory items, and whether or not the player has won the game .

*/


#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Player
{
private:

	int health;
	bool itemsArry[5];
	bool won;

public:

	Player();
	int getHealth();
	
	void doDamage(int);
	void getHealthBack(int);
	void addItem(int);
	bool getItemStatus(int);
	void setItemStatus(int, bool);
	bool haveAllItems();

	void setWonBool();
	bool getWonBool();
};
#endif 


