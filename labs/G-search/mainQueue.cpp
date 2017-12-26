//
//  main.cpp
//  labG
//
//  Created by Jacob Karcz on 7/31/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "QueueClass.hpp"
#include "OpenFiles.hpp"
#include "LinearSearch.hpp"
#include "BubbleSort.hpp"
#include "BinarySearch.hpp"
using std::cin;
using std::cout;
using std::endl;
using std:: string;

int getInt();


/*****************************************************************************************
 ** Function: Main Function
 ** Description: This is the main function for a simple program that prompts the user for
 *                  an input file, from which it extracts the contents into an array of
 *                  chars. The array is then passed to a recursive function which
 *                  reverses the order of its contents. The user is then prompted for
 *                  the name of an exiting output file. once successfully accessed,
 *                  the contents of the array are written into the output file.
 ** Parameters: None
 ** Pre-Conditions: An input file, output file, and existing reverse() function (@ end)
 ** Post-Conditions: The output file now contains the contents of the first file,
 *                   in reverse.
 ****************************************************************************************/
int main() {
    
    char choice;
    bool exit = false;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inFileName,
                outFileName;
    int arraySize,
        num,
        intSought,
        elmnt,
        i,
        index = 0;
    int *intArray;
    QueueClass intQueue;

    
    // ADD int Sought PROMPT function
    // ADD error catching function for reutns of -5
    // ADD enqueue and copy to array function, and getIndex() function
    
    int numArray[10] {3, 5, 8, 10, 0, 4, 2, 1, 9, 18};
    
    intSought = getInt();
    
    cout << "Ok, the program will first look for " << intSought
         << " using linear search:\n";
    
    elmnt = linearSearch(numArray, 10, intSought);
    
    if (elmnt == 99999)
        cout << "Error, number not found\n\n";
    else
        cout << "The number you're looking for is item " << (elmnt + 1)
        << " in the file.\n\n";

    cout << "The program is now sorting the numbers in your file using the "
         << "bubbleSort code.\n Here they are in order:\n";
    BubbleSort(numArray, 10);
    for (int i = 0; i < 10; i++)
        cout << numArray[i] << " ";
        cout << "\n\n";

    cout << "Ok, the program will now look for " << intSought
    << " using the much more efficient binary search:\n";
    elmnt = binarySearch(numArray, 10, intSought);
    if (elmnt == -5)
        cout << "Error, number not found\n\n";
    else
        cout << "The number you're looking for is item " << (elmnt + 1)
        << " in the output file.\n\n";
    


//MAIN FUNCTION
  /*
    cout << "Lets get started by using linear search to find a number in your file.\n";
    inFileName = getInputFile();
    inputFile.open(inFileName.c_str());
    intSought = getInt();
    
    elmnt = linearSearch(intArray, arraySize, intSought);
    
    if (elmnt == -5)
        cout << "Error, number not found\n\n";
    else
        cout << "The number you're looking for is item " << (elmnt + 1)
        << " in the file.\n\n";
    
    cout << "Now lets put the numbers in the file in order so we can use binary search.\n";
    outFileName = getOutputFile();
    outputFile.open(outFileName.c_str());
    
    BubbleSort(intArray, arraySize);
    
    //print sorted array to file
    for (int i = 0; i < arraySize; i++) {
        outputFile.put(intArray[i]);
        outputFile.put(' ');
    }
    
    intSought = getInt();
    elmnt = binarySearch(intArray, arraySize, intSought);
    if (elmnt == -5)
        cout << "Error, number not found";
    else
        cout << "The number you're looking for is item " << (elmnt + 1)
        << " in the output file.";

    */
    
    
/*
    do {
        //implement pointer here?
        std::cout << "\nChoose from the following options:" << std::endl;
        std::cout << "  A. Use linear search to find a number in your file\n"
        "  B. Sort the numbers in your file and write them to a new file\n"
        "  C. Use binary search to find a number in your file\n"
        "  D. Quit\n\n";
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                inFileName = getInputFile();
                inputFile.open(inFileName.c_str());
                intSought = getInt();
                
                
                //retrieve input file data
                //cout << "Retrieving from file:\n\n";  //error check input code
                while (!inputFile.eof()) {
//                    inputFile >> num;
//                    //cout << num << " ";               //error check input code
//                    intQueue.addBack(num);
                    index++;
                }   //cout << endl << endl;             //error check input code
                
                
                //copy the queue into a dynamic array
                //cout << "Copying Queue to Array\n\n";
                arraySize = index;
                intArray = new int[arraySize];
//                for (int i = 0; i < arraySize; i++) { // or while(!intQueue.isEmpty())
//                    intArray[i] = intQueue.getFront();
                    //cout << intQueue.getFront() << " ";
//                    intQueue.removeFront();
//                } //cout << endl << endl;
                i = 0;
                while ( !inputFile.eof()) {
                    inputFile >> intArray[i];
                    cout << intArray[i] << " ";
                    i++;
                } cout << endl << endl;
                
                elmnt = linearSearch(intArray, arraySize, intSought);
                if (elmnt == -5)
                    cout << "Error, number not found";
                else
                    cout << "The number you're looking for is item " << (elmnt + 1)
                         << " in the file.";
                
                // reset the eof flag, rewind, file, close files
                inputFile.clear();
                inputFile.seekg(0L, std::ios::beg);
                inputFile.close();
                delete [] intArray;
                std::cout << "\n";
                break;
                
            case 'B':
                inFileName = getInputFile();
                outFileName = getOutputFile();
                inputFile.open(inFileName.c_str());
                outputFile.open(outFileName.c_str());
                
                //retrieve input file data
                while (!inputFile.eof()) {
                    inputFile >> num;
                    intQueue.addBack(num);
                    index++;
                }
                
                //copy the queue into a dynamic array
                arraySize = index;
                intArray = new int[arraySize];
                for (int i = 0; i < arraySize; i++) { // or while(!intQueue.isEmpty())
                    intArray[i] = intQueue.getFront();
                    intQueue.removeFront();
                }
                
                BubbleSort(intArray, arraySize);
                
                //print sorted array to file
                for (int i = 0; i < arraySize; i++) {
                    outputFile.put(intArray[i]);
                    outputFile.put(' ');
                }

                delete [] intArray;
                // reset the eof flag, rewind, file, close files
                inputFile.clear();
                inputFile.seekg(0L, std::ios::beg);
                inputFile.close();
                outputFile.close();
                std::cout << "\n";
                break;
                
            case 'C':
                inFileName = getInputFile();
                outFileName = getOutputFile();
                intSought = getInt();
                inputFile.open(inFileName.c_str());
                outputFile.open(outFileName.c_str());
                
                //retrieve input file data
                while (!inputFile.eof()) {
                    inputFile >> num;
                    intQueue.addBack(num);
                    index++;
                }
                
                //copy the queue into a dynamic array
                arraySize = index;
                intArray = new int[arraySize];
                for (int i = 0; i < arraySize; i++) { // or while(!intQueue.isEmpty())
                    intArray[i] = intQueue.getFront();
                    intQueue.removeFront();
                }
                
                BubbleSort(intArray, arraySize);
                //print sorted array to file
                for (int i = 0; i < arraySize; i++) {
                    outputFile.put(intArray[i]);
                    outputFile.put(' ');
                }
                
                elmnt = binarySearch(intArray, arraySize, intSought);
                if (elmnt == -5)
                    cout << "Error, number not found";
                else
                    cout << "The number you're looking for is item " << (elmnt + 1)
                    << " in the output file.";
                
                
                delete [] intArray;
                // reset the eof flag, rewind, file, close files
                inputFile.clear();
                inputFile.seekg(0L, std::ios::beg);
                inputFile.close();
                outputFile.close();
                std::cout << "\n";
                break;
                
            case 'D':
                exit = true;
                break;
                
            default:
                if (!exit)
                    std::cout << "\nPlease choose a valid option.\n";
                break;
        }
    } while (!exit);
    
    // close files
    inputFile.close();
    outputFile.close();


   // delete [] intArray;
  */
    return 0;
}
/***************************************************************************************/
int getInt() {
    int num;
    cout << "What number are you looking for in your data file?\n";
    cin >> num;
    
//    while (!ispunct(num) && !isalpha(num)) {
//        cout << "Input Error. What number are you looking for in your data file?\n";
//        cin >> num;
//    }
    return num;
}

