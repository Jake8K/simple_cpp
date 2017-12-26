
/***************************************************************************************
 ** Program Filename:
 ** Author: Jacob Karcz
 ** Date:
 ** Description:  
 ** Input:
 ** Output:
 ***************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Dice.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Gollum.hpp"
#include "ReptilePeople.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
using std::cout;
using::std::cin;
using std::endl;
using std::string;

char getCharacter();
void fight(Creature *, Creature *);

/*****************************************************************************************
 ** Function: main()
 ** Description:
 ** Parameters: None
 ** Pre-Conditions: Creature abstract base class nad other relvenat class files included
 ** Post-Conditions: returns 0 if no errors encountered
 ****************************************************************************************/
int main() {
    
    Creature *fighter1;
    Creature *fighter2;
    int cont = 1;
    int round = 1;
    char player;
    
    srand(time(0));
    
//prompt for player 1 character
    cout << "Player 1, ";
    player = getCharacter();
    if (player == 'A')
        fighter1 = new Medusa();
    else if (player == 'B')
        fighter1 = new Gollum();
    else if (player == 'C')
        fighter1 = new ReptilePeople();
    else if (player == 'D')
        fighter1 = new BlueMen();
    else if (player == 'E')
        fighter1 = new HarryPotter();
    else if (player == 'F')
        cout << "FATAL ERROR, please restart\n";

//prompt for player 2 character
    cout << "Player 2, ";
    player = getCharacter();
    if (player == 'A')
        fighter2 = new Medusa();
    else if (player == 'B')
        fighter2 = new Gollum();
    else if (player == 'C')
        fighter2 = new ReptilePeople();
    else if (player == 'D')
        fighter2 = new BlueMen();
    else if (player == 'E')
        fighter2 = new HarryPotter();
    else if (player == 'F')
        cout << "FATAL ERROR, please restart\n";

// Time to Battle!
    do {
        cout << "Round " << round << "... fight!\n******************\n\n";
        
        //if player 1 is still kicking, fight on!
        if(fighter1->getStrength() > 0 && fighter2->getStrength() > 0)
            fight(fighter1, fighter2);
        if (fighter2->getStrength() <= 0) { //player 1 just won
            cout << "\nPlayer 1 victoriously vanquished player 2!\n\n";
            cont = 0;
        }
        cout << endl;
        
        //if player 2 is still kicking, fight on!
        if(fighter1->getStrength() > 0 && fighter2->getStrength() > 0)
            fight(fighter2, fighter1);
        if (fighter1->getStrength() <= 0) { //player 2 just won
            cout << "\nPlayer 2 victoriously vanquished player 1!\n\n";
            cont = 0;
        }
        
        //everyone's still alive, prompt for next round.
        if(fighter1->getStrength() > 0 && fighter2->getStrength() > 0) {
            cout << "\n\t[ press 1 to fight another round ]\n";
            cin >> cont;
            cout << "\n";
        }
        round++;
        
    } while (cont == 1);
    
    delete fighter1;
    delete fighter2;
    
    
    return 0;
}

/*****************************************************************************************
 ** Function: fight(Creature *, Creature *)
 ** Description:
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions:
 ****************************************************************************************/
void fight(Creature *offense, Creature *defense){
    int attackPts = 0;
    attackPts = offense->attack();
    defense->defend(attackPts);
}



/*****************************************************************************************
 ** Function: Default Constructor
 ** Description: Creates a HarryPotter with the his "special" attributes
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: There's delusional child that believes in magic waving a stick around
 ****************************************************************************************/
char getCharacter() {
    char choice;
    bool goOn = true;
    
    do {
        cout << "choose your creature character!\n"
            << "\"A\" Medusa, \"B\" Gollum, \"C\" Reptile People, "
            << "\"D\" Blue Men, or \"E\" Harry Potter?\n";
            cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                cout << "Great, you're a Medusa. No one wants to look at you.\n\n";
                goOn = false;
                return 'A';
                break;
            case 'B':
                cout << "Great, you're Gollum... but why?\n\n";
                goOn = false;
                return 'B';
                break;
            case 'C':
                cout << "Great, you're Reptile People. You sound pretty badass.\n\n";
                goOn = false;
                return 'C';
                break;
            case 'D':
                cout << "Great, you're Blue Men. I like your song with Dave Mathews.\n\n";
                goOn = false;
                return 'D';
                break;
            case 'E':
                cout << "Great, you're Harry Potter. I assume Gollum was taken.\n\n";
                goOn = false;
                return 'E';
                break;
    
            default:
                break;
        }
    } while (goOn);

//error message
 return 'F';
}



