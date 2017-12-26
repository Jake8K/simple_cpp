/***********************************************************************************
 ** Function: avg() (average.cpp)
 ** Description: This is a simple function that gets passed an array as a constant
 *               and computes the average (mean) of the doubles in the array.
 ** Parameters: const double array[] (IN) is an array of doubles
 *              int arraySize (IN) is the number of elements in the array
 ** Pre-Conditions: an array of doubles containing as many elements as the int
 *                  arraySize dictates
 ** Post-Conditions: returns a double containing the mean average of the values 
 *                   within the array
 ***********************************************************************************/

#include "average.hpp"

double avg(const double array[], int arraySize)
{
    double sum = 0; //initialize the sum as 0
    
    for (int i = 0; i < arraySize; i++)
        sum += array[i];
    
    double average = sum / arraySize;
    
    return average;
}