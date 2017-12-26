/***************************************************************************************
 ** Program Filename: Encryption.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation for polymorphic subclass Encryption
 *               This class is initialized with an int that is passed to its constructor. 
 *               It's virtual function, transform(char) encrypts the char it is passed 
 *               with the int passed as a key to the constructor. When its virtual
 *               function is called by doFilter, the input file's contents are are 
 *               encrypted in the output file, with every letter being augmented by the 
 *               key according to the corresponding ASCII letter assignation.
 ** Input: An input file name, an integer for encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include "Encryption.hpp"


/*****************************************************************************************
 ** Function: Encryption constructor
 ** Description: It calls the base class constructor in the initialization list to 
 *               initialize most variables, but it sets the Encryption class's special
 *               key member variable according to the int passed as a parameter.
 ** Parameters: an int
 ** Pre-Conditions: None
 ** Post-Conditions: A class instance is instantiated
 ****************************************************************************************/
Encryption::Encryption(int k) : Transformer() {
    key = k;
}


/*****************************************************************************************
 ** Function: transformer()
 ** Description: thsi is a virtual function that is passed a character to encrypt as a
 *               parameter. The function then takes the instances key and adds it to the 
 *               char's ASCII numerical value, it then takes the modulus 26 of this 
 *               instance and adds 97 to ensure the char is still a letter. It then 
 *               returns this new char. When called by doFilter, the out file is encrypted.
 ** Parameters: a char
 ** Pre-Conditions: a char exxists
 ** Post-Conditions: the char has been encrypted by the key and returned by the function
 ****************************************************************************************/
char Encryption::transform(char ch) {
    int temp = (int) ch;
    temp += key;
    temp = temp % 26 +97;
    mutilatedChar = static_cast<char>(temp);
    return mutilatedChar;
}