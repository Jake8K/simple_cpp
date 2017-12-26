
/************************************************************************************************
 ** Program Filename: LabAa
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description: The program has 3 functions, main, sum(), and avg(). It adds up as many numbers
 *               as the user wants to enter and finds the average of the numbers by passing the
 *               numbers as a dynamic array to sum() and avg(), it then displays the results.
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
 ** Description: Main function prompts the user for the number of elements (numbers) they want in a
 *               dynamically allocated array, it then creates the array with that number of elements
 *               and prompts the user to enter the numbers they would like the program to find the
 *               average (mean) and the sum of. It then passes the array to the sum() and avg()
 *               functions and  displays the values returned to the user. Finally it frees up the
 *               dynamically allocated memory by erasing the array.
 ** Parameters: This function is passed no parameters
 ** Pre-Conditions: There are no preconditions for this function.
 ** Post-Conditions: Once the function terminates, the program should terminate and return 0.
 *****************************************************************************************************/

int main()
{
    int arraySize;
    
    cout << "How many numbers would you like to enter?" << endl;
    cin >>   arraySize;
    /* Check for numeric input from user */
    while (!cin || arraySize <= 0 ){
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            /* test from http://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer */
        }
        cout << "Please stick to positive whole numbers.\nHow many numbers would you like to enter?" << endl;
        cin >>   arraySize;
    }
    
    
    double *array = new double[arraySize];
    
    
    cout << "Please enter " << arraySize << " numbers to add up and average." << endl;
    for (int i = 0; i < arraySize; i++)
        cin >> array[i];
    
    
    cout << "The sum of these numbers is " << sum(array, arraySize) << " and the average is " << avg(array, arraySize) << ".\n";
    
    
    delete [] array;
    
    return 0;
}
