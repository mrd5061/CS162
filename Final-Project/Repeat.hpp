/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Repeat Class, a public cop of Space.

*/

#ifndef REPEAT_H
#define REPEAT_H
#include <string>
#include"Space.hpp"
#include "Player.hpp"




class Repeat : public Space
{


public:

	Repeat();
	void firstTimeIn(Player*);
	void nextTimeIn(Player*);

};

#endif