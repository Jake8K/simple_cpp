/***************************************************************************************
 ** Program Filename: Transformer.hpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation file for abstract base class
 *               Transformer. A polymorphic class that encrypts input files differently
 *               deppending on the subclass instance. transform(char) is a pure virtual
 *               each subclass has a specialized version of it. doFilter is virtual so
 *               that OrderedOutPut can use a specialized version of it.
 ** Input: An input file name, an integer if encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#ifndef Transformer_hpp
#define Transformer_hpp

#include <stdio.h>
#include <fstream>
using std::ifstream;
using std::ofstream;

class Transformer {
    
protected:
    char cChar;
    
public:
    virtual void doFilter(ifstream &in, ofstream &out);
    virtual char transform(char ch) = 0;
    
};

#endif /* Transformer_hpp */

