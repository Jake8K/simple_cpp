/***************************************************************************************
 ** Program Filename: labD.cpp
 ** Author: Jacob Karcz
 ** Date: 7.12.2016
 ** Description: This is a simple program using polymorphic class inheritance. A switch 
 *               statement prompts the user whether they wish to take an input file and
 *               turn it into uppercase letters, copy it, encrypt it, or turn it into a
 *               casesar cipher. After making a choice, the user is prompted for an input 
 *               file and an output file name, if encryption is selected, the user is 
 *               also prompted for a an integer to use as a key. once the input is 
 *               submitted, the desired output is written to a file that is either 
 *               created at run-time or overwritten if previously existing. The user 
 *               also has the option to quit.
 ** Input: An input file name, an integer if encryption
 ** Output: output file containing a manipulated copy of the input file
 ***************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Transformer.hpp"
#include "Copy.hpp"
#include "Encryption.hpp"
#include "ToUpper.hpp"
#include "OrderedOutput.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;



/*****************************************************************************************
 ** Function: Main Function
 ** Description: This is the main function for a simple program using polymorphic classes
 *               inheritance. A switch statement prompts the user if they want to copy 
 *               the document, turn it into uppercase letters, encrypt it, or make a
 *               casesar cipher. After making a choice, the user is prompted for an input
 *               file and an output file name by getInputFile() and getOutputFile(), 
 *               respectively, which return the file anmes to open the respective files.
 *               If the user selects one of the encryption options, the user is also
 *               prompted for a key by the getKey() function. The abstract base class 
 *               is then initialized with an instance of the appropriate subclass, and it 
 *               calls the polymorphic class's doFilter() function which performs the 
 *               action of copying or manipulating the input file's data and writing it to
 *               the output file. The pointer is then deleted and the files closed. If the 
 *               user does not select quit, the deleted pointer is re-declared at the 
 *               start of the do while loop.
 ** Parameters: None
 ** Pre-Conditions: An input file exists
 ** Post-Conditions: An output file containing the input file's manipulated data
 ****************************************************************************************/
int main() {
 
//variable declarations
    int key;
    char choice;
    bool exit = false;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inFileName,
                outFileName;
//    Transformer *transPtr;
    
//function declarations
    string getInputFile();
    string getOutputFile();
    int getKey();
    
    
//MAIN FUNCTION
    do {
        Transformer *transPtr;
        std::cout << "\nChoose from the following options:" << std::endl;
        std::cout << "  A. Copy your document\n"
                     "  B. Encrypt your document\n"
                     "  C. Turn your document into upper case letters\n"
                     "  D. Turn your document into a Caesar cypher\n"
                     "  E. Quit\n\n";
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                    inFileName = getInputFile();
                    outFileName = getOutputFile();
                    inputFile.open(inFileName.c_str());
                    outputFile.open(outFileName.c_str());
                
                    transPtr = new Copy;
                    transPtr->doFilter(inputFile, outputFile);
                    delete transPtr;
                
                    inputFile.close();
                    outputFile.close();
                    std::cout << "\n";
                break;
                
            case 'B':
                    key = getKey();
                    inFileName = getInputFile();
                    outFileName = getOutputFile();
                    inputFile.open(inFileName.c_str());
                    outputFile.open(outFileName.c_str());
                
                    transPtr = new Encryption(key);
                    transPtr->doFilter(inputFile, outputFile);
                    delete transPtr;

                
                    inputFile.close();
                    outputFile.close();
                    std::cout << "\n";
                break;
                
            case 'C':
                    inFileName = getInputFile();
                    outFileName = getOutputFile();
                    inputFile.open(inFileName.c_str());
                    outputFile.open(outFileName.c_str());
                
                    transPtr = new ToUpper;
                    transPtr->doFilter(inputFile, outputFile);
                    delete transPtr;

                
                    inputFile.close();
                    outputFile.close();
                    std::cout << "\n";
                break;
                
            case 'D':
                    key = getKey();
                    inFileName = getInputFile();
                    outFileName = getOutputFile();
                    inputFile.open(inFileName.c_str());
                    outputFile.open(outFileName.c_str());
                
                    transPtr = new OrderedOutput(key);
                    transPtr->doFilter(inputFile, outputFile);
                    delete transPtr;
                
                    inputFile.close();
                    outputFile.close();
                    std::cout << "\n";
                break;
            case 'E':
                exit = true;
                
            default:
                if (!exit)
                    std::cout << "\nPlease choose a valid option.\n";
                break;
        }
    } while (!exit);

    // close files
    inputFile.close();
    outputFile.close();
    
    return 0;
}
/*****************************************************************************************
 ** Function: getInputFile()
 ** Description: A function that originally performed the action of opening the file and
 *               returned the stream object, but since flip did not like this action it
 *               is now only repsobsible for verifying that the input file exists. Once 
 *               the file's existance is verified, the file name is returned by the
 *               function
 ** Parameters: None
 ** Pre-Conditions: An input file exists in the directory
 ** Post-Conditions: returns the input file's name
 ****************************************************************************************/
string getInputFile() {
    std::ifstream inputFile;
    std::string inFileName;
    
    cout << "What's the name of your input file?\n";
    cin >> inFileName;
    inputFile.open(inFileName.c_str());
    

        while (!inputFile) {
            cout << "Could not access file. Did you forget to add the extension?\n";
            cout << "What's the name of your input file?\n";
            cin >> inFileName;
            inputFile.open(inFileName.c_str());
        }
    inputFile.close();
    return inFileName;
}
    
/*****************************************************************************************
 ** Function: getOutputFile()
 ** Description: A function that prompts the user for an output file name and returns
 *               the output file name. It doesn not verify existance (anymore).
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: returns the output file name
 ****************************************************************************************/
string getOutputFile() {
    std::string   outFileName;

    cout << "What's the name of your output file?\n";
    cin >> outFileName;
    
    return outFileName;

}


/*****************************************************************************************
 ** Function: getKey()
 ** Description: A simple function that prompts the user for a number to use as 
 *               an encryption key
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: returns an int
 ****************************************************************************************/
int getKey() {
    int key = 0;
    
    std::cout << "What is the encryption key?\n Key must be a positive integer.\n";
    std::cin >> key;
    
    while (!std::cin || key < 0 ) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "What is the encryption key?\n Key must be a positive integer.\n";
        std::cin >>   key;
    }
    
    return key;
}



