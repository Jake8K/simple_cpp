/***************************************************************************************
 ** Program Filename: QueueClass.hpp
 ** Author: Jacob Karcz
 ** Date: 7.26.2016
 ** Description: The QueueClass class declaration file. A dynamic queue data structure
 *               that holds data variables of type int.
 *               -isEmpty() returns true if the structure is empty
 *               -addBack(int) adds an integer to the queue
 *               -getFront() returns the first integer in the queue
 *               -removeFront() deallocates and removes the first integer in the queue
 ** Input: as needed by the fucntions, otherwise dependent on programmer implementation
 ** Output: a dynamic queue
 ***************************************************************************************/

#ifndef QueueClass_hpp
#define QueueClass_hpp

#include <iostream>
class QueueClass {
    
protected:
    struct Qnode {
        int data;
        Qnode *next;
        Qnode(int num, Qnode *nextN = NULL) {
            data = num;
            next = nextN;
        }
    };
    Qnode *front;
    Qnode *back;
    int counter;
    
public:
    //constructor & destructor
    QueueClass();
    ~QueueClass();
    
    //member functions
    bool isEmpty() const;
    void addBack(int num);
    int getFront() const;
    void removeFront();
    
};

#endif /* QueueClass_hpp */
