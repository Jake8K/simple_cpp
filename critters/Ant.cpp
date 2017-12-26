/***************************************************************************************
 ** Program Filename: Ant.cpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is the Ant subclass cfunction implementation file. The parent
 *               class is critter and holds the bulk of its attributes and functions. The
 *               constructor initializes the speciesChar to the identifying ':' and its
 *               specialized breed and die functions work differently than its
 *               parent class. It breeds every 3 move() function calls and dies after 10
 *               move() funciton calls.
 ** Input: None
 ** Output: An Ant instance
 ***************************************************************************************/

#include "Ant.hpp"

/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: Creates an Ant instance with the Critter default consturctor but
 *               with a special character (speciesChar) to identiy if it as an Ant.
 ** Parameters: None
 ** Input: None
 ** Output: An Ant instance
 ****************************************************************************************/
Ant::Ant() : Critter() {
    this->speciesChar = ':';
}

/*****************************************************************************************
 ** Function: breed()
 ** Description: A simple function that returns false unless the instances timeToBreed
 *               data member is equal to 3, in which case it resets it to 0 and returns
 *               true
 ** Parameters: None
 ** Pre-Conditions: an instance of am Ant
 ** Post-Conditions: timeToBreed data member is reset to 0 if it equaled 3.
 ****************************************************************************************/
bool Ant::breed() {
    if (timeToBreed == 3) {
        this->timeToBreed = 0;
        return true;
        }
    else
        return false;
}

/*****************************************************************************************
 ** Function: die()
 ** Description: A simple function that returns true if the instance's life data member
 *               is equal to 10, otherwise it returns false
 ** Parameters: None
 ** Pre-Conditions: an instance of an Ant
 ** Post-Conditions: None
 ****************************************************************************************/
bool Ant::die() {
    if (life == 10) {
        return true;}
    else
        return false;
}