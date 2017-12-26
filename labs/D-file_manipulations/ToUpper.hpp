/***************************************************************************************
 ** Program Filename: ToUpper.hpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation for polymorphic subclass ToUpper
 *               It's virtual function, transform(char) returns the uppercase letter of
 *               the char it is passed. When it's called by doFilter, the input file's
 *               contents are are copyed as uppercase letters to the output file
 ** Input: An input file name
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#ifndef ToUpper_hpp
#define ToUpper_hpp

#include <stdio.h>
#include "Transformer.hpp"


class ToUpper : public Transformer {
    
private:
    char upperChar;
    
public:
    virtual char transform(char ch);
    
};

#endif /* ToUpper_hpp */
