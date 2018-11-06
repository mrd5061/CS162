/*Author: Meghan Dougherty
 *Date: 07/08/2018
 *Description: The function prototypes for the letter counting program. Includes
 *count_letters, which takes an input file and counts the letters of each 
 *paragraph and stores the info in an array,  and output_letters which outputs
 *the contents of the letter array to a user chosen text file. 
*/

//include guard. 
#ifndef LETTERS_H
#define LETTERS_H

//Allow use of file stream objects.
#include <fstream>
using std::ifstream;
using std::ofstream;

void count_letters(ifstream&, int*);
void output_letters(ofstream&, int*);

#endif
