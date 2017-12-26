/***************************************************************************************
 ** Program Filename: OrderedOutput.hpp
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
#ifndef OrderedOutput_hpp
#define OrderedOutput_hpp

#include <stdio.h>
#include "Transformer.hpp"

class OrderedOutput : public Transformer {
    
private:
    int key;
    char orderedChar;
    
public:
    OrderedOutput(int key);
    virtual void doFilter(ifstream &in, ofstream &out);
    virtual char transform(char ch);
};

#endif /* OrderedOutput_hpp */
