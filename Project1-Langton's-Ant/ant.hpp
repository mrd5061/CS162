/*Author: Meghan Dougherty
 * Date: 7/01/2018
 * Description: The header file for the Ant Class. Defines the variables and 
 * getter/setter functions for the Ant objects. 
*/

#ifndef ANT_H
#define ANT_H



class Ant

{
	private: 
		int antRow;
		int antCol;
		char antOrient; //Holds the cardinal direction of the ant. 
	public:
		//constructor
		Ant();
	
		//Getters.
		int getAntRow();
		int getAntCol();
		char getAntOrient();
		
		//Setters
		void setAntRow(int r);
		void setAntCol(int c);
		void setAntOrient(char d);

};
#endif 
