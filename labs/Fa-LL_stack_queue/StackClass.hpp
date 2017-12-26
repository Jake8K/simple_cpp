/***************************************************************************************
 ** Program Filename: StackClass.hpp
 ** Author: Jacob Karcz
 ** Date: 7.26.2016
 ** Description: The StackClass class declaration file. A dynamic stack data structure
 *               that holds data variables of type int.
 *               -isEmpty() returns true if the structure is empty
 *               -push(int) adds an integer to the (top) of the stack
 *               -peek() returns the item at the top of the stack
 *               -pop() deallocates and removes the item at the top of the stack
 ** Input: as needed by the fucntions, otherwise dependent on programmer implementation
 ** Output: a dynamic stack
 ***************************************************************************************/

#ifndef StackClass_hpp
#define StackClass_hpp

#include <iostream>
class StackClass {
    
protected:
    struct StackNode {
        int data;
        StackNode *next;
        StackNode(int num, StackNode *nextN = NULL) {
            data = num;
            next = nextN;
        }
    };
    StackNode *top;
    
public:
    //constructor & destructor
    StackClass();
    ~StackClass();
    
    //member functions
    void push(int num);
    int peek() const;
    void pop(); //void pop(int &num);
    bool isEmpty() const;
    
};

#endif /* StackClass_hpp */
