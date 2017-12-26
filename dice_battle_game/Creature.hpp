//
//  Creature.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <iostream>
#include "Dice.hpp"
using std::cout;
using std::endl;

class Creature {
    
protected:
    Dice **creatureDice;
    int  attackDice,
         attackDsides,
         defenseDice,
         defenseDsides,
         armor,
         strength;
public:
    virtual int attack() = 0;
    virtual void defend(int) = 0;
    int rollMyDice(int numDice, int numSides);
    int getStrength();
};


#endif /* Creature_hpp */
