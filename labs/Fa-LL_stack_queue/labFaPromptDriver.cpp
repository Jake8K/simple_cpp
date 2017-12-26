/***************************************************************************************
 ** Program Filename: labFaPromptDriver.cpp
 ** Author: Jacob Karcz
 ** Date: 7.26.2016
 ** Description: This is a driver program for dynamic stack and queue classes that hold 
 *               an integer as a data member.
 ** Input: char choices and integers, as prompted by the menu-driven main function
 ** Output: Only what was entered into the data structures
 ***************************************************************************************/

#include <iostream>
#include "StackClass.hpp"
#include "QueueClass.hpp"
using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************************
 ** Function: main()
 ** Description: A menu-driven function that prompts the user for choices on adding
 *               removing, and displaying integers in a  stack and a queue. Every option 
 *               automatically performs the desired action on both the stack and the queue.
 ** Parameters: None
 ** Pre-Conditions: None.
 ** Post-Conditions: returns 0 if no erros.
 ****************************************************************************************/
int main() {
    
    char choice = 'x';
    int num;
    bool exit = false;
    
    StackClass stack;
    QueueClass queue;
    
    do {
        cout << "\nChoose from the following options:" << endl;
        cout << "  A. Add a single number to the stack\n     and the queue\n"
                "  B. Display current first number on the\n     stack and queue\n"
                "  C. Remove the current first number on\n     the stack and the queue\n"
                "  D. Display and erase all numbers held\n     in the stack and the queue\n"
                "  E. Quit\n\n";
        cout << "Your choice: ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        
        switch (choice) {
            case 'A': //add an element
                cout << "What number would you like to add?\n";
                cin >> num;
                cout << "Pushing " << num << " to the stack\n";
                    stack.push(num);
                cout << "Adding " << num << " to the queue\n";
                    queue.addBack(num);
                break;
                
            case 'B': //display 1st element
                cout << "The number on top of the stack is " << stack.peek() << endl;
                cout << "The number at the front of the queue is " << queue.getFront()
                     << endl;
                break;
                
            case 'C': //remove 1st element
                cout << "Popping " << stack.peek() << " from the top of the stack\n";
                    stack.pop();
                cout << "Removing " << queue.getFront() << " from the front of the queue"
                     << endl;
                    queue.removeFront();
                cout << endl;
                break;
                
            case 'D': //display all elements (and remove all elements)
                cout << "Retrieving stack...\n";
                
                if (!stack.isEmpty()) { //if the stack is not empty, display
                    while (!stack.isEmpty()) {
                        cout << stack.peek() << " ";
                        stack.pop();
                    }
                    cout << "\nOperation complete. Stack is empty." << endl;
                }
                
                else // the stack is empty, this is a prettier error message than default
                    cout << "Error processing request, stack has no data.\n";
                
                cout << endl; //**************

                cout << "Retrieving queue...\n";
                
                 if (!queue.isEmpty()) { //if the queue is not empty, display
                     while (!queue.isEmpty()) {
                         cout << queue.getFront() << " ";
                         queue.removeFront();
                     }
                
                     cout << "\nOperation complete. Queue is empty." << endl;
                 }
                else // the queue is empty, this is a prettier error message than default
                    cout << "Error processing request, queue has no data.\n";
                
                break;
                
            case 'E':
                cout << " The stack should be retrieving the most recent entry"
                        " (print in reverse order than they were entered) while the queue"
                        " should be retrieving (& printing) the entries in the order"
                        " that they were entered.\n\n";
                exit = true;
                break;
                
            default:
                if (!exit)
                    std::cout << "\nPlease choose a valid option.\n";
                break;
        }
    }while(!exit);
    
    
    return 0;
}