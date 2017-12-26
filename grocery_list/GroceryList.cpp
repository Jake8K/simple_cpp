/***************************************************************************************
 ** Program Filename: GroceryList.cpp
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description: The program has 2 classes, Item and List, whose member functions are 
 *                  called on by the main function bellow to create items, add them to
 *                  a shopping list, remove items from the shopping list, and display the
 *                  contents of the shopping list, with each item occupying 1 line that
 *                  displays its name, cost/unit, quantity, and item subtotal. At the
 *                  end of the list, the total cost of all items is displayed
 ** Input: User input to create items and add or remove them from the shoppingList
 ** Output: Exit with code 0 if no errors encountered.
 ***************************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "Item.hpp"
#include "List.hpp"

/***************************************************************************************
 ** Function: main()
 ** Description: Initializes a List object (shoppingList) and presents the user with a 
 *                  menu to choose whether they want to add a new item to shoppingList,
 *                  remove an item from the shoppingList,Display the shopping list in
 *                  its current state, or finish the list and exit the program.
 *               If they wish to add an Item to the shopping list, they are prompted 
 *                  by the switch statement to enter the name, unit, price, and quantity
 *                  of the object (with input validation for each attribute of the Item
 *                  object). The attributes are then passed to the Item class constructor
 *                  to create the item and the item is then passed to the List class 
 *                  addItem function to add it to the shoppingList. If the item already 
 *                  exists, then the item quantity will be augmented but the list will 
 *                  not elongate.
 *               If the user wishes to remove an item, they are prompted for the item 
 *                  name and this gets passed to the removeItem function of the List 
 *                  class to remove the item.
 *               If the user wishes to display the list, the enumerated list is 
 *                  displayed along with item subtotals and the total cost of all 
 *                  items at the bottom.
 *               If the user chooses to quit, they are prompted with one chance to be 
 *                  sure they are finished with the list, and if they respond "y"  the
 *                  shoppinglist is erased and the do while loop terminates, causing 
 *                  the program to exit and return 0.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Return 0 if no errors encountered.
 **************************************************************************************/
int main() {
    
    List shoppingList;
    char choice;
    char unitChoice;
    char check = 'x';
    std::string name;
    //enum Unit {each, lb, oz, kg, g};
    std::string unit;
    double price;
    int quantity;
    Item unwanted;
    Item temp;
    char exit = 'n';
   
    
    std::cout << "To create your grocery list, ";
  
    do {
    std::cout << "\nplease choose from the following options:" << std::endl;
    std::cout << "  A. Add an item\n"
                 "  B. Remove an item\n"
                 "  C. Display your shopping list\n"
                 "  D. Finish and exit\n\n";
    std::cin >> choice;
        choice = toupper(choice);

    switch (choice) {
        case 'A': std::cout << "OK, let's add an item.\n";
                    //add name
                  std::cout << "What's the name of the item you wish to add?\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, name);
            
                    //add unit
                  std::cout << "\nWhat's the unit of sale for this item?\n"
                            << "    Enter \"a\" for lb, \"b\" for oz, \"c\" for kg,\n"
                                "    \"d\" for g, or \"e\" if sold individually\n";
                  do {
                        std::cin >> unitChoice;
                        unitChoice = tolower(unitChoice);
                      
                    switch(unitChoice) {
                        case 'a': std::cout << "OK, unit of sale is pounds.\n";
                                unit = "lb";
                                check = 'z';
                                break;
                        case 'b': std::cout <<  "OK, unit of sale is ounces.\n";
                                unit = "oz";
                                check = 'z';
                                break;
                        case 'c': std::cout <<  "OK, unit of sale is kilograms.\n";
                                unit = "kg";
                                check = 'z';
                                break;
                        case 'd': std::cout <<  "OK, unit of sale is grams.\n";
                                unit = "g";
                                check = 'z';
                                break;
                        case 'e': std::cout <<  "OK, items are sold individually.\n";
                                unit = "Ea";
                                check = 'z';
                                break;
                        default: std::cout <<  "Invalid. Enter \"a\" for lb, \"b\" for oz,"
                            " \"c\" for kg, \"d\" for g, or \"e\" if sold individually\n";
                                break;
                    }
                   } while (check != 'z');
            
                    //add price
                  std::cout << "\nWhat's the cost for one unit of this item?\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> price;
                    while (!cin || price < 0 ){
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        cout << "Please use real numbers."
                        "\nHow much does one unit cost?" << endl;
                        cin >>   price;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

            
                    //add quantity
                  std::cout << "\nHow many units of this item would you like?\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> quantity;
                    while (!cin || quantity < 0 ){
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        cout << "Please stick to positive whole numbers."
                        "\nHow many units of this item would you like?" << endl;
                        cin >>   quantity;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

                    //create item and add to list (cannot initialize variable in switch)
                    temp = Item(name, unit, price, quantity);
                    shoppingList.addItem(temp);
            
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
                    break;
            
        case 'B': std::cout << "\nWhat's the name of the item you wish to remove?\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                shoppingList.removeItem(name);
                  break;
            
        case 'C': std::cout << "\nHere is your shopping list & total cost of your items:\n"
                            << std::endl;
                  shoppingList.displayItems();
                  break;
        
        case 'D': std::cout << "\nAre you sure you wish to quit? (y/n)\n";
                std::cin >> exit;
                exit = tolower(exit);
                break;
            
        default: std::cout << "\nPlease choose a valid option.";
                break;
        }
    } while (exit == 'n');
    
    return 0;
}

