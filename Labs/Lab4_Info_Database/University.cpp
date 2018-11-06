/*Author: Meghan Dougherty
Date:07/22/2018
Description: The function definition file for the University class. This class includes a constructor and destructor of university
objects as well as functions for the program's main menus and the do_Work function. It also contains dynamically allocated
person and building arrays. 


*/
#include <string>
#include <iostream>

#include "University.hpp"
#include "Person.hpp"
#include "Instructor.hpp"
#include "Student.hpp"
#include "Building.hpp"


using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::getline;

/* University: Constructor. Takes no arguments. Initializes the building and person arrays to 50 null pointers. 
also manually creates 4 person objects and 2 building objects and places them in the appropriate arrays. 
*/
University::University()
{
	//Allocate the arrays.
	buildingArray = new Building*[10]();
	personArray = new Person*[10]();
	
	//Create People.
	personArray[0] = new Instructor ("Bill", 2.3);
	personArray[1] = new Student ("Jane", 4.0);
	personArray[2] = new Instructor("Eric", 4.9);
	personArray[3] = new Student("Amanda", 3.2);

	//Create Buildings. 
	buildingArray[0] = new Building ("Adam's Hall", 11168, "606 SW 15TH ST");
	buildingArray[1] = new Building("Milne Computer Center", 23441, "1800 SW CAMPUS WAY");
	
}
 
/* ~University: Destructor. Deletes the dynamically allocated arrays and frees the memory. 
*/
University ::~University()
{
	for (int i =0; i<10; i++)
	{
		delete buildingArray[i];
		delete personArray[i];
	}

	delete []buildingArray;
	delete []personArray;
}

/*getName: Takes no arguments. Returns the University's name as a string.
*/
string University::getName()
{
	return name;
}

/* printPeople: Takes no arguments. Prints out the names, ages and GPA/Rating of the people objects
in the people array. Ignores null pointers. 
*/
void University::printPeople()
{
	cout << "These are the people at Oregon State University \n" << endl;

	//Print the information of the people objects. 
	for (int i = 0; i < 10; i++)
	{	
		//If the pointer in the array is not null (there is a person object).
		if (personArray[i] != nullptr)
		{
			cout << "Name: " << personArray[i]->getName() << endl;
			cout << "Age: " << personArray[i]->getAge() << endl;

			//Prints GPA if the object is a student
			//Prints Rating if object is an instructor. 
			personArray[i]->printVar();
			cout << endl;
		}
	}

}

/* printBuildings: Takes no arguments. Prints the name, size (in square feet), and address of the 
building objects in the buildings array. Ignores null pointers.
*/
void University::printBuildings()
{
	cout << endl;
	cout << "These are the " << name << " buildings.\n" << endl;

	//Print the information int the person array.
	for (int i = 0; i < 10; i++)
	{	
		//If the pointer is not null (there is a building object)	
		if (buildingArray[i] != nullptr)
		{		
			cout << "Name: " << buildingArray[i]->getName() << endl;
			cout << "Size: " << buildingArray[i]->getSize() << " sqr ft."  << endl;
			cout << "Address: " << buildingArray[i]->getAddress() << endl;
			cout << endl;
		}
		
	}
}
/* mainMenu: Takes no arguments. 
*/
void University::mainMenu()
{
	string choice;
	int n;

	//Prints the main menu choices. 
	cout << "Main Menu: " << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Print information about all buildings." << endl;
	cout << "2. Print information about people at " << this->getName() << endl;
	cout << "3. Choose a person to do work." << endl;
	cout << "4. Exit the program. " << endl;

	//accept the input as a string.
	getline(cin, choice);

	//Verify if the input is a digit and the digit is one character long.
	if (isdigit(choice[0]) && choice.length()==1 )
		//convert the string to a digit.
		n = stoi(choice, nullptr, 10);
	else
		//Assign a garbage value to n otherwise. 
		n = -1;

	//If input is invalid, ask again.
	while (!cin || (n < 1 || n >4))
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a number between 1 and 4." << endl;
		getline(cin, choice);

		if (isdigit(choice[0]) && choice.length() == 1)
			n = stoi(choice, nullptr, 10);
		else
			n = -1;
	}
	


	//Switch menu based on the user's input
	switch (n)
	{
	case 1:
		this->printBuildings();
		break;
	case 2:
		this->printPeople();
		break;
	case 3:
		this->doWorkMenu();

		break;
	case 4:
		
		break;
	}
}

/* doWorkMenu: Takes no arguments. Prints the people at the university, then asks the user which person
they would like to do work. 
*/
void University::doWorkMenu()
{
	string input;
	int choice;
	int count = 0;

	//Print the people
	cout << "Here are the people at " << this->getName() << endl;
	for (int i = 0; i < 10; i++)
	{
		//If a person object exists.
		if (this->personArray[i] != nullptr)
		{   //print the name.
			cout << i + 1 << "." << this->personArray[i]->getName() << endl;
			//Add to the person count. Used for validation later.
			count++;
		}
	}
	
	cout << "Which person would you like to do work? " << endl;

	//get the input. 
	getline(cin, input);
	
	if (input.length() == 1 && isdigit(input[0]))
		choice = stoi(input);
	else
		choice = -1;

	//Make sure the input is valid (non negative and less or equal to the people who exist.).
	while (!cin||(choice<1 || choice > count))
	{
		
		cout << "Invalid Input." << endl;
		cout << "Please enter an integer." << endl;

		getline(cin, input);
		if (input.length() == 1 && isdigit(input[0]))
			choice = stoi(input);
		else
			choice = -1;
	}

	//Pass the user choice minus one (for indexing) to the do work choice function.
	doWorkChoice(choice - 1);
	

}

/* doWorkChoice: takes one integer as an argument. If the person exists at that integer index in the
Person array, the function makes that person do work. Otherwise, it prints that the person does not exist.
*/
void University::doWorkChoice(int i)
{
	//If a person object exists
	if (this->personArray[i] != nullptr)
	{
		//make them do work.
		this->personArray[i]->do_work();
		cout << endl;
	}
	else
		cout << "Person does not exist. " << endl;
}
