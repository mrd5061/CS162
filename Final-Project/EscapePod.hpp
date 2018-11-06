/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Escape Pod Class, a public cop of Space. 

*/

#ifndef ESCAPE_POD
#define ESCAPE_POD
#include <string>
#include"Space.hpp"
#include "Player.hpp"

using std::string;

class EscapePod: public Space
{
public:

	EscapePod();
	void firstTimeIn(Player*);
	void nextTimeIn(Player*);
	
};

#endif