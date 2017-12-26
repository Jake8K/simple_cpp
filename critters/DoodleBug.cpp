/***************************************************************************************
 ** Program Filename: DoodleBug.cpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is the DoodleBug subclass function implementation file. The parent
 *               class is critter and holds the bulk of its attributes and functions. The
 *               constructor initializes the speciesChar to the identifying '@' and its 
 *               specialized eat, breed, and die functions work differently than its 
 *               parent class. It breeds every 8 move() function calls and dies after 3
 *               move() funciton calls if the eat() function isn't called to reset its 
 *               life data member to 0.
 ** Input: None
 ** Output: A DoodleBug instance
 ***************************************************************************************/

#include "DoodleBug.hpp"

/*****************************************************************************************
 ** Function: Constructor
 ** Description: Creates a DoodleBug instance with the Critter default consturctor but
 *               with a special character (speciesChar) to identiy if it as a Doodlebug.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: an instance of a DoodleBug
 ****************************************************************************************/
DoodleBug::DoodleBug() : Critter() {
    this->speciesChar = '@';
}

/*****************************************************************************************
 ** Function: Eat()
 ** Description: A simple function that resets the DoodleBug's life integer data member
 *               to 0 wif called
 ** Parameters: None
 ** Pre-Conditions: an instance of a DoodleBug
 ** Post-Conditions: life data member is reset to 0
 ****************************************************************************************/
void DoodleBug::Eat() {
    this->life = 0;
}

/*****************************************************************************************
 ** Function: breed()
 ** Description: A simple function that returns false unless the instances timeToBreed
 *               data member is equal to 8, in which case it resets it to 0 and returns 
 *               true
 ** Parameters: None
 ** Pre-Conditions: an instance of a DoodleBug
 ** Post-Conditions: timeToBreed data member is reset to 0 if it equaled 8.
 ****************************************************************************************/
bool DoodleBug::breed() {
    if (timeToBreed == 8) {
        timeToBreed = 0;
        return true; }
    else
        return false;
}


/*****************************************************************************************
 ** Function: die()
 ** Description: A simple function that returns true if the instance's life data member
 *               is equal to 3, otherwise it returns false
 ** Parameters: None
 ** Pre-Conditions: an instance of a DoodleBug
 ** Post-Conditions: None
 ****************************************************************************************/
bool DoodleBug::die() {
    if (life == 3) {
        return true; }
    else
        return false;
}