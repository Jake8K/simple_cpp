//
//  BubbleSort.cpp
//  labG
//
//  Created by Jacob Karcz on 8/2/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "BubbleSort.hpp"

void BubbleSort(int array[], int arraySize) {
    for (int j = (arraySize -1); j >= 0; j--) {
        for (int k = 1; k <= j; k++) {
            if (array[k-1] > array[k]) {
                int temp = array[k-1];
                array[k-1] = array[k];
                array[k] = temp;
            }
        }
    }
}
