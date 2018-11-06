/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Field Class, a public cop of Space.

*/

#ifndef FIELD_H
#define FIELD_H
#include <string>
#include"Space.hpp"
#include "Player.hpp"

using std::string;

class Field : public Space
{


public:

	Field();
	void firstTimeIn(Player*);
	void nextTimeIn(Player*);
	
};

#endif
