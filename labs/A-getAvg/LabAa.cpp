
/************************************************************************************************
 ** Program Filename: LabAa
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description: The program has 3 functions, main, sum(), and avg(). It adds up 10 numbers and 
 *               finds their average of the numbers by passing the numbers as a dynamic array to
 *               sum() and avg(), it then displays the results.
 ** Input: None
 ** Output: None
 ************************************************************************************************/

#include <iostream>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
#include "summation.hpp"
#include "average.hpp"

/*****************************************************************************************************
 ** Function: main
 ** Description: Main function initializes an array of doubles with consisting of 10 elements
 *               and prompts the user to enter 10 numbers they would like the program to find the
 *               average (mean) and the sum of. It then passes the array to the sum() and avg()
 *               functions and  displays the values returned to the user. 
 ** Parameters: This function is passed no parameters
 ** Pre-Conditions: There are no preconditions for this function.
 ** Post-Conditions: Once the function terminates, the program should terminate and return 0.
 *****************************************************************************************************/

int main()
{
    
    double array[10];
    
    
    cout << "Please enter 10 numbers to add up and average." << endl;
    for (int i = 0; i < 10; i++)
        cin >> array[i];
    
    
    cout << "The sum of these numbers is " << sum(array, 10) << " and the average is " << avg(array, 10) << ".\n";
    
    

    return 0;
}
