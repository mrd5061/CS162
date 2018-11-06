/*Author: Meghan Dougherty
Date:
Description: The function declaration file for the Building class. Makes building objects that represent
buildings on the Oregon State University Campus. Includes name, size (in square feet), and address 
information for the buildings. 

*/
#ifndef BUILDING_H
#define BUILDING_H
#include <string>

using std::string;

class Building
{
private:

	string name;
	int size;
	string address;

public:
	Building(string n, int s, string a);

	string getName();
	int getSize();
	string getAddress();

	void setName(string);
	void setSize(int);
	void setAddress(string);
};

#endif 