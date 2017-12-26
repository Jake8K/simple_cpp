//
//  Gollum.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef Gollum_hpp
#define Gollum_hpp

#include <stdio.h>
#include "Creature.hpp"

class Gollum : public Creature {
    
public:
    Gollum();
    virtual int attack();
    virtual void defend(int);
    
};
#endif /* Gollum_hpp */
