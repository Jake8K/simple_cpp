/***************************************************************************************
 ** Program Filename: Copy.hpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation file for polymorphic subclass Copy
 *               This class simply copies a character as it is passed. When its virtual
 *               function is called by doFilter, it copies an input file's data into an
 *               output file, but deletes any punctuation or newline characters.
 ** Input: An input file name, an integer if encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#ifndef Copy_hpp
#define Copy_hpp

#include <stdio.h>
#include "Transformer.hpp"


class Copy : public Transformer {

private:
    char copyChar;
    
public:
    virtual char transform(char ch);
    
};


#endif /* Copy_hpp */
