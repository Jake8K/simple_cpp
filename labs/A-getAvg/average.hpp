/****************************************************************************
 ** Function: sum() (summation)
 ** Description: This is the header file for the summation function
 *               It contains the function protoype
 ** Parameters: const double array[] (IN) is an array of doubles 
 *                  that gets passed as a constant
 *              int arraySize (IN) is an int of the number of elements
 *                  in the array
 ** Pre-Conditions: an array of doubles
 ** Post-Conditions: a double containing the sum of the elements in the array
 ****************************************************************************/

#ifndef average_hpp
#define average_hpp

#include <stdio.h>

double avg(const double array[], int arraySize);

#endif /* average_hpp */
