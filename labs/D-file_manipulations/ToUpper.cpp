/***************************************************************************************
 ** Program Filename: ToUpper.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation for polymorphic subclass ToUpper
 *               It's virtual function, transform(char) returns the uppercase letter of
 *               the char it is passed. When it's called by doFilter, the input file's 
 *               contents are are copyed as uppercase letters to the output file
 ** Input: An input file name
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include "ToUpper.hpp"

/*****************************************************************************************
 ** Function: transform()
 ** Description: the cubclasses specialized virtual function which is passed a char and
 *               it returns the uppercase version of the letter.
 ** Parameters: a char
 ** Pre-Conditions: a char
 ** Post-Conditions: returns the uppercase char it was passed
 ****************************************************************************************/
char ToUpper::transform(char ch) {
    
    upperChar = toupper(ch);
    return upperChar;
}
