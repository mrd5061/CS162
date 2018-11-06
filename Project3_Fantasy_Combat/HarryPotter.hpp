/*Author: Meghan Dougherty
Date:07/31/2018
Description:  Function declaration file for the Barbarian class. A subclass of the character class. 
He's a wizard. His special move is hogwarts. 

*/

#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H
#include "Character.hpp"
class HarryPotter : public baseCharacter
{
private:
	int hogwartsBool;
public:
	HarryPotter();
	void attackRoll();
	void defenseRoll();
	void printAttackDiceRolls();
	void printDefenseDiceRolls();

	void setDamageTaken(int);
	void strengthCalc();
};

#endif
