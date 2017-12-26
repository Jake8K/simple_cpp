/*****************************************************************************************
 ** Program Filename: List.cpp
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description: List class declaration file for List object, creates a dynamically
 *                  allocated array of pointer to pointers and adds, removes, and
 *                  displays the items held, it also adds up the subottals of all
 *                  items in the array and displays the total cost of all items. At
 *                  the end it also erases the array to free up the memory.
 ** Input: None
 ** Output: dynamically allocated array of pointer to Item pointers
 ****************************************************************************************/

#include "List.hpp"


/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: Initializes the size of the dynamically allocated array of Items
 *                  (arraySize) and the total number of items in the array 
                    (listItemsTotal) to 4 and 0 respectively.
 ** Parameters: None
 ** Pre-Conditions: none
 ** Post-Conditions: arraySize = 4 and listItemsToal = 0
 ****************************************************************************************/
List::List() {
    arraySize = 4;
    listItemsTotal = 0;
    listArray = new Item[arraySize];
}
/*****************************************************************************************
 ** Function: addItem
 ** Description: Gets passed an Item to add to the array, however, if the array is maxed
 *                  out, it doubles the size of the array before adding the item, if the
 *                  item is already present in the array then it changes the quantity of 
 *                  the Item without adding an Item. Otherwise if it's a novel item and 
 *                  the array still has room, it adds an Item to the array and increases 
 *                  the array's element counter (listItemTotal) by 1.
 ** Parameters: an Item
 ** Pre-Conditions: an Item exists and an array of Items exists
 ** Post-Conditions: Either the quantity of an Item is augmented or an Item is added to
 *                      the array. If the array is maxed out, then it will double in size
 *                      to accomodate the new item.
 ****************************************************************************************/
void List::addItem(Item newItem) {
    bool isInList = false;
    for (int k = 0; k < listItemsTotal; k++) {
        if (listArray[k].getName() == newItem.getName()) {
            listArray[k].setQuantity(listArray[k].getQuantity()+newItem.getQuantity());
            //std::cout << listArray[k].getQuantity();
            listArray[k].setSubtotal();
            isInList = true;
            return;
        }
    }
    if (arraySize == listItemsTotal && !isInList){
        int newSize = arraySize * 2;
        Item *newArray = new Item[newSize];
        for (int i = 0; i < listItemsTotal; i++) {
            newArray[i].setName(listArray[i].getName());
            newArray[i].setUnit(listArray[i].getUnit());
            newArray[i].setPrice(listArray[i].getPrice());
            newArray[i].setQuantity(listArray[i].getQuantity());
            newArray[i].setSubtotal(); 
            
        }
        Item * tmp = listArray;
        listArray = newArray;
        delete [] tmp;
        arraySize = newSize;
        
    }
    
    if (!isInList) {
        listArray[listItemsTotal] = newItem;
        listItemsTotal++;
    }
}
/*****************************************************************************************
 ** Function: removeItem
 ** Description: Removes a chosen Item from the listArray
 ** Parameters: (string name)
 ** Pre-Conditions: a string containing the name of an item in the array
 ** Post-Conditions: The item is erased and all subsequent items 
 *                      (according to their index number) are shifted 
 *                      down by 1
 ****************************************************************************************/
void List::removeItem(std::string unwanted) {
    for (int k = 0; k < listItemsTotal; k++)
        if (listArray[k].getName() == unwanted) {
            for (int l = k; l < (listItemsTotal+1); l++)
                listArray[l] = listArray[l+1];
            listItemsTotal--;
        }
}

/*****************************************************************************************
 ** Function: totalCost
 ** Description: Calculates the total cost of the items in the array 
 *                  by adding the subtotals of every item in the array.
 ** Parameters: Nonce
 ** Pre-Conditions: An array of Items
 ** Post-Conditions: returns a double containing the total cost of 
 *                      all Items in the array
 ****************************************************************************************/
double List::totalCost() {
    double sum = 0;
    for (int m = 0; m < listItemsTotal; m++)
        sum += listArray[m].getSubtotal();
    return sum;
}

/*****************************************************************************************
 ** Function: displayItems
 ** Description: Displays the Items in the array in list form, each 
 *                  Item occupying one line where its attributes are 
 *                  displayed. After all Items in the array have been 
 *                  printed, the total cost of all items in the array 
 *                  is printed.
 ** Parameters: None
 ** Pre-Conditions: an array of Items
 ** Post-Conditions: the array's contents and the totalCost are displayed
 ****************************************************************************************/
void List::displayItems() {
    int itemNumber = 1;
    for (int p = 0; p < listItemsTotal; p++) {
        std::cout << "Item " << itemNumber << ": "
                       << listArray[p].getName() << "  "
                  << "cost: " << std::fixed << std::setprecision(2)
                       << listArray[p].getPrice() << "/" << listArray[p].getUnit() << "  "
                  << "quantity: " << listArray[p].getQuantity() << "  "
                  << "item subtotal: " << std::fixed << std::setprecision(2)
                        << listArray[p].getSubtotal() << "\n";
                  itemNumber++;
    }
    cout << "____________________\nTotal Cost: "
    << std::fixed << std::setprecision(2) << totalCost() << "\n\n" << std::endl;
}


/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: Deletes the dynamically allocated array of Items
 ** Parameters: None
 ** Pre-Conditions: a dynamic array of Items
 ** Post-Conditions: The dynamic array is erased and its memory freed
 ****************************************************************************************/
List::~List() {
    delete [] listArray;
}
