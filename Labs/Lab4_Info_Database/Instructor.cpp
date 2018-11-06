/*Author: Meghan Dougherty
Date: 07/22/2018
Description: The function definition file for the Instructor class. Includes a getter and a setter for the rating variable
as well as an overridden versions of the do_work and printVar functions inherited from the Person Class. 


*/

#include <string>
#include <iostream>
#include <iomanip>

#include "Instructor.hpp"
using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

/* Instructor: Default constructor. Takes no arguments. Sets the rating to 0.00 and name
to " ". Inherits age from the Person constructor.

*/
Instructor::Instructor()
{
	name = " ";
	rating = 0.00;
}

/* Instructor:Constructor. Takes two arguments, a string and a double.
Sets the name (string) and rating(r) of the instructor object. Inherits age from the Person constructor.
*/
Instructor::Instructor(string n, double r)
{
	name = n;
	rating = r;
}

/* printVar: inherited from Person class. Takes no arguments. Prints the 
rating of the instructor object. 
*/
void Instructor::printVar()
{
	cout << "Rating: " << fixed << setprecision(1) << rating << endl;
}

/* setRating: Takes a double as an argument. Sets the rating of the instructor object.
*/
void Instructor::setRating(double r)
{
	rating = r;
}

/* setRating: Takes no arguments. Returns the rating of the instructor object.
*/
double Instructor::getRating()
{
	return rating;
}

/* do_work(): Inherited from Person class. takes no arguments. Retrieves the
name of the associated person object and prints a random number x to represent
the number of hours the person worked.
*/
void Instructor::do_work()
{
	//Random number from 1 to 24. 
	int x = rand() % 23 + 1;

	//Print result.
	cout << this->getName() << " graded papers for " << x << " hours";
}
