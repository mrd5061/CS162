

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "menu.hpp"

void mainMenu()
{
	cout << "Welcome to the Langton's Ant Simulation!" << endl;
	cout << "Please select one of the following options:" <<endl;
	cout << " 1. Start the simulation." << endl;
	cout << " 2. Quit. " << endl;
	
	 
}

void retryMenu()
{
	cout << "Would you like to run another simulation?" << endl;
	cout << "Please select one of the following options:" <<endl;
	cout << " 1. Start a new simulation." << endl;
	cout << " 2. Quit. " << endl;
	
}
void exitMessage()
{
	cout << "Thank you for using the simulator." << endl;
	cout << "Good Bye!" << endl;
	
}
int getChoice()
{
	int choice;
	
	cin >> choice;
	
	while (!cin|| !(choice==1 || choice==2))
	{
		cin.clear();
		cin.ignore();
		
		cout << "That was an invalid input" << endl;
		cout << "Please select one of the following options:" <<endl;
		cout << " 1. Start a new simulation." << endl;
		cout << " 2. Quit. " << endl;
		
		cin >> choice;
	}
	
	return choice;	

}

