/*Author: Meghan Dougherty
Date:
Description: The Function declaration fiel for the Instructor Class. Derived from the Person Class and inherits the name
and age variables from Person. Has a private variable for the instructor rating, as well as two inherited and overridden.
functions do_work and printVar. 


*/
#ifndef INSTRUCT_H
#define INSTRUCT_H
#include "Person.hpp"
using std::string;

class Instructor : public Person
{
private:
	double rating;

public:
	Instructor();
	Instructor(string, double);

	void printVar();
	void setRating(double);
	double getRating();
	void do_work();
};
#endif