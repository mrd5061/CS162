/*Name: Meghan Dougherty
 * Date:  7/01/2018
 * Description: This is the main function file for the Langtons Any simulator. 
 * this file ties together the menu, ant, board, and sim functions to create
 * a working program
 */
 


//Header files
#include "menu.hpp"
#include "ant.hpp"
#include "antSimulation.hpp"
 

int main()
{
	//Create an Ant Object
	Ant lsAnt;

	//Display the menu
	mainMenu();
	
	//accept and validate the menu choice
	int choice = getChoice();

	//Run the simulation if 1 is chosen.
	while(choice == 1)
	{	
		//Simulatior function.
		antSimulation(&lsAnt);
	
		//Reset the ant's Orientation to the default.
		lsAnt.setAntOrient('N');

		//Display the menu to re-run the simulator.
		retryMenu();
		
		//Accept and validate the choice.
		choice = getChoice();
	} 
	
	//If the user choes to quit.
	if (choice==2)
	{
		exitMessage();		
		return 0;
	}

}

