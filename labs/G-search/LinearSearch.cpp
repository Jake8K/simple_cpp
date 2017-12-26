//
//  LinearSearch.cpp
//  labG
//
//  Created by Jacob Karcz on 8/2/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//
#include <iostream>
#include "LinearSearch.hpp"
using std::cout;

int linearSearch(int array[], int arraySize, int intSought) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == intSought)
            return i;
        //cout << "I did enter the loop!\n";
    }
    return 99999;
}