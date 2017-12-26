/***************************************************************************************
 ** Program Filename: Dice.hpp
 ** Author: Jacob Karcz
 ** Date: 7.03.2016
 ** Description: a class that creates Dice objects, simulating dice, and symbolically
 *                  "rolls" the "dice" and returns on of the face values. The default
 *                  Dice object has 6 sides, but an int can be passed to the constructor
 *                  specifying any number of sides. Each Dice object is a dynamically
 *                  allocated array (each side is an element) so further manipulation of
 *                  class is possible if new functions are written. Function getSides 
 *                  returns the number of sides of the instance and the rollDice function
 *                  returns a randomly generated number represeinting one of the sides of
 *                  the die. Don't forget to seed the function with srand(time(0)) in main
 ** Input: an int for the number of sides desired in Dice instance
 ** Output: a Dice object, when rollDice is called an int representing a side of the "die"
 ***************************************************************************************/
#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>
#include <ctime>
#include <cstdlib>

class Dice
{
protected:
    int sides;
    
private:
    int *diceArray;
    
public:
    Dice();
    Dice(int s);
    ~Dice();
    int getSides();
    int rollDice();
};

#endif /* Dice_hpp */
