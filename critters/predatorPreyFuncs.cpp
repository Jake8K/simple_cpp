/***************************************************************************************
 ** Program Filename: predatorPreyFuncs.cpp
 ** Author: Jacob Karcz
 ** Date: 7.05.2016
 ** Description: This is the main function file for a program that simulates predator/prey
 *                  interactions of two types of Critters, Ants (the prey), and DoodleBugs
 *                  (the predators). The Ants (represented by :'s) have a reproductive 
 *                  cycle of 3 days and a lifespan of 10 days. The DoodleBugs 
 *                  (represented by @s)have a reproductive cycle of 8 days and will die 
 *                  of starvation if they don't eat an Ant for 3 days.
 *                  At the start of the program the user is prompted for the number of
 *                  DoodleBugs and Ants they would like to see inhabit the 20X20 2D array 
 *                  that encompasses their universe. The program then populates the array
 *                  and displays the critters in their "world." The user is then prompted
 *                  to continue or quit, which makes a "day" pass in the simulation and 
 *                  each critter moves 1 spot chosen at random, if possible. Neither 
 *                  species can move onto a spot occupied by a conspecific or travel off 
 *                  the grid. If a DoodleBug moves onto an ant, it will eat it. If either
 *                  species breeds, it deposits a spawn at the breeding site, if they 
 *                  don't move after breeding they will not deposit a spawn. No one knows 
 *                  what they do to the babies when they can't move (because they're
 *                  cornered or at the edge of the world). Once the user quits, the world 
 *                  ends.
 ** Input: User is prompted for the number of critters to create (2 ints) and 
 *         either a lowercase "y" to continue the simulation or any other key to exit.
 ** Output: None
 ***************************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include "Critter.hpp"
#include "DoodleBug.hpp"
#include "Ant.hpp"
using std::cout;
using::std::cin;
using std::endl;


/*****************************************************************************************
 ** Function: Main Function
 ** Description: This is the main function for a program that simulates the predator/prey
 *                  interactions of two types of Critters, Ants (the prey), and DoodleBugs
 *                  (the predators). The Ants (represented by :'s) have a reproductive
 *                  cycle of 3 days and a lifespan of 10 days. The DoodleBugs
 *                  (represented by @s)have a reproductive cycle of 8 days and will die
 *                  of starvation if they don't eat an Ant for 3 days.
 *                  At the start of the program the user is prompted for the number of
 *                  DoodleBugs and Ants they would like to see inhabit the 20X20 2D array
 *                  that encompasses their universe. The program then populates the array
 *                  and displays the critters in their "world." The user is then prompted
 *                  to continue or quit, which makes a "day" pass in the simulation and
 *                  each critter moves 1 spot chosen at random, if possible. Neither
 *                  species can move onto a spot occupied by a conspecific or travel off
 *                  the grid. If a DoodleBug moves onto an ant, it will eat it. If either
 *                  species breeds, it deposits a spawn at the breeding site, if they
 *                  don't move after breeding they will not deposit a spawn. No one knows
 *                  what they do to the babies when they can't move (because they're
 *                  cornered or at the edge of the world). Once the user quits, the world
 *                  ends.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ****************************************************************************************/

int main() {
    //Variables
    int  dimension = 20;
    char choice = 'y';
    bool keepGoing = true;
    int maxDoods = 20;
    int maxAnts = 200;
    srand(time(0));
    
    //Function Declarations
    void runSimulation(Critter *CritterArray[20][20], int dimension);
    void create(Critter *array[20][20], int, int);
    void display(Critter *CritterArray[20][20], int dimension);
    void resetCritMoved(Critter *CritterArray[20][20], int dimension);
    void destroyWorld(Critter *CritterArray[20][20], int dimension);
    
    
    
//create & initialize array
    Critter *CritterArray[20][20];
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            CritterArray[i][j] = NULL;
    
    
//create creatures
    cout << "How many DoodleBugs ( @ ) would you like create?\nI suggest 20...\n";
    cin >> maxDoods;
    while (!cin || maxDoods < 0 ){
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << "Please stick to positive whole numbers." << endl;
        cin >>   maxDoods;
    }
    
    cout << "How many Ants ( : ) would you like to create?\nI suggest 200...\n";
    cin >>maxAnts;
    while (!cin || maxAnts < 0 ){
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << "Please stick to positive whole numbers." << endl;
        cin >>   maxAnts;
    }
    
    //call critter initialization function
    create(CritterArray, maxAnts, maxDoods);
    
    
//Run the simulation until user quits
    do {
        
        display(CritterArray, dimension);
        
        runSimulation(CritterArray, dimension);
        
        
        //prompt user to continue or quit
        cout << "\"y\" to see what the critters do next, or any other key to exit.\n";
        cin >> choice;
        if (choice != 'y')
            keepGoing = false;
        
    } while (keepGoing);
    
//delete CritterArray;
    destroyWorld(CritterArray, dimension);
    
    return 0;
}

/*****************************************************************************************
 ** Function: create(Critter *[][20], int, int)
 ** Description: This function spawns Ants and DoodleBugs into their world (a 2D array)
 *                  at random locations. The x and y coordinates of the Critters are 
 *                  determined by the Critter class constructor.
 ** Parameters: (Critter *CritterArray[][20], int maxAnts, int maxDoods)
 *               CritterArray is a 2D 20X20 array of pointers to Critters,
 *               maxAnts is the number of Ants to spawn.
 *               maxDoodles is the number of  DoodleBugs to spawn
 ** Pre-Conditions: A 20 by 20 array of pointers to Critters has been created and
 *                  its elements have been initialized to NULL
 ** Post-Conditions: The array is populated by pointers to the desired number of Ants
 *                   and DoodleBugs placed randomly within the array.
 ****************************************************************************************/
void create(Critter *CritterArray[][20], int maxAnts, int maxDoods) {
    
    Critter *antPoint;
    Critter *doodPoint;
    
    //make Ants
    for (int a = 0; a < maxAnts; a++) {
        antPoint = new Ant;
        if (CritterArray[antPoint->getX()][antPoint->getY()] == NULL)
            CritterArray[antPoint->getX()][antPoint->getY()] = antPoint;
        else {
            delete antPoint;
            a--;
        }
    }
    
    
    //make DoodleBugs
    for (int d = 0; d < maxDoods; d++) {
        doodPoint = new  DoodleBug();
        if (CritterArray[doodPoint->getX()][doodPoint->getY()] == NULL)
            CritterArray[doodPoint->getX()][doodPoint->getY()] = doodPoint;
        else {
            delete doodPoint;
            d--;
        }
        
    }
    


}
/*****************************************************************************************
 ** Function: display(Critter *[][20], int)
 ** Description: This function iterates through the 2D array of pointers to Critters and 
 *                   prints it out as a 20 by 20 grid, where NULL elements are
 *                   represented by white spaces and species characters ( @ or : )
 *                   where there are Ants ( : ) and DoodleBugs ( @ ).
 ** Parameters: (Critter *CritterArray[20][20], int dimension)
 *                  CritterArray is a 20 x 20 element 2D array of pointers to Critters
 *                  dimension is the legth and width of the array (20)
 ** Pre-Conditions: an Array of pointers to Critters, initialized with Critters.
 ** Post-Conditions: The array is printed out on the screen with NULL elements 
 *                   represented by white spaces and species characters ( @ or : ) 
 *                   where there are Ants and DoodleBugs.
 ****************************************************************************************/
void display(Critter *CritterArray[20][20], int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (CritterArray[i][j] != NULL)
                cout << CritterArray[i][j]->getChar();
            else if (CritterArray[i][j] == NULL)
                cout << " ";
        }
        cout << endl;
    }
}


/*****************************************************************************************
 ** Function: runSimulation(Critter *[][20], int)
 ** Description: This program is passed a 20 by 20 element array of pointers to Critters 
 *                 by reference. The function then iterates through the array looking for 
 *                 pointers to Critters. If it comes accross one, it identifies it as an
 *                 Ant or a DoodleBug and calls its class member functions to see if it's 
 *                 old enough to breed or die. If it's a 10 day old Ant or a 3 day
 *                 starved DoodleBug, the Critter is erased and the array spot set to
 *                 null.
 *                 If the function didn't just kill the Critter, then it calls the class
 *                 member function move(), if the function returns a 1 the Critter moves
 *                 one spot to the right, if it returns a 2 the Critter moves one spot to
 *                 the left, if it returns a 3 the Critter moves one spot up, and if it
 *                 returns a 4 the Critter moves down one spot. If there's a conspecific
 *                 they moving means stepping off the array, then they stay in the same
 *                 spot. If they are old enough to breed and they moved, then they will 
 *                 deposit a spawn at the spot they just left behind. If the Critter is a 
 *                 DoodleBug and it just moved onto an Ant then the Ant is deleted and the 
 *                 DoodleBugs life data member is set to 0 so it doesn't starve.
 ** Parameters: (Critter *CritterArray[20][20], int dimension)
 *                  CritterArray is a 20 x 20 element 2D array of pointers to Critters
 *                  dimension is the legth and width of the array (20)
 ** Pre-Conditions: an Array of pointers to Critters, initialized with Critters.
 ** Post-Conditions: Every Critter within the array is updated. If possible, it moved 
 *                   one spot, died and got erased, was eaten and got erased, or bred and
 *                   created a new pointer of a conspecific. All the Critters within the 
 *                   array also aged by 1 and got 1 "day" closed to breeding and dying.
 ****************************************************************************************/
void runSimulation(Critter *CritterArray[20][20], int dimension) {
  
    int  move;
    bool breed = false,
         die = false;
    char species = 'x';

for (int i = 0; i < dimension; i++)
    for (int j = 0; j < dimension; j++)
    {
        //If there's a Critter here
        if(CritterArray[i][j] != NULL) {
            //reset Critter life flags
            move = 0;
            breed = false;
            die = false;
            species = CritterArray[i][j]->getChar();
        
            //IT'S AN ANT'S LIFE
            if(CritterArray[i][j] != NULL &&
               CritterArray[i][j]->critMoved() == false && species == ':')
            {
                breed = static_cast<Ant*>(CritterArray[i][j])->breed();
            
                die = static_cast<Ant*>(CritterArray[i][j])->die();
                
                if (die) {
                    delete CritterArray[i][j];
                    CritterArray[i][j] = NULL;
                }
                
            //lets move
                if (!die)
                    move = CritterArray[i][j]->move(); //ant just aged
                
            //move right
                if (move == 1 && (i+1) < dimension) {
                    if (CritterArray[i+1][j] == NULL)
                    {
                        CritterArray[i+1][j] = CritterArray[i][j];
                        if (breed)
                            CritterArray[i][j] = new Ant();
                        else
                            CritterArray[i][j] = NULL;
                    }
                }
            //move left
                else if (move == 2 && (i-1) > 0) {
                    if (CritterArray[i-1][j] == NULL)
                    {
                        CritterArray[i-1][j] = CritterArray[i][j];
                        if (breed)
                            CritterArray[i][j] = new Ant();
                        else
                            CritterArray[i][j] = NULL;
                    }
                }
            //move up
                else if (move == 3 && (j+1) < dimension) {
                    if (CritterArray[i][j+1] == NULL)
                    {
                        CritterArray[i][j+1] = CritterArray[i][j];
                        if (breed)
                            CritterArray[i][j] = new Ant();
                        else
                            CritterArray[i][j] = NULL;
                    }
                }
            //move down
                else if (move == 4 && (j-1) > 0) {
                    if (CritterArray[i][j-1] == NULL)
                    {
                        CritterArray[i][j-1] = CritterArray[i][j];
                        if (breed)
                            CritterArray[i][j] = new Ant();
                        else
                            CritterArray[i][j] = NULL;
                    }
                }
        } //done with the Ants
        
            
        //IT'S A DOODLEBUG'S LIFE
        if(CritterArray[i][j] != NULL
           && CritterArray[i][j]->critMoved() == false && species == '@')
        {
            breed = static_cast<DoodleBug*>(CritterArray[i][j])->breed();
            
            die = static_cast<DoodleBug*>(CritterArray[i][j])->die();
            
            if (die) {
                delete CritterArray[i][j];
                CritterArray[i][j] = NULL;
            }
        //let's move
            if (!die)
                move = CritterArray[i][j]->move(); //DoodleBug just aged
                
            //move right
                if (move == 1 && (i+1) < dimension) {
                    if (CritterArray[i+1][j] == NULL
                        || CritterArray[i+1][j]->getChar() != '@')
                    {
                        if (CritterArray[i+1][j] != NULL
                            && CritterArray[i+1][j]->getChar() == ':')
                        { //lets eat
                            static_cast<DoodleBug*>(CritterArray[i][j])->Eat();
                            delete CritterArray[i+1][j];
                        }
                        CritterArray[i+1][j] = CritterArray[i][j]; // @ moved
                        if (breed)
                            CritterArray[i][j] = new DoodleBug();
                        else
                            CritterArray[i][j] = NULL;
                        }
                }
        //move left
            if (move == 2 && (i-1) > 0) {
                if (CritterArray[i-1][j] == NULL
                    || CritterArray[i-1][j]->getChar() != '@')
                {
                    if (CritterArray[i-1][j] != NULL
                        && CritterArray[i-1][j]->getChar() == ':')
                    { //lets eat
                        static_cast<DoodleBug*>(CritterArray[i][j])->Eat();
                        delete CritterArray[i-1][j];
                    }
                    CritterArray[i-1][j] = CritterArray[i][j]; // @ moved
                    if (breed)
                        CritterArray[i][j] = new DoodleBug();
                    else
                        CritterArray[i][j] = NULL;
                }
            }
        //move up
            if (move == 3 && (j+1) < dimension) {
                if (CritterArray[i][j+1] == NULL
                    || CritterArray[i][j+1]->getChar() != '@')
                {
                    if (CritterArray[i][j+1] != NULL
                        && CritterArray[i][j+1]->getChar() == ':')
                    { //lets eat
                        static_cast<DoodleBug*>(CritterArray[i][j])->Eat();
                        delete CritterArray[i][j+1];
                    }
                    CritterArray[i][j+1] = CritterArray[i][j]; // @ moved
                    if (breed)
                        CritterArray[i][j] = new DoodleBug();
                        else
                            CritterArray[i][j] = NULL;
                }
            }
            //move down
            if (move == 4 && (j-1) > 0) {
                if (CritterArray[i][j-1] == NULL
                    || CritterArray[i][j-1]->getChar() != '@')
                {
                    if (CritterArray[i][j-1] != NULL
                        && CritterArray[i][j-1]->getChar() == ':')
                    { //lets eat
                        static_cast<DoodleBug*>(CritterArray[i][j])->Eat();
                        delete CritterArray[i][j-1];
                    }
                    CritterArray[i][j-1] = CritterArray[i][j]; // @ moved
                    if (breed)
                        CritterArray[i][j] = new DoodleBug();
                    else
                        CritterArray[i][j] = NULL;
                }
            }
            
        }// done with the DoodleBugs
    }
}

//reset the Critter's moved bool variable
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            if(CritterArray[i][j] != NULL)
                if(CritterArray[i][j]->critMoved() == true)
                    CritterArray[i][j]->setMoved(false);
}

/*****************************************************************************************
 ** Function: resetCritMoved()
 ** Description: This is a simple function that iterates through the 2D array encompassing
 *               the Critters' world and resets the class member bool variable moved to 
 *               false, this bool prevents a Critter that moved further down the array from
 *               being accessed multiple times in the runSimulation function's for loops.
 ** Parameters: (Critter *CritterArray[20][20], int dimension)
 *                  CritterArray is a 20 x 20 element 2D array of pointers to Critters
 *                  dimension is the legth and width of the array (20)
 ** Pre-Conditions: an Array of pointers to Critters, initialized with Critters.
 ** Post-Conditions: All of the Critters' move bool variables are set to false
 ****************************************************************************************/
void resetCritMoved(Critter *CritterArray[20][20], int dimension) {
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            if(CritterArray[i][j] != NULL)
                if(CritterArray[i][j]->critMoved() == true)
                    CritterArray[i][j]->setMoved(false);
}

/*****************************************************************************************
 ** Function: destroyWorld(Critter *CritterArray[20][20], int dimension)
 ** Description: This is a function that iterates through a 20 by 20 2D array of pointers 
 *                 to Critters and deletes all the Critters within the array to deallocate
 *                 the memory before the program quits.
 ** Parameters: (Critter *CritterArray[20][20], int dimension)
 *                  CritterArray is a 20 x 20 element 2D array of pointers to Critters
 *                  dimension is the legth and width of the array (20)
 ** Pre-Conditions: an Array of pointers to Critters, initialized with Critters.
 ** Post-Conditions: All of the Critters the array pointed to are erased and the memory 
 *                   dealloted. The Pointers are also erased.
 ****************************************************************************************/
void destroyWorld(Critter *CritterArray[20][20], int dimension) {
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            if(CritterArray[i][j] != NULL)
                delete CritterArray[i][j];
}


