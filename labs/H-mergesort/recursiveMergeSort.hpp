//
//  recursiveMergeSort.hpp
//  LabH
//
//  MergeSort code from: http://www.geeksforgeeks.org/iterative-merge-sort/
//      Written by Shivam Agrawal
//          (ref: http://csg.sph.umich.edu/abecasis/class/2006/615.09.pdf)
//


#ifndef recursiveMergeSort_hpp
#define recursiveMergeSort_hpp

#include <stdio.h>
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void rMerge(int array[], int left, int middle, int right);

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void rMergeSort(int array[], int left, int right);


#endif /* recursiveMergeSort_hpp */
