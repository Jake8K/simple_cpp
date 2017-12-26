//
//  BinarySearch.cpp
//  labG
//
//  Created by Jacob Karcz on 8/2/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "BinarySearch.hpp"

int binarySearch (int array[], int arraySize, int intSought) {
    int min = 0;
    int max = (arraySize - 1);
    
    while (min <= max) {
        int middle = (min + max)/2; // cut the phonebook in half
        int difference = array[middle] - intSought; // compare centr elemnt to what I want
        if (difference == 0) // this is what I want
            return middle;
        else if (difference < 0) //what I'm looking for is in the top half of the search
            min = (middle + 1);
        else                     // what I want is in the lower half of the search field
            max = (middle - 1);
    }
    return -5;
}


/*
 
 while (min <= max) {
    int middle = (min + max)/2; // cut the phonebook in half
    int difference = array[middle] - intSought; // compare centr elemnt to what I want
    if (difference == 0) // this is what I want
        return middle;
    else if (difference < 0) //what I'm looking for is in the top half of the search
        min = (middle + 1);
    else                     // what I want is in the lower half of the search field
        max = (middle - 1);
 }

 


int binarySearch (int array[], int arraySize, int intSought) {
    int min = 0;
    int max = (arraySize - 1);
    
    while (min <= max) {
        int middle = (min + max)/2; // cut the phonebook in half
        // compare center elemnet to the number I'm looking for
        if ((array[middle] - intSought) == 0) // this is what I want
            return middle;
        else if (array[middle] - intSought < 0) //search in top half
            min = (middle + 1);
        else                     //search bottom half
            max = (middle - 1);
    }
    return -5;
}

*/
