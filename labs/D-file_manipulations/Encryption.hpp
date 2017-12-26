/***************************************************************************************
 ** Program Filename: Encryption.hpp
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

#ifndef Encryption_hpp
#define Encryption_hpp

#include <stdio.h>
#include "Transformer.hpp"


class Encryption : public Transformer {
    
private:
    int key;
    char mutilatedChar;
    
public:
    Encryption(int key); 
    virtual char transform(char ch);
    
};

#endif /* Encryption_hpp */

