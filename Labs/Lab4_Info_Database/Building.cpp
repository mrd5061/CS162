/*Author: Meghan Dougherty
Date:07/22/2018
Description: The function definition file for the Building class. Includes getters and setters for all of the
building class variables. 


*/

#include <string>
#include "Building.hpp"
using std::string;

/* Building: constructor. Takes three arguments, a string for name, an int for size
and a string for address and initializes the member variables. 
*/
Building::Building(string n, int s, string a)
{
	name = n;
	size = s;
	address = a;
}

/* The following 3 functions are getters for all of the Building class member variables.  
They take no arguments and return the corresponding variables for the called building object.
*/


string Building::getName()
{
	return (this->name);
}
int Building::getSize()
{
	return (this->size);

}
string Building::getAddress()
{
	return (this ->address);
}

/* The following 3 functions are setters for all of the Building class member variables.
They take either a string or an int argument and and use those variables to set the 
appropriate object variable. 
*/

void Building::setName( string n)
{
	name = n;
}
void Building::setSize(int s)
{
	size = s;
}
void Building::setAddress(string a)
{
	address = a;
}