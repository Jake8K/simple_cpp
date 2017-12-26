//
//  OpenFiles.cpp
//  labG
//
//  Created by Jacob Karcz on 8/3/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "OpenFiles.hpp"





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
    
    std::ifstream inFile;
    std::string inFname;
    
    cout << "What's the name of your input file?\n";
    cin >> inFname;
    inFile.open(inFname.c_str());
    
    
    while (!inFile) {
        cout << "Could not access file. Did you forget to add the extension?\n";
        cout << "What's the name of your input file?\n";
        cin >> inFname;
        inFile.open(inFname.c_str());
    }
    inFile.close();
    return inFname;
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
    std::string   outFname;
    
    cout << "What's the name of your output file?\n";
    cin >> outFname;
    
    return outFname;
}
