/***************************************************************************************
 ** Program Filename: main.cpp
 ** Author: Jacob Karcz
 ** Date: 7.10.2016
 ** Description: This is the driver function, the main function, 
 *               to test a reverse polish notation calculator object
 ** Input: a string of integers and any of the 4 basic arithmatic operands (+, -, /, *) 
 *         when prompted by the class
 ** Output: the result of the mathematical evaluation of the RPN input
 ***************************************************************************************/


#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Stack.hpp"
#include "RPNcalc.hpp"
using std:: string;
using std::cout;
using std::cin;

/*****************************************************************************************
 ** Function: Main Function
 ** Description: This is the driver function, the main function,
 *               to test a reverse polish notation calculator object
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: the result of the Reverse Polish Notation expression evaluated
 ****************************************************************************************/
int main() {
    
    Calculator *calc;

    calc = new Calculator;
    
    calc->RPNcalc();
    
    delete calc;
    
        
    
    return 0;
}
