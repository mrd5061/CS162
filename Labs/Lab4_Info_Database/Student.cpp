/*Author: Meghan Dougherty
Date:
Description: The function definition file for the Student class. Includes a getter and a setter for the rating variable
as well as an overridden versions of the do_work and printVar functions inherited from the Person Class.


*/
#include <string>
#include <iostream>
#include <iomanip>
#include "Student.hpp"
using std::string;
using std::cout;
using std::setprecision;
using std::fixed;
using std::endl;

/* Student: default constructor. sets GPA to 0.00 and the Name to " ". Inherits age from the Person constructor.
*/
Student::Student()
{
	name = " ";
	GPA = 0.00;
}
/* Student: Constructor. Takes a string and a double as arguments. Sets name (string)
and GPA(double) on object creation. Inherits age from the Person constructor.
*/
Student::Student(string n, double g)
{
	name = n;
	GPA = g;
}

/* printVar: inherited from Person class. Takes no arguments. Prints the
GPA of the student object.
*/
void Student::printVar()
{
	cout << "GPA: " << fixed << setprecision(1) << GPA << endl;
}
/* setGPA: Takes a double as an argument. Sets the GPA of the Student object.
*/
void Student::setGPA(double g)
{
	GPA = g;
}
/* getGPA: Takes no arguemtn. Returnss the GPA of the Student object.
*/
double Student::getGPA()
{
	return GPA;
}

/* do_work(): Inherited from Person class. takes no arguments. Retrieves the
name of the associated person object and prints a random number x to represent
the number of hours the person worked.
*/
void Student::do_work()
{
	//Random number from 1 to 24
	int x = rand() % 23 + 1;

	//Print results.
	cout << this->getName() << " did " << x << " hours of homework";
}