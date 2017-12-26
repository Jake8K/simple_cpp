/***************************************************************************************
 ** Program Filename: OrderedOutput.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation for polymorphic subclass OrderedOuput.
 *               This class is initialized with an int that is passed to its constructor.
 *               It's virtual function, transform(char) encrypts the char it is passed
 *               with the int passed as a key to the constructor and turns the resulting 
 *               char into an upper case letter This subclass also has a specialized
 *               verison of doFiler() which adds a space character ( ' ' )to the output 
 *               file every 5 characters. Once doFiler() is finished writing the input 
 *               file to output all of the letters are encrypted with the key, turned 
 *               uppercase, and had all of its spaces and punctuation removed. In addition
 *               all of the letters are grouped into "words" of 5 letters sperated by a 
 *               space.
 ** Input: An input file name, an integer for encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include "OrderedOutput.hpp"


/*****************************************************************************************
 ** Function: Encryption constructor
 ** Description: It calls the base class constructor in the initialization list to
 *               initialize most variables, but it sets the OrderedOuput class's special
 *               key member variable according to the int passed as a parameter.
 ** Parameters: an int
 ** Pre-Conditions: None
 ** Post-Conditions: A class instance is instantiated
 ****************************************************************************************/
OrderedOutput::OrderedOutput(int k){
    key = k;
}


/*****************************************************************************************
 ** Function: doFilter(ifstream &in, ofstream &out)
 ** Description: This is a specialized version of the base class function definition. 
 *               Unlike the parent class function, this one ignores white spaces and 
 *               encrypts all alphaneumeric characters with the classes transform() 
 *               function and adds a space every 5th character. The resulting output file 
 *               contains a caesar cipher of the input file.
 ** Parameters: an ifstream object and an ofstream object
 ** Pre-Conditions: An open input and output file
 ** Post-Conditions: the output file is written to and the input file is ready to re-use.
 ****************************************************************************************/
void OrderedOutput::doFilter(ifstream &in, ofstream &out) {
    char ch;
    int count = 0;
    
    while (!in.eof()) {
        
        in.get(cChar);
        
        if (isalnum(cChar) && cChar != '\n') {
            ch = transform(cChar);
            out.put(ch);
            count++;
        }
        //add a space
        if (count == 5) {
            out.put(' ');
            count = 0;
        }
    }
    out << std::endl << std::endl;
    in.clear();
    in.seekg(0L, std::ios::beg);
}


/*****************************************************************************************
 ** Function: transformer()
 ** Description: This is a virtual function that is passed a character to encrypt as a
 *               parameter. The function then takes the instances key and adds it to the
 *               char's ASCII numerical value, it then takes the modulus 26 of this
 *               instance and adds 97 to ensure the char is still a letter. It then
 *               turns the letter into an upper case character and returns it. When
 *               called on by the OrderedOutputs specialized doFilter() function, 
 *               the contents of the input file are written in caesar cipher.
 ** Parameters: a char
 ** Pre-Conditions: a char exxists
 ** Post-Conditions: the char is encrypted by the key, turned upper case and 
 *                   returned by the function
 ****************************************************************************************/
char OrderedOutput::transform(char ch) {
    int temp = (int) ch;
    temp += key;
    temp = temp % 26 +97;
    orderedChar = (char) temp;
    orderedChar = toupper(orderedChar);
    return orderedChar;
}
