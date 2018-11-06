/*Author: Meghan Dougherty
Date:07/31/2018
Description:  Function declaration file for the Barbarian class. A subclass of the character class. 
Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!
Her special move is glare. 

*/
#ifndef MEDUSA_H
#define MEDUSA_H


#include "Character.hpp"
class Medusa : public baseCharacter
{
public:
	Medusa();
	void attackRoll();
	void defenseRoll();
	void printAttackDiceRolls();
	void printDefenseDiceRolls();

	void setDamageTaken(int);
	void strengthCalc();
};

#endif // !MEDUSA_H
