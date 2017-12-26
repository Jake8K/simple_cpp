/**********************************************************************
 ** Function: avg() (average)
 ** Description: This is the header file for the avg() function
 *               It contains the function protoype
 ** Parameters: const double array[] (IN) is an array of doubles
 *                  that gets passed as a constant
 *              int arraySize (IN) is an int of the number of elements
 *                  in the array
 ** Pre-Conditions: an array of doubles
 ** Post-Conditions: a double containing the average (mean) of the 
 *                   elements in the array
 ***********************************************************************/

#ifndef summation_hpp
#define summation_hpp

#include <stdio.h>

double sum(const double array[], int arraySize);

#endif /* summation_hpp */
