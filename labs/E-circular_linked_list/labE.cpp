
/***************************************************************************************
 ** Program Filename:
 ** Author: Jacob Karcz
 ** Date: 7.20.2016
 ** Description: A menu-driven program that manages a circularly linked list of chars. 
 *               The char data containing nodes are managed by the LinkedList class and 
 *               its member functions. The main function first instantiates a list
 *               object and then prompts the user to either add a single character,
 *               display the "first" character on the list, display the entire list, or
 *               quit the program. Anything that the user chooses to have displayed is
 *               automatically erased by the function. Nothing can be retrieved more than
 *               once.
 ** Input: user input for menu choices and characters to add to the list
 ** Output: Displays the chars contained in the list (once). Returns 0.
 ***************************************************************************************/

#include <iostream>
#include "LinkList.hpp"
using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************************
 ** Function: main()
 ** Description: A menu-driven function that prompts the user how they would manage a
 *               circular linked list of char data. The function first instantiates a 
 *               list object and then prompts the user to either add a single character,
 *               display the "first" character on the list, display the entire list, or
 *               quit the program. Anything that the user chooses to have displayed is
 *               automatically erased by the function. Nothing can be retrieved more than
 *               once.
 ** Parameters: None
 ** Pre-Conditions: None.
 ** Post-Conditions: returns 0 if no erros.
 ****************************************************************************************/
int main() {
    
    char choice = 'x';
    char ch;
    bool exit = false;
    int count = 0;
    int i = 0;

    LinkList list;
    
    do {
        cout << "\nChoose from the following options:" << endl;
        cout << "  A. Add a single character\n"
                "  B. Display (current) first character\n"
                "  C. Display all characters\n"
                "  D. Quit\n\n";
        cout << "Your choice: ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        switch (choice) {
            case 'A': //add
                    cout << "What char would you like to add?\n";
                    cin >> ch;
                    list.addNode(ch);
                    cout << "Done.\n";
                    count++;
                    break;
            
            case 'B': //display 1st
                    list.displayNode();
                    list.cutNode();
                    cout << endl;
                    break;
                
            case 'C': //display all
                    count = list.getCount();
                
                    for (i = 0; i < count; i++) {
                        if (list.getNode()) {
                            list.displayNode();
                            list.cutNode();
                        }
                    }
                    cout << endl;
                    break;
            
            case 'D':
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
