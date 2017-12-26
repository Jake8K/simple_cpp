/**************************************************************************
 ** Program Filename: Item.cpp
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description:
 ** Input:
 ** Output:
 **************************************************************************/

#include "Item.hpp"


/**************************************************************************
 ** Function: Default Constructor
 ** Description: Creates a NULL item where strings  = " " and numbers = 0
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: An Item with name " ", unit " ", price 0.00, 
 *                   quantity 0, and subtotal of 0.00
 **************************************************************************/
Item::Item () {
    setName(" ");
    setUnit(" ");
    setPrice(0.00);
    setQuantity(0);
    setSubtotal();
    
}


/**************************************************************************
 ** Function: Constructor
 ** Description: Creates an item with attributes passed as parameters
 ** Parameters: (string name N, string unit U, double price P, int quantity Q)
 ** Pre-Conditions: string N, string U, price P, quantity Q
 ** Post-Conditions: Item with name = N, unit = U, price = P, quantity = Q, 
 *                     and subtotal = P * Q
 **************************************************************************/
Item::Item (std::string N, std::string U, double P, int Q){
    setName(N);
    setUnit(U);
    setPrice(P);
    setQuantity(Q);
    setSubtotal();
}

/**************************************************************************
 ** Function: setName
 ** Description: Sets the name of the Item to N
 ** Parameters: (string N)
 ** Pre-Conditions: string N
 ** Post-Conditions: Item name = N
 **************************************************************************/
void Item::setName (std::string N){
    name = N;
}

/**************************************************************************
 ** Function: getName
 ** Description: returns the Item name
 ** Parameters: None
 ** Pre-Conditions: Item exists
 ** Post-Conditions: Returns Item name
 **************************************************************************/
std::string Item::getName () {
    return name;
}

/**************************************************************************
 ** Function: setUnit
 ** Description: Sets the unit of the Item to U
 ** Parameters: (string U)
 ** Pre-Conditions: string U
 ** Post-Conditions: Item unit = U
 **************************************************************************/
void Item::setUnit (std::string U) {
    unit = U;
}

/**************************************************************************
 ** Function: getUnit
 ** Description: returns the Item unit
 ** Parameters: None
 ** Pre-Conditions: Item exists
 ** Post-Conditions: Returns Item unit
 **************************************************************************/
std::string Item::getUnit() {
    return unit;
}

/**************************************************************************
 ** Function: setPrice
 ** Description: Sets the price of the Item to P
 ** Parameters: (double P)
 ** Pre-Conditions: double P
 ** Post-Conditions: Item price = P
 **************************************************************************/
void Item::setPrice (double P) {
    price = P;
}

/**************************************************************************
 ** Function: getPrice
 ** Description: returns the Item price
 ** Parameters: None
 ** Pre-Conditions: Item exists
 ** Post-Conditions: Returns Item price
 **************************************************************************/
double Item::getPrice () {
    return price;
}

/**************************************************************************
 ** Function: setQuantity
 ** Description: Sets the quantity of the Item to Q
 ** Parameters: (int Q)
 ** Pre-Conditions: int Q
 ** Post-Conditions: Item quantity = Q
 **************************************************************************/
void Item::setQuantity (int Q) {
    quantity = Q;
}

/**************************************************************************
 ** Function: getQuantity
 ** Description: returns the Item quantity
 ** Parameters: None
 ** Pre-Conditions: Item exists
 ** Post-Conditions: Returns Item quantity
 **************************************************************************/
int Item::getQuantity () {
    return quantity;
}

/**************************************************************************
 ** Function: setSubtotal
 ** Description: Sets the subtotal of the Item
 ** Parameters: None
 ** Pre-Conditions: Item price and Item quantity are set
 ** Post-Conditions: Item subtotal
 **************************************************************************/
void Item::setSubtotal () {
    subtotal = price * quantity;
}

/**************************************************************************
 ** Function: getSubtotal
 ** Description: returns the Item subtotal
 ** Parameters: None
 ** Pre-Conditions: Item exists
 ** Post-Conditions: Returns Item subtotal
 **************************************************************************/
double Item::getSubtotal () {
    return subtotal;
}




