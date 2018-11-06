/*Author: Meghan Dougherty
Date:07/31/2018
Description: Function declaration file for the Barbarian class. A subclass of the character class. 	
Suave, debonair, but vicious and surprisingly resilient. His special move is charm. 

*/
#ifndef VAMPIRE_H
#define VAMPIRE_H


#include "Character.hpp"
class Vampire : public baseCharacter
{
private: 
	int charmBool; 
public:
	Vampire();
	void attackRoll();
	void defenseRoll();
	void printAttackDiceRolls();
	void printDefenseDiceRolls();

	void setDamageTaken(int);
	void strengthCalc();


};

#endif // !VAMPIRE_H
