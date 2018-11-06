/*Author: Meghan Dougherty
 *Date: 07/08/201*
 *Description: The main function that implements count_letters and output_letters.
 *Asks the user for the file they want to count the letters in, then runs the 
 *two letter counting programs, looping through each paragraph.
 */
 
#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios;

#include "countLetters.hpp"

int main()
{
	string fileName;
	
	int letterCount[26]= {0};
	
	ifstream fileIn;
	ofstream fileOut;
	
	char ch;

	//ask the user for the file for input.
	cout << "Please enter the name of the file you would like to open." << endl;
	cin >> fileName;
	
	//open the file
	fileIn.open(fileName.c_str());
	
	//if the file cannot be opened, ask again.
	while (!fileIn)
	{
		cin.clear();
		cin.ignore();
		cout << "Cannot open file " << fileName;
		cout << "Please enter the name of the file you would like to open." << endl;
		cin >> fileName;
		fileIn.open(fileName.c_str());
	}
		
	//read through the file paragraph by paragraph. 
	while(ch!=EOF)
	{	
		//make sure the array is reset to 0
		for(int i=0; i<26; i++)
			letterCount[i]=0;
			
		//cout letters
		count_letters(fileIn, letterCount);

		//create out put files
		output_letters(fileOut, letterCount);

		//check to see if the file is at the end.
		ch = fileIn.peek();	
	}

	//Close the input file	
	fileIn.close();
	
    return 0;
}

