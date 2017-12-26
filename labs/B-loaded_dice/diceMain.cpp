/***************************************************************************************
 ** Program Filename: diceMain.cpp
 ** Author: Jacob Karcz
 ** Date: 7.03.2016
 ** Description: This is the main function for a dice game using Dice (superclass) and
 *                  LoadedDice (subclass) classes. Dice simulates dice and LoadedDice
 *                  dice have a 10% chance of any value less than the objects maximum
 *                  value being augmented by 1. It prompts the user for the number of
 *                  sides each die should have and the number of times to roll the dice.
 *                  The program then "rolls the dice" and displays the results. At the
 *                  end, if uncommented out, it can also print out how many times the
 *                  LoadedDice returned an augmented value.
 ** Input: ints as responses to prompts to create objects and roll the dice
 ** Output: The number of sides per die, the value of the dice at each roll, and if desired,
 *              the number of times the LoadedDice die was "loaded"
 ***************************************************************************************/

#include <iostream>
#include <iostream>
#include <iomanip>
#include "Dice.hpp"
#include "LoadedDice.hpp"
using std::cout;
using::std::cin;
using std::endl;


/*****************************************************************************************
 ** Function: Main Function
 ** Description: This is the main function for a dice game using Dice (superclass) and 
 *                  LoadedDice (subclass) classes. Dice simulates dice and LoadedDice 
 *                  dice have a 10% chance of any value less than the objects maximum 
 *                  value being augmented by 1. It prompts the user for the number of
 *                  sides each of the 2 dice should have and the number of times to roll
 *                  the dice. The program then "rolls the dice" and displays the results.
 *                  At the end, if uncommented out, it can also print out how many times 
 *                  the LoadedDice returned an augmented value.
 *
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ****************************************************************************************/
int main() {
    //seed random number generator
    srand(time(0));
    
    int rolls = 0;
     //die 1 faces, die 2 faces, # desired dice rolls
    int d1, d2, maxRolls;
    
    //Initialize objects
    cout << "how many sides should the loaded die have?\n";
    cin >> d1;
    cout << "how many sides should the regular die have?\n";
    cin >> d2;
    LoadedDice Die1 = d1;
    Dice Die2 = Dice(d2);
    
    //confirm dice attributes
    cout << "\nDie 1 has " << Die1.getSides() << " sides.\n";
    cout << "Die 2 has " << Die2.getSides() << " sides.\n";
    
    cout << "\nhow many times will we roll the dice?\n";
    cin >> maxRolls;
    
    //roll the dice
    cout << "\nLet's roll the dice!\n";
    cout << "-------------------------\n";
    cout << "           D1\tD2\n";
    while (rolls < maxRolls) {
        cout << "roll " << rolls + 1 << ":    ";
        cout << Die1.rollDice() << "\t ";
        cout << Die2.rollDice() << "\n";
        rolls++;
    }
    
    //Display number of times LoadedDice rollDice function augmented the die value and avgs
    cout << "\nLoaded dice augmented " << Die1.getChances() << " times.\n\n";
    
    return 0;
}
