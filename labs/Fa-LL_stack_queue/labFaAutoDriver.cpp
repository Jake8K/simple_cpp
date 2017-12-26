//
//  main.cpp
//  labFa
//
//  Created by Jacob Karcz on 7/26/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//



// This program demonstrates the dynamic stack and the dynamic queue
#include <iostream>
#include "StackClass.hpp"
#include "QueueClass.hpp"
using std::endl;
using std::cout;
using std::cin;

int main()
{
// Demonstrate a Dynamic Stack
    cout << "Lets begin by implementing a dynamic stack and pushing 5 values: \n\n";
    
    StackClass stack;
    
    // Push values on the stack
    for (int value = 5; value <= 25; value = value + 5) {
        cout << "Push: " << value << "\n";
        stack.push(value);
    }
    cout << "\n";
    
    // Pop values off the stack
    for (int k = 1; k <= 5; k++) {
        cout << "Pop: ";
        cout << stack.peek() << endl; //take a peek before it's gone
        stack.pop(); //it's gone
    }
    cout << endl;
    
   cout << "\nThe stack is a first-in last-out data structure. As we can see, 5,"
        << " the first number entered, is the last one to be retrieved.\n"
        << "The data in the stack is accessible in reverse relative "
        << "to the order in which it was added.";

// Demonstrate a Dynamic Queue
    
    cout << "\n\n\nNow lets implement a dynamic queue and enqueue the same 5 numbers:\n\n";

    QueueClass queue;
    
    // Enqueue values
    for (int item = 5; item <= 25; item = item + 5) {
        cout << "Enqueue: " << item << "\n";
        queue.addBack(item);
    }
    cout << "\n";
    
    
    // Deqeue and retrieve all items in the queue
    while (!queue.isEmpty()) {
        cout << "Dequeue: ";
        cout << queue.getFront() << "\n";
        queue.removeFront();

    }
    cout << endl;
    
    cout << "\nThe queue is a FIFO data structure (first-in last-out "
         << "for those that didn't have crappy high school jobs). As we can see, 5,"
         << " the first number entered, is the first one to be retrieved.\nThe data in"
         << " the queue is accessible in the same order in which it was entered.\n";

//Summary
    cout << "\nTo reiterate, \n\nthis is a stack:\n";
    
    cout <<  "Adding: ";
    
        for (int i =1; i <= 5; i++) {
            stack.push(i);
            cout << i << " ";
        } cout << endl;
    
    cout << "Removing: ";
    
        while (!stack.isEmpty()) {
            cout << stack.peek() << " ";
            stack.pop();
        } cout << endl;
    
    cout << "\nand this is a queue:\n";
    
    cout <<  "Adding: ";
    
        for (int k =1; k <= 5; k++) {
            queue.addBack(k);
            cout << k << " ";
        } cout << endl;
    
    cout << "Removing: ";
    
        while (!queue.isEmpty()) {
            cout << queue.getFront() << " ";
            queue.removeFront();
        }cout << endl;
    
    cout << endl;
    return 0;
}
