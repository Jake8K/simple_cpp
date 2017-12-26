//
//  iterativeMergeSort.hpp
//  LabH
//
//  MergeSort code from: http://www.geeksforgeeks.org/iterative-merge-sort/
//      Written by Shivam Agrawal
//          (ref: http://csg.sph.umich.edu/abecasis/class/2006/615.09.pdf)
//

#ifndef iterativeMergeSort_hpp
#define iterativeMergeSort_hpp

#include <stdio.h>
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void iMerge(int array[], int left, int middle, int right);

// Utility function to find minimum of two integers
int min(int x, int y);


/* Iterative mergesort function to sort arr[0...n-1] */
void iMergeSort(int array[], int n);

#endif /* iterativeMergeSort_hpp */
