/***************************************************************************************
 ** Program Filename: Transformer.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is the function implementation file for abstract base class 
 *               Transformer. A polymorphic class that encrypts input files differently 
 *               deppending on the subclass instance.
 ** Input: An input file name, an integer if encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include <fstream>
#include "Transformer.hpp"

/*****************************************************************************************
 ** Function: doFilter(ifstream &in, ofstream &out)
 ** Description: This base class function is inherited and called by the subclasses to 
 *               properly manipulate their input files and write it to output.
 ** Parameters: an ifstream object and an ofstream object
 ** Pre-Conditions: An open input and output file
 ** Post-Conditions: the output file is written to and the input file is ready to re-use.
 ****************************************************************************************/
void Transformer::doFilter(ifstream &in, ofstream &out) {
    char ch;
    
    while (!in.eof()) {
        
        //get input
        in.get(cChar);
        
             // filter out all non-alphaneumeric characters.
        if (isalnum(cChar) && cChar != '\n') {    // !ispunct()
            
            //manipulate input
            ch = transform(cChar);
    
            //append output
            out.put(ch);
        }
        else if (cChar == ' ') { // keep the white spaces
            transform(cChar);
            out.put(cChar);
        }
    }
    out << std::endl << std::endl;
    
    // reset the eof flag and rewind the file
    in.clear();
    in.seekg(0L, std::ios::beg);
}