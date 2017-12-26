/***************************************************************************************
 ** Program Filename: RONcalc.cpp
 ** Author: Jacob Karcz
 ** Date: 7.10.2016
 ** Description: This is the function implementation file for a reverse polish notation
 *               calculator class
 ** Input: as required by the function
 ** Output: as required by the function
 ***************************************************************************************/

#include "RPNcalc.hpp"


/*****************************************************************************************
 ** Function: RPNcalc( string, Stack)
 ** Description: A function that prompts the user for an arguement (in Reverse Polish
 *               Notation) to mathematically evaluate. The function then treats the
 *               string as an array and evaluates the characters within. If they are
 *               numbers they are added to the stack and if they are one of the 4 basic
 *               arithematic operands (+, -, *, /) it pops 2 numbers from the stack to
 *               evaluate and pushes the result onto the stack. Once the function has
 *               gone through the entire string, the function prints and returns the
 *               number storeed in the top of the stack.
 ** Parameters: a string in RPN to evaluate and the Stack instance it will work on
 ** Pre-Conditions: an instance of Calculator
 ** Post-Conditions: the result of the Reverse Polish Notation expression evaluated
 ****************************************************************************************/
/*
int RPNcalc(string expression, Stack calcStack) {
    
    //Stack calcStack;
    double  first,
            second,
            result;
    
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;
        
        else if(expression[i] == '+') {
            first = calcStack.peek() - '0';
            calcStack.pop();
            second = calcStack.peek() - '0';
            calcStack.pop();
            //calcStack.push(first + second);
            calcStack.push(second + first);
        }
        else if(expression[i] == '-') {
            
            first = calcStack.peek() - '0';
            calcStack.pop();
            second = calcStack.peek() - '0';
            calcStack.pop();
            //calcStack.push(first - second);
            calcStack.push(second - first);
            
            
        }
        else if(expression[i] == '*'){
            
            first = calcStack.peek() - '0';
            calcStack.pop();
            second = calcStack.peek() - '0';
            calcStack.pop();
            //calcStack.push(first * second);
            calcStack.push(second * first);
        }
        else if(expression[i] == '/'){
            
            first = calcStack.peek() - '0';
            calcStack.pop();
            second = calcStack.peek() - '0';
            calcStack.pop();
            //calcStack.push(first / second);
            calcStack.push(second / first);
        }
        else{
            calcStack.push(expression[i] - '0');
        }
    }
    cout << "The result of the expression is: " << calcStack.peek();
    cout << "\n\n";
    
    result = calcStack.peek();
    
    
    return result;

}
*/

/*****************************************************************************************
 ** Function: RPNcalc()
 ** Description: A function that prompts the user for an arguement (in Reverse Polish 
 *               Notation) to mathematically evaluate. the function then turns the string
 *               into a stream object and evaluates the characters within. If they are 
 *               numbers they are added to the stack and if they are one of the 4 basic 
 *               arithematic operands (+, -, *, /) it pops 2 numbers from the stack to 
 *               evaluate and pushes the result onto the stack. Once the function has 
 *               gone through the entire string, the function prints and returns the
 *               number storeed in the top of the stack.
 ** Parameters: None
 ** Pre-Conditions: an instance of Calculator
 ** Post-Conditions: the result of the Reverse Polish Notation expression evaluated
 ****************************************************************************************/
int Calculator::RPNcalc() {
/*
    Stack calcStack;
    int i;
    float num,
          result,
          first,
          second;
    string str,
           str1;
    //std::stringstream *is;
*/
    
    cout << "Enter a mathematical arguement in Reverse Polish Notation \n"
    << "for the program to evaluate:\n\n";
    getline(cin,str);
    //is(str);
    std::istringstream is(str);

    
    for( ; is >> str1; ){
        
        if(str1.compare("+") == 0){
            first = calcStack.peek();
            calcStack.pop();
            second = calcStack.peek();
            calcStack.pop();
            //calcStack.push(first + second);
            calcStack.push(second + first);
        }
        else if(str1.compare("-") == 0){
            
            first = calcStack.peek();
            calcStack.pop();
            second = calcStack.peek();
            calcStack.pop();
            //calcStack.push(first - second);
            calcStack.push(second - first);
            
            
        }
        else if(str1.compare("*") == 0){
            
            first = calcStack.peek();
            calcStack.pop();
            second = calcStack.peek();
            calcStack.pop();
            //calcStack.push(first * second);
            calcStack.push(second * first);
        }
        else if(str1.compare("/") == 0){
            
            first = calcStack.peek();
            calcStack.pop();
            second = calcStack.peek();
            calcStack.pop();
            //calcStack.push(first / second);
            calcStack.push(second / first);
        }
        else{
            calcStack.push(strtof(str1.c_str(),NULL));
        }
    }
    cout << "The result of the expression is: " << calcStack.peek();
    cout << "\n\n";
    
    result = calcStack.peek();
    
    //rewind string stream?????????????
    
    return result;
}

