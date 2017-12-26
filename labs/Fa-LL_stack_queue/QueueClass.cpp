/***************************************************************************************
 ** Program Filename: QueueClass.cpp
 ** Author: Jacob Karcz
 ** Date: 7.26.2016
 ** Description: The function implementation file for class QueueClass The class creates 
 *               and manages dynamic queue data structure that holds data variables of type int.
 *               -isEmpty() returns true if the structure is empty
 *               -addBack(int) adds an integer to the queue
 *               -getFront() returns the first integer in the queue
 *               -removeFront() deallocates and removes the first integer in the queue
 ** Input: as needed by the fucntions, otherwise dependent on programmer implementation
 ** Output: a dynamic queue
 ***************************************************************************************/

#include "QueueClass.hpp"

/*****************************************************************************************
 ** Function: default constructor
 ** Description: default constructor for QueueClass class,
 *               initializes front and back pointers to NULL
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: An empty queue with an empty node & all pointers set to NULL
 ****************************************************************************************/
QueueClass::QueueClass() {
    this->front = NULL;
    this->back = NULL;
}
/*****************************************************************************************
 ** Function: addBack(int num)
 ** Description: Adds a node to the back of the queue with the int passed. If it's the
 *               first item in the queue then it creates a node to hold the int and 
 *               sets front and back to point at it. Else if it's not the first node it
 *               adds the int to the back of the queue (creating a node for it) and 
 *               updates the back pointer.
 ** Parameters: an int
 ** Pre-Conditions: the queue has been instantiated by the constructor (pointers == NULL)
 ** Post-Conditions: a first or new node containing the passed data is added to the queue
 ****************************************************************************************/
void QueueClass::addBack(int num) {
    
    if (isEmpty()) {
        front = new Qnode(num);
        //front->next = front; //this would make it a circular queue (update destructor)
        back = front;
    }
    
    else {
        back->next = new Qnode(num);
        back = back->next;
    }
    
}

/*****************************************************************************************
 ** Function: getFront()
 ** Description: Returns the node pointed to by the head pointer, 
 *               if there isn't one it returns NULL
 ** Parameters: None
 ** Pre-Conditions: The queue exists (if it doesn't, nothing happens... returns NULL)
 ** Post-Conditions: returns the int data member of the node at the front of the queue
 ****************************************************************************************/
int QueueClass::getFront() const {
    if (isEmpty()) {
        //std::cout << "The queue is empty, unable to complete operation.\n";
        return NULL;
    }
    else {
        return front->data;
    }
}

/*****************************************************************************************
 ** Function: removeFront()
 ** Description: deletes the node at the front of the queue
 ** Parameters: None
 ** Pre-Conditions: A queue exists
 ** Post-Conditions: the node pointed to by front pointer is deallocated
 ****************************************************************************************/
void QueueClass::removeFront(){
    Qnode *temp;
    
    if (isEmpty()) {
        std::cout << "The queue is empty, unable to complete operation.\n";
        return;
    }
    else {
        temp = front;
        front = front->next;
        delete temp;
    }
}

/*****************************************************************************************
 ** Function: isEmpty()
 ** Description: a boolean function that returns true if the queue is empty or 
 *               false if it isn't empty.
 ** Parameters: None
 ** Pre-Conditions: A queue exists
 ** Post-Conditions: fucntion returns true or false
 ****************************************************************************************/

bool QueueClass::isEmpty() const {
    if (front == NULL)
        return true;
    else
        return false;
    
}
/*****************************************************************************************
 ** Function: Destructor
 ** Description: Deallocates the data contained in the queue by calling removeFront() 
 *               function until the queue is empty
 *                  *commented code could be implemented for use in a circular queue
 ** Parameters: None
 ** Pre-Conditions: An instance of the class
 ** Post-Conditions: Poof. The queue is gone and the memory is free again.
 ****************************************************************************************/
QueueClass::~QueueClass()
{
    while(!isEmpty())
        removeFront();
    
 /*   StackNode *nodePtr = this->head;  // Start at head of list
    while(!isEmpty()) {
        // garbage keeps track of next node to be deleted
        StackNode *garbage = nodePtr;
        
        // Delete the "garbage" node
        delete garbage;
        
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
    }
  */
}


