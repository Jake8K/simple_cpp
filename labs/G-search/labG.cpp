//
//  labG.cpp
//  labG
//
//  Created by Jacob Karcz on 8/6/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <stdio.h>

//
//  main.cpp
//  labG
//
//  Created by Jacob Karcz on 8/3/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <stdio.h>
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
    int num,
        intSought,
        elmnt,
        i,
        arraySize = 20,
        index = 0;
    int *intArray;
    bool allocated = false;
    
    //copy the numbers into a dynamic array
    cout << "copying numbers to file:\n";
    intArray = new int[arraySize];
    
    index = 0;
    while ( !inputFile.eof()) {
        inputFile >> intArray[i];
        cout << intArray[i] << " ";
        index++;
        
        //if the array fills up, double the size of the array
        if (index == arraySize) {
            int newSize = arraySize * 2;
            int *newArray;
            newArray = new int[newSize];
            //copy contents
            for (int i = 0; i < index; i++)
                newArray[i] = intArray[i];
            //get rid of the temp
            int *temp = intArray;
            intArray = newArray;
            delete [] temp;
            arraySize = newSize;
        }
        
    }
    cout << "\n";
    
    //Copy the array to a new one to get rid of the "empty" spaces
    int *finalArray;
    finalArray = new int[index];
    //copy contents
    for (int i = 0; i < index; i++)
        finalArray[i] = intArray[i];
    //get rid of the temp
    int *temp = intArray;
    intArray = finalArray;
    delete [] temp;
    arraySize = index;

    
    
    
    
    
    
// open input file and copuy contents to int array
    
    inFileName = getInputFile();
    inputFile.open(inFileName.c_str());
    
    cout << "copying numbers to file:\n";
    intArray = new int[arraySize];
    
    //initialize array to 0s
    for (int i = 0; i < arraySize; i++)
        intArray[i] = 0;
    
    index = 0;
    while ( !inputFile.eof()) {
        inputFile >> intArray[i];
        cout << intArray[i] << " ";
        index++;
        
        //if the array fills up, double the size of the array
        if (index == arraySize) {
            int newSize = arraySize * 2;
            int *newArray = new int[newSize];
            //initialize array to 0's
            for (int i = 0; i < newSize; i++)
                newArray[i] = 0;
            //copy contents
            for (int i = 0; i < index; i++)
                newArray[i] = intArray[i];
            //get rid of the temp
            int *temp = intArray;
            intArray = newArray;
            delete [] temp;
            arraySize = newSize;
        }

    } cout << endl << endl;
    
    inputFile.clear();
    inputFile.seekg(0L, std::ios::beg);
    inputFile.close();
    
    do {
        std::cout << "\nChoose from the following options:" << std::endl;
        std::cout << "  A. Use linear search to find a number in your file\n"
        "  B. Sort the numbers in your file and write them to a new file\n"
        "  C. Use binary search to find a number in your file\n"
        "  D. Quit\n\n";
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                intSought = getInt();
                
                //use linear search on array
                elmnt = linearSearch(intArray, index, intSought);
                if (elmnt == -5)
                    cout << "Error, number not found";
                else
                    cout << "The number you're looking for is item " << (elmnt + 1)
                         << " in the file.";
                    cout << "\n";
                break;
                
            case 'B':
                outFileName = getOutputFile();
                outputFile.open(outFileName.c_str());
               
                //sort array
                BubbleSort(intArray, index);
                
                //print sorted array to file
                cout << "copying numbers to file:\n";
                for (int i = 0; i < index; i++) {
                    cout << intArray[i];
                    outputFile << intArray[i];
                }
    
                outputFile.close();
                std::cout << "\n";
                break;
                
            case 'C':

                outFileName = getOutputFile();
                outputFile.open(outFileName.c_str());
                intSought = getInt();
                
                //sort array (just in case)
                BubbleSort(intArray, arraySize);
                
                //print sorted array to file
                cout << "copying numbers to file:\n";
                for (int i = 0; i < index; i++) {
                    cout << intArray[i];
                    outputFile << intArray[i];
                }
                
                //use binary search
                elmnt = binarySearch(intArray, index, intSought);
                
                if (elmnt == -5)
                    cout << "Error, number not found";
                else
                    cout << "The number you're looking for is item " << (elmnt + 1)
                    << " in the output file.";
                
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
    
    
    if (allocated)
        delete [] intArray;
    
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

 