/*Author: Meghan Dougherty
Date:
Description: The class definition file for the Person Class. A polymorphic abstract class that Student and Instructor are derived
from. Constains getters and setters for the name and age variables as well as two pure virtual functions do_work and 
printVar. 


*/
#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

class Person
{
	protected:
		string name; 
		int age;
	public:
		Person();
		
		virtual void do_work() = 0;
		virtual void printVar() = 0;

		string getName();
		void setName(string);
		int getAge();


};
#endif 