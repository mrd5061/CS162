/*Author: Meghan Dougherty
Date:07/31/2018
Description: Function declaration file for the Blue Men class. A subclass of the character class.
They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage.
They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.
Their special move is mob. 
*/
#ifndef BLUEMEN_H
#define BLUEMEN_H
#include "Character.hpp"
class BlueMen : public baseCharacter
{
public:
	BlueMen();
	void attackRoll();
	void defenseRoll();
	void printAttackDiceRolls();
	void printDefenseDiceRolls();

	void setDamageTaken(int);
	void strengthCalc();
};

#endif
