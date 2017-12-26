/***************************************************************************************
 ** Program Filename: Dice.cpp
 ** Author: Jacob Karcz
 ** Date: 7.03.2016
 ** Description: a class that creates Dice objects, simulating dice, and symbolically 
 *                  "rolls" the "dice" and returns on of the face values. The deefault 
 *                  Dice object has 6 sides, but an int can be passed to the constructor
 *                  specifying any number of sides. Each Dice object is a dynamically 
 *                  allocated array so further manipulation of class is possible if new
 *                  functions are written.
 ** Input: an int for the number of sides desired in Dice instance
 ** Output: a Dice object, when rollDice is called an int representing a side of the "die"
 ***************************************************************************************/

#include <iostream>
#include "Dice.hpp"
using std::cout;
using std::endl;

/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: Creates a Dice object with the default attributes of a 6-sided die
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: a Dice object with 6 "sides"
 ****************************************************************************************/
Dice::Dice() {
    sides = 6;
    diceArray = new int[sides];
    
    for (int i = 0; i < sides; i++)
        diceArray[i] = (i+1);
    
    /*check it out
    for (int i = 0; i < sides; i++)
        cout << diceArray[i] << " ";
    cout << "I am the default constructor\n";*/

}

/*****************************************************************************************
 ** Function:  Constructor
 ** Description: Initializes the size of the dynamically allocated array simulating a die
 *                  according to the integer passed as representing the number of sides
 ** Parameters: an int for he number of sides in the die
 ** Pre-Conditions: None
 ** Post-Conditions: A die (array) with specified number of sides
 ****************************************************************************************/
Dice::Dice(int s){
    sides = s;
    diceArray = new int[sides];
    
    for (int i = 0; i < sides; i++)
        diceArray[i] = (i+1);
    
    /*check it out
    for (int i = 0; i < sides; i++)
        cout << diceArray[i] << " ";
        cout << "I am the constructor\n";*/


}

/*****************************************************************************************
 ** Function:  Destructor
 ** Description: If the die has at least one side, it destroys it & deallocates the memory
 ** Parameters: none
 ** Pre-Conditions: a Dice instance exists
 ** Post-Conditions: the Dice no longer exists
 ****************************************************************************************/
Dice::~Dice() {
    if (this->sides > 0)
        delete [] diceArray;
}

/*****************************************************************************************
 ** Function:  getSides
 ** Description: returns the number of sides of the Dice
 ** Parameters: none
 ** Pre-Conditions: a Dice exists
 ** Post-Conditions: The function returns the number of sides of the die
 ****************************************************************************************/
int Dice::getSides(){
     return this->sides;
}


/*****************************************************************************************
 ** Function:  rollDice
 ** Description: simulates the rolling of a die by choosing a side by chance
 ** Parameters: none
 ** Pre-Conditions: a Dice exists
 ** Post-Conditions: The function returns a side of the die
 ****************************************************************************************/
int Dice::rollDice() {

    int roll;
    int faces = (*this).sides;
    
    //roll the die
    //seed with srand(time(0)); in main
    roll = (rand() % faces) + 1;
    
    return roll;
}



