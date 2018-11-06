/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Ocean Class, a public cop of Space.

*/

#ifndef OCEAN_H
#define OCEAN_H
#include <string>
#include"Space.hpp"
#include "Player.hpp"

using std::string;

class Ocean: public Space
{
private:
	bool eelPill;

public:

	Ocean();

	void firstTimeIn(Player*);
	void nextTimeIn(Player*);


	void eelDamage(Player*, int);


};

#endif