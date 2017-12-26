/***************************************************************************************
 ** Program Filename: LoadedDice.hpp
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

#ifndef LoadedDice_hpp
#define LoadedDice_hpp

#include <iostream>
#include "Dice.hpp"
using std::cout;
using std::endl;


class LoadedDice : public Dice

{
    private:
        Dice Loaded;
        int chances;
    public:
        LoadedDice();
        LoadedDice (int);
        int rollDice();
    int getChances();
};

#endif /* LoadedDice_hpp */
