//
//  Medusa.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef Medusa_hpp
#define Medusa_hpp

#include <stdio.h>
#include "Creature.hpp"

class Medusa : public Creature {
    
public:
    Medusa();
    virtual int attack();
    virtual void defend(int hit);
    
};
                             
                                             
#endif /* Medusa_hpp */
