/*********************************************************************
 ** Program Filename: Item.cpp
 ** Author: Jacob Karcz
 ** Date: 6.25.2016
 ** Description:
 ** Input:
 ** Output:
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include<iomanip>
#include <string>
#include <sstream>

class Item {
    

private:
    std::string name;
    std::string unit;
    double price;
    int quantity;
    double subtotal;

public:
    Item ();
    Item (std::string N, std::string U, double P, int Q);
    void setName (std::string);
    std::string getName ();
    void setUnit (std::string);
    std::string getUnit();
    void setPrice (double);
    double getPrice ();
    void setQuantity (int);
    int getQuantity ();
    void setSubtotal ();
    double getSubtotal ();
};


#endif /* Item_hpp */
