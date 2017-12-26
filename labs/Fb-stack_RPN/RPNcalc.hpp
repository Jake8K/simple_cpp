/***************************************************************************************
 ** Program Filename: RPNcalc.cpp
 ** Author: Jacob Karcz
 ** Date: 7.10.2016
 ** Description: This is the class declaration file for a reverse polish notation
 *               calculator class
 ** Input: as required by the function
 ** Output: as required by the function
 ***************************************************************************************/

#ifndef RPNcalc_hpp
#define RPNcalc_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Stack.hpp"
using std:: string;
using std::cout;
using std::cin;

class Calculator {
private:
    Stack calcStack;
    int i;
    float num,
        result,
        first,
        second;
    string str,
        str1;
public:
    int RPNcalc();
    
};


//int RPNcalc(string, Stack);
//int RPNcalc();

#endif /* RPNcalc_hpp */
