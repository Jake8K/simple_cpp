/***************************************************************************************
 ** Program Filename: Critter.hpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is a class declaration file for the class Critter. MoveDisDat is 
 *                 a number between 1 and 4 generated and returned by move() to tell the
 *                  controlling program where to move the Critter. x and y are only used 
 *                  in the creation of the first inhabitants for random placement in 
 *                  array, and dimension is the x and y dimensions of the 2D array the 
 *                  Critters will inhabit. life and time to breed are treated differently 
 *                  by the subclasses of Critter but they represent the "age" and "sexual
 *                  maturity" of the Critters. speciesChar identifies each of the 
 *                  sublasses of Critter and moved is a boolean variable used in the move 
 *                  function that is set to true once the Critter calls move() so that
 *                  it can only call it once per "day".
 *                  move() returns a direction to move and updates the Critters life and 
 *                  timeTo Breed variables. breed(), die(), and critMoved() return true 
 *                  or false for the calling function to either reproduce, delete, or 
 *                  ignore the Critter.
 ** Input: None
 ** Output: A Critter instance or manipulation of Critter class data members by member 
 *          functions
 ***************************************************************************************/

#ifndef Critter_hpp
#define Critter_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Critter {

private:
    int moveDisDat,
        x, y,
        dimension = 20;
    
protected:
    int life,
        timeToBreed;
    bool moved;
    char speciesChar;
    
public:
    Critter();
    int move();
    bool breed();
    bool die();
    char getChar();
    int getX();
    int getY();
    bool critMoved();
    void setMoved(bool);

    
};

#endif /* Critter_hpp */
