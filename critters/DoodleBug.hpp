/***************************************************************************************
 ** Program Filename: DoodleBug.hpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is the DoodleBug subclass class declaration file. The parent
 *               class is critter and holds the bulk of its attributes and functions. The
 *               constructor initializes the speciesChar to the identifying '@' and its
 *               specialized eat, breed, and die functions work differently than its
 *               parent class. It breeds every 8 move() function calls and dies after 3
 *               move() funciton calls if the eat() function isn't called to reset its
 *               life data member to 0.
 ** Input: None
 ** Output: A DoodleBug instance
 ***************************************************************************************/

#ifndef DoodleBug_hpp
#define DoodleBug_hpp

#include <stdio.h>
#include "Critter.hpp"


class DoodleBug : public Critter {

private:
    bool eaten;
    
public:
    DoodleBug();
    void Eat();
    bool breed();
    bool die();
    
};

#endif /* DoodleBug_hpp */
