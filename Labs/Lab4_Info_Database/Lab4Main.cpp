/*Author: Meghan Dougherty
Date: 07/22/2018
Description: The main function file for the Oregons State Database. Creates an OSU university object and 
implements the various menus as needed.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>

#include "University.hpp"
#include"Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"

using std::cout;
using std::cin;
using std::endl;

using std::getline;

int main()
{
	string choice;
	char a;
	int n;

	//seed the random number generators.
	srand(static_cast<unsigned int> (NULL));

	//Create the university object. 
	University OSU;

	//Greet the user. 
	cout << "Welcome to the " << OSU.getName() << " database." << endl;

	//While the user wants to continue, reprint the main menu.
	do
	{
		OSU.mainMenu();

		cout << "Would you like to continue? Y/N." << endl;

		//Get and validate the user's choice.
		getline(cin, choice);
		
		//Make sure the input is either Y/y or N/n
		while (!cin || choice.length() != 1 || !(toupper(choice[0]) == 'Y' || toupper(choice[0]) == 'N'))
		{
			//Print Error and re retrieve the user's choice. 
			cout << "Invalid Input. Please enter Y for yes or N for no." << endl;
			getline(cin, choice);

		}
		
	} while  (toupper(choice[0]) == 'Y');
	
	//Bid the user farewell.
	cout << "Goodbye!" << endl;
	return 0;
	
}
