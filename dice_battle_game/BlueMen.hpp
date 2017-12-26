//
//  BlueMen.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Creature.hpp"

class BlueMen : public Creature {

public:
    BlueMen();
    virtual int attack();
    virtual void defend(int);
    
};

#endif /* BlueMen_hpp */
