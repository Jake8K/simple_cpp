//
//  ReptilePeople.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef ReptilePeople_hpp
#define ReptilePeople_hpp

#include <stdio.h>
#include "Creature.hpp"

class ReptilePeople : public Creature {
    
public:
    ReptilePeople();
    virtual int attack();
    virtual void defend(int a);
    
};
#endif /* ReptilePeople_hpp */
