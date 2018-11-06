/*Author: Meghan Dougherty
Date:07/31/2018
Description: The function declaration class for the Character class, an abstract class that the Barbarian,
Blue Men, Harry Potter, Medusa, and Vampire classes are all based on. Not a pure abstract class as there are
some concrete functions, like member variable getter and setters that will be universal to all character 
permutations. 

*/

#ifndef CHARACTER_H
#define CHARACTER_H



class baseCharacter
{
protected:
	int armor;
	int strengthPoints;

	int diceRoll1;
	int diceRoll2;
	int diceRoll3;

	int attackTotal;
	int defenseTotal;
	int damageTaken;

public:
	baseCharacter();

	virtual void attackRoll() = 0;
	virtual void defenseRoll() = 0;

	virtual void setDamageTaken(int) = 0;
	virtual void strengthCalc() = 0;
	virtual void printAttackDiceRolls() = 0;
	virtual void printDefenseDiceRolls() = 0;


	int getArmor();
	int getStrengthPoints();
	int getDiceRoll1();
	int getDiceRoll2();
	int getDiceRoll3();
	int getAttackTotal();
	int getDefenseTotal();
	int getDamageTaken();

	void setArmor(int);
	void setStrengthPoints(int);
	void setDiceRoll1(int);
	void setDiceRoll2(int);
	void setDiceRoll3(int);
};

#endif // !1
