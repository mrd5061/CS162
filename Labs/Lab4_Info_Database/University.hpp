/*Author: Meghan Dougherty
Date:
Description: The class definition file for the University Class. This class contains the name of the university 
a constant (Oregon State University) and two arrays of pointers to Building and Person objects. Also contains
menu functions for the University database.


*/
#ifndef UNIV_H
#define UNIV_H

#endif
#include <string>
#include "Person.hpp"
#include "Building.hpp"

using std::string;

class University
{
private: 
	 const string name = "Oregon State University";
	 Building **buildingArray;
	 Person **personArray;
public:
	University();
	~University();
	string getName();
	void printPeople();
	void printBuildings();

	void mainMenu();
	void doWorkMenu();
	void doWorkChoice(int);

}; 