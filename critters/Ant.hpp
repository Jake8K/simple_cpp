/***************************************************************************************
 ** Program Filename: Ant.hpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is the Ant subclass class declaration file. The parent
 *               class is critter and holds the bulk of its attributes and functions. The
 *               constructor initializes the speciesChar to the identifying ':' and its
 *               specialized breed and die functions work differently than its
 *               parent class. It breeds every 3 move() function calls and dies after 10
 *               move() funciton calls.
 ** Input: None
 ** Output: An Ant instance
 ***************************************************************************************/
#ifndef Ant_hpp
#define Ant_hpp

#include <stdio.h>
#include "Critter.hpp"


class Ant : public Critter {
    
private:
    
    
public:
    Ant();
    bool breed();
    bool die();
    
};

#endif /* Ant_hpp */
