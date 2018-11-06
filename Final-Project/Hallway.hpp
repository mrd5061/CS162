/*Author: Meghan Dougherty
Date: 8/15/2018
Description: The declaration for the Escape Pod Class, a public cop of Space.

*/

#include "Space.hpp"


class Hallway : public Space
{


public:
	Hallway();

	void firstTimeIn(Player*);
	void nextTimeIn(Player*);


};
