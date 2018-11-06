/*Author: Meghan Dougherty
Date: 07/22/2018
Description: The function definition file for the Person Class. Includes a default constructor and getters 
and setters for the Person variables. 

*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Person.hpp"
using std::string;

/* Person: Constructor. Generates a random number from 18 to 80 and initializes the age variable. 
*/
Person::Person()
{
	age = rand() % 62 + 18;
}

/* getAge: Takes no arguments. returns the person object's age. 
*/
int Person::getAge()
{
	return (this->age);
}

/* getName: Takes no arguments. returns the person object's name. 
*/
string Person::getName()
{
	return (this->name);
}

/* set name: Takes a string argument. Sets the person object's name. 
*/
void Person::setName(string n)
{
	name = n;
}
