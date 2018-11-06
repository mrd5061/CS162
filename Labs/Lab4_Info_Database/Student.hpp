/*Author: Meghan Dougherty
Date:
Description: The Function declaration fiel for the Student Class. Derived from the Person Class and inherits the name
and age variables from Person. Has a private variable for the student's GPA, as well as two inherited and overridden.
functions do_work and printVar. 


*/

#ifndef STUDENT_H
#define STUDENT_H
#include "Person.hpp"
using std::string;

class Student: public Person
{
private: 
	double GPA;
public:
	Student();
	Student(string, double);
	void printVar();
	void setGPA(double);
	double getGPA();
	void do_work();

};
#endif // !STUDENT_H

