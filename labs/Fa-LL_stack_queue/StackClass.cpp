
/***************************************************************************************
 ** Program Filename: StackClass.cpp
 ** Author: Jacob Karcz
 ** Date: 7.26.2016
 ** Description: The function implementation file for class StackClass. The class creates
 *               and manages a dynamic stack data structure that holds data of type int.
 *               -isEmpty() returns true if the structure is empty
 *               -push(int) adds an integer to the (top) of the stack
 *               -peek() returns the item at the top of the stack
 *               -pop() deallocates and removes the item at the top of the stack
 ** Input: as needed by the fucntions, otherwise dependent on programmer implementation
 ** Output: a dynamic stack
 ***************************************************************************************/



#include "StackClass.hpp"


/*****************************************************************************************
 ** Function: default constructor
 ** Description: default constructor for LinkList class,
 *               initializes top pointer to NULL
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: An empty stack with an empty node & all pointers set to NULL
 ****************************************************************************************/
StackClass::StackClass() {
    this->top = NULL;
}
/*****************************************************************************************
 ** Function: push(int num)
 ** Description: Adds a node to the "top" of the stack with the int passed.
 *               If it's the first item in the stack then it creates a node for the int.
 *               Else if it's not the first node it adds the int to the "top" of the stack
 *               (creating a node for it) simultaneously updating the top pointer.
 ** Parameters: an int
 ** Pre-Conditions: the stack has been instantiated by the constructor (top == NULL)
 ** Post-Conditions: a first or new node containing the passed data is added to the stack
 ****************************************************************************************/
void StackClass::push(int num) {
    
    top = new StackNode(num, top);
  /*
    if (isEmpty()) {
        top = new StackNode(num);
        //head->next = head;
        //tail = head;
    }
    
    else {
        top->next = new StackNode(num);
        top = top->next;
    }
   */
}

/*****************************************************************************************
 ** Function: peek()
 ** Description: Returns the node pointed to by the top pointer,
 *               if there isn't one it returns NULL
 ** Parameters: None
 ** Pre-Conditions: The stack exists (if it doesn't, nothing happens... returns NULL)
 ** Post-Conditions: returns the int data member of the node at the top of the stack
 ****************************************************************************************/
int StackClass::peek() const {
    if (!isEmpty()) {
        return top->data;
    }
    
    return NULL;
}

/*****************************************************************************************
 ** Function: pop()
 ** Description: deletes the node at the top of the stack
 ** Parameters: None
 ** Pre-Conditions: A stack exists
 ** Post-Conditions: the node pointed to by top pointer is deallocated
 ****************************************************************************************/
void StackClass::pop() {
    
    StackNode *temp;
    
    if (isEmpty()) {
        std::cout << "The stack is empty, unable to complete operation.\n";
        return;
    }
    else {
//        num = top->data;
        temp = top;
        top = top->next;
        delete temp;
    }
}

/*****************************************************************************************
 ** Function: isEmpty()
 ** Description: a boolean function that returns true if the stack is empty or
 *               false if it isn't empty.
 ** Parameters: None
 ** Pre-Conditions: A stack exists
 ** Post-Conditions: fucntion returns true or false
 ****************************************************************************************/

bool StackClass::isEmpty() const {
    if (!top)
        return true;
    else
        return false;
    
}
/*****************************************************************************************
 ** Function: Destructor
 ** Description: Deallocates the data contained in the stack by calling the 
 *               pop() function until the stack is empty
 *                  *commented code could be implemented for use in a circular stack
 ** Parameters: None
 ** Pre-Conditions: An instance of the class
 ** Post-Conditions: Poof. The stack is gone and the memory is free again.
 ****************************************************************************************/
StackClass::~StackClass()
{
    //StackNode *nodePtr = this->top;  // Start at top of the stack
    
    while(!isEmpty()) {
        pop();
        
        /*
        // garbage keeps track of next node to be deleted
        StackNode *garbage = nodePtr;
        
        // Delete the "garbage" node
        delete garbage;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next; //seg fault here
         */
    }
}

