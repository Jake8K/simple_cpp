/*********************************************************************
 ** Program Filename: List.hpp
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description: List class declaration file for List object, creates a dynamically 
 *                  allocated array of pointer to pointers and adds, removes, and 
 *                  displays the items held, it also adds up the subottals of all 
 *                  items in the array and displays the total cost of all items. At 
 *                  the end it also erases the array to free up the memory.
 ** Input: None
 ** Output: dynamically allocated array of pointer to Item pointers
 *********************************************************************/

#ifndef List_hpp
#define List_hpp


#include <stdio.h>
#include "Item.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class List {
    
private:
    int arraySize;
    Item *listArray;
    int listItemsTotal;

public:
    List();
    void addItem(Item newItem);
    void removeItem(std::string unwanted);
    double totalCost();
    void displayItems();
    ~List();
    
    
};

#endif /* List_hpp */
