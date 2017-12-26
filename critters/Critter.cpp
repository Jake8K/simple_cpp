/***************************************************************************************
 ** Program Filename: Critter.cpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is a class implementation file for the Critter class. This is a 
 *               parent class for Critter subclasses, where each different critter 
 *               represents a different species with derived qualities along with many
 *               shared traits described by the parent class. The class creates Critters
 *               that simulate creatures in a grid controlled by another class or function.
 ** Input: None
 ** Output: A Critter instance or manipulation of Critter class data members by member
 *          functions
 ***************************************************************************************/

#include "Critter.hpp"

/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: This is the Critter class constructor, it initializes a critter instance
 *               random x and y coordinates (within the given 2D array grid) and its life, 
 *               timeToBreed, and moved data members initialized to 0 or false.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: a Critter instance
 ****************************************************************************************/
Critter::Critter() {
    this->life = 0;
    this->timeToBreed = 0;
    this->speciesChar = ' ';
    this->x = (rand() %dimension) +1;
    this->y = (rand() %dimension) +1;
    this->moved = false;
}

/*****************************************************************************************
 ** Function: move()
 ** Description: if the critter hasn't moved yet (moved is false) then it changes the 
 *               bool to true, increments the Critters life and timeToBreed data members, 
 *               and returns a random number between 1 and 4. If the critter has moved it 
 *               returns a null direction of 0.
 ** Parameters: None
 ** Pre-Conditions: a Critter instance
 ** Post-Conditions: The critter's life and timeToBreed data members are incremented 
 *                   and a direction is returned by the function
 ****************************************************************************************/
int Critter::move() {
    if (moved == false) {
        moved = true;
        moveDisDat = (rand() %4) +1;
        this->life++;
        this->timeToBreed++;
        return moveDisDat;
    }
    else
        return 0;
}
/*****************************************************************************************
 ** Function: getChar()
 ** Description: a simple fucntion that returns the calling objects speciesChar identity.
 ** Parameters: None
 ** Pre-Conditions: an inctance of a Critter
 ** Post-Conditions: The Critters identifying character is returned
 ****************************************************************************************/
char Critter::getChar() {
    return this->speciesChar;
}
/*****************************************************************************************
 ** Function: getX()
 ** Description: a simple function that returns a Critter's x variable
 *
 ** Parameters: None
 ** Pre-Conditions: a Critter object
 ** Post-Conditions: The calling Critter's x data member is returned
 ****************************************************************************************/
int Critter::getX() {
    return this->x;
}

/*****************************************************************************************
 ** Function: getY()
 ** Description: a simple function that returns a Critter's y variable
 *
 ** Parameters: None
 ** Pre-Conditions: a Critter object
 ** Post-Conditions: The calling Critter's y data member is returned
 ****************************************************************************************/
int Critter::getY() {
    return this->y;
}

/*****************************************************************************************
 ** Function: getMoved()
 ** Description: a simple function that returns a Critter's true or false
 *
 ** Parameters: None
 ** Pre-Conditions: a Critter object
 ** Post-Conditions: The calling Critter's moved bool data member is returned (t or f)
 ****************************************************************************************/
bool Critter::critMoved() {
    return this->moved;
}

/*****************************************************************************************
 ** Function: setMoved(bool)
 ** Description: a simple function that sets the calling Critter's moved bool data member
 *                to true or false deppending on the bool passed.
 ** Parameters: a boolean variable, true or false
 ** Pre-Conditions: a Critter object
 ** Post-Conditions: the Critter's moved bool is set to true or false
 ****************************************************************************************/
void Critter::setMoved(bool M) {
    moved = M;
}

