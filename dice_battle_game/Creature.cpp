//
//  Creature.cpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "Creature.hpp"



/*****************************************************************************************
 ** Function: Roll Function
 ** Description: This is the main function "rolls the dice" and returns the results.
 *
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ****************************************************************************************/

int Creature::rollMyDice (int numDice, int numSides) {
    
    creatureDice = new Dice*[numDice];
    int rollValue = 0;
    
    //create the Dice
    for (int i = 0; i < numDice; i++)
        creatureDice[i] = new Dice(numSides);
    //roll the dice
    for (int i = 0; i < numDice; i++)
        rollValue += creatureDice[i]->rollDice();
    //delete the dice
    for (int i = 0; i < numDice; i++)
        delete creatureDice[i];
    
    delete creatureDice;
    
    return rollValue;
}

/*****************************************************************************************
 ** Function: getStrength()
 ** Description: a "getter" function that returns the caller's strength
 ** Parameters: None
 ** Pre-Conditions: the calling instance exists
 ** Post-Conditions: returns the instance's strength
 ****************************************************************************************/
int Creature::getStrength() {
    return this->strength;
}
