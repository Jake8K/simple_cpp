/***************************************************************************************
 ** Program Filename: Copy.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation file for polymorphic subclass Copy
 *               This class simply copies a character as it is passed. When its virtual 
 *               function is called by doFilter, it copies an input file's data into an
 *               output file, but deletes any punctuation or newline characters.
 ** Input: An input file name, an integer if encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include "Copy.hpp"

/*****************************************************************************************
 ** Function: transform()
 ** Description: This function simply returns the same char that it is passed
 ** Parameters: a char
 ** Pre-Conditions: a char exists
 ** Post-Conditions: returns the same char it was passed
 ****************************************************************************************/
char Copy::transform(char ch) {
    
    copyChar = ch;
    return copyChar;
}