/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Kitchen Class, a public cop of Space.

*/
#include "Space.hpp"

class Kitchen : public Space
{


public:
	Kitchen();

	void firstTimeIn(Player*);
	void nextTimeIn(Player*);


};