/*Author: Meghan Dougherty
Date:07/31/2018
Description: Function declaration file for the Barbarian class. A subclass of the character class. 
Think Conan or Hercules from the movies. Big sword, big muscles, bare torso. No special moves. 

*/

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Character.hpp"
class Barbarian : public baseCharacter
{
public:
	Barbarian();
	void attackRoll();
	void defenseRoll();
	void printAttackDiceRolls();
	void printDefenseDiceRolls();

	void setDamageTaken(int);
	void strengthCalc();
};
#endif // !BARBARIAN_H
