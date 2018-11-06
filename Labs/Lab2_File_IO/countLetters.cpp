#include <string>
#include<fstream>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
#include "countLetters.hpp"

/* count_letters: read the paragraph string from the inputfile stream, then 
 * counts the frequenceies of the paragraph and stores the frequences in the 
 * array, making no distinction between upper and lower case. Takes an ifstream
 * object and an array pointer as arguments. 
 */ 
void count_letters(ifstream& fileIn, int* array)
{
	string paragraph;
	char letter;
		 	
	//Read the paragraph, stopping at the new line character.
	
	getline(fileIn, paragraph,'\n');
	
	for(int i=0; i<=paragraph.length(); i++)
	{	
		if(isalpha(paragraph[i]))
		{
			//convert all letters to lowercase.
			letter = tolower(paragraph[i]);
	
			/*The location in the array is the
			selected letter minus the numeric
			value of lowercase a. Thus 'a' is
			location 0, 'b' is 1, etc8*/
			array[letter-'a']++;
		}
		
	}		
		
	

}

/* output_letters: first asks user for the file name the user would like to 
 * output to, then ouputs contents of the letter frequencies array. Takes an
 * ofstream object and an array pointer as arguments. 
 */ 
void output_letters(ofstream& fileOut, int* array)
{
	string output;
	char letter = 'a';

	//Ask user to name output file.
	cout << "What file name would you like to output to?"<< endl;
	cin >> output;
	
	//open the file.
	fileOut.open(output.c_str());
	
	//read the array info into the file with correct formatting.
	for(int r=0; r<26;r++)
		fileOut << static_cast<char>(letter+r) << " : " << array[r] <<endl;
	//close the file.
	fileOut.close();
	
}
