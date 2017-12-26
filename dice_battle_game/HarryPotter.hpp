//
//  HarryPotter.hpp
//  Assignment3
//
//  Created by Jacob Karcz on 7/18/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include <stdio.h>
#include "Creature.hpp"

class HarryPotter : public Creature {
private:
    int lives;
   
public:
    HarryPotter();
    virtual int attack();
    virtual void defend(int);

    };
    
    
#endif /* HarryPotter_hpp */
