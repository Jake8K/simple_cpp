//
//  recursiveMS.hpp
//  LabH
//
//  Created by http://www.cprogramming.com/tutorial/computersciencetheory/merge.html
//  
//

#ifndef recursiveMS_hpp
#define recursiveMS_hpp

#include <stdio.h>
int max(int x, int y);

void merge_helper(int *input, int left, int right, int *scratch);


int mergesort(int *input, int size);

#endif /* recursiveMS_hpp */
