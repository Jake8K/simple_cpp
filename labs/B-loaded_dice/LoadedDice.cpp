/***************************************************************************************
 ** Program Filename: LoadedDice.cpp
 ** Author: Jacob Karcz
 ** Date: 7.03.2016
 ** Description: This is a subclass of the superclass Dice. It creates instances using the 
 *                  parent class constructors. The default instance is a "dice" with 6 
 *                  sides, however, an int can be passed to the constructor to create a 
 *                  die with as many sides as the user wants. The class overrides the 
 *                  parent class rollDice function, causing a roll of LoadedDice to have
 *                  a 10% chance of the die roll being augmented by 1 (so long as it is
 *                  not already the highest value die face). Do for dice with 6 sides, 
 *                  any roll that is less than 6 has a 10% chance of being 1 higher. 
 *                  Further, the overridden function augments the int chances to keep 
 *                  track of the number of times a return value is manipulated. This 
 *                  value is accessible through the getChances() function.
 ** Input: None or an int representing the number of desired LoadedDice "die" sides
 ** Output: a LoadedDice instance / an int representing a die face / the number of times 
 *             the "dice" are "loaded"
 ***************************************************************************************/

#include "LoadedDice.hpp"

/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: creates a LoadedDice object with the default attributes of a 6-sided die
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: a LoadedDice object with 6 "sides"
 ****************************************************************************************/
LoadedDice::LoadedDice() : Dice() {
    chances = 0;
}

/*****************************************************************************************
 ** Function: Constructor
 ** Description: Creates a LoadedDice object with the number of sides passed as arguement
 ** Parameters: an int for the number of faces the die will have
 ** Pre-Conditions: None
 ** Post-Conditions: An instance of LoadedDice with specified number of sides
 ****************************************************************************************/
LoadedDice::LoadedDice(int s) : Dice(s) {
}

/*****************************************************************************************
 ** Function: rollDice()
 ** Description: overridden superclass function, rollDice has a 10% chance of the 
 *                  LoadedDice returning a number that is one number higher for any number 
 *                  rolled that is less than the highest die face. so a 6-sided die roll
 *                  of any number less than 6 has a 10% chance of being augmented by 1, 
 *                  however a roll of 6 will always remain a 6
 ** Parameters: None
 ** Pre-Conditions: a LoadedDice object
 ** Post-Conditions: returns a randomly chosen face of the die, with any value less than
 *                      the highest face being affected by a 10% probability of 
 *                      augmentation by 1
 ****************************************************************************************/
int LoadedDice::rollDice() {
    int roll;
    int faces = (*this).sides;
    int loaded;
    
    //roll the die
    roll = (rand() % faces) + 1;
    
    // LoadedDice has a 10% chance of being incremented
    loaded = (rand() %10) +1;
    if ( roll < faces && loaded == 5) {
        roll++;
        chances++;
    }

    return roll;

}

/*****************************************************************************************
 ** Function: getChances
 ** Description: A function for statistical verfication of overriden rollDice function
 *                  functionality. Returns error checking variable augmented in the loop,
 *                  on average the number returned by getChances should be 10% of the
 *                  the number of times rollDice() is called (or any percentage chosen for
 *                  the roll to be affected.
 ** Parameters: None
 ** Pre-Conditions: A LoadedDice object called the rollDice() function
 ** Post-Conditions: an int representing the number of times the dice were "loaded"
 ****************************************************************************************/
int LoadedDice::getChances() {
    return chances;
}
