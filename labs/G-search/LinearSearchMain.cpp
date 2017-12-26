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
    
    int choice = 0;
    bool exit = false;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inFileName,
                outFileName;
    int arraySize,
        intSought,
        elmnt,
        i,
        index = 0;
    int *intArray;
    int numArray[99990];
    // ADD int Sought PROMPT function
    // ADD error catching function for reutns of -5
    // ADD enqueue and copy to array function, and getIndex() function
    
    
    
    
    
//MAIN FUNCTION
    inFileName = getInputFile();
    inputFile.open(inFileName.c_str());

//copy the numbers into a dynamic array
    cout << "copying numbers to file:\n";
    intArray = new int[arraySize];

    index = 0;
    while ( !inputFile.eof()) {
        inputFile >> numArray[i];
        cout << numArray[i] << " ";
        index++;
        
/*        //if the array fills up, double the size of the array
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
       }        */
        
    }
    cout << "\n";
    
//Copy the array to a new one to get rid of the "empty" spaces
    intArray = new int[index];
    //copy contents
    for (int i = 0; i < index; i++) {
        intArray[i] = numArray[i];
        cout << intArray[i];
    }
    arraySize = index;
    
    
//close, rewind, and reset the input file
    inputFile.clear();
    inputFile.seekg(0L, std::ios::beg);
    inputFile.close();
 
 

    do {
    //prompt the user for int to find
        intSought = getInt();
        
    //find the number and print location
        elmnt = linearSearch(intArray, arraySize, intSought);
        if (elmnt == 99999)
            cout << "Error, number not found";
        else
            cout << "The number you're looking for is item " << (elmnt + 1)
                 << " in the file.";
                

        std::cout << "\n\n press 1 to quit\n";
        std::cin >> choice;
        if (choice == 1)
            exit = true;
        
       } while (!exit);

    delete [] intArray;
    
    return 0;
}
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
int getInt() {
    int num;
    cout << "What number are you looking for in your data file?\n";
    cin >> num;
    
    return num;
}


/*

  while(inputFile >> numList[i])
 
 for(int i=0; i<listSize; i++) {
 outputFile << numList[i]
 
 
 so I open the file then store the integers in an array with
 from Keisha to jake (privately):
 while(inputFile >> numList[i])
 from Keisha to jake (privately):
 then as a test right below it I have cout << numList[i]; to make sure its copying correctly
 from Keisha to jake (privately):
 then I have an if statement that grows the array if it gets full
 from jake to Keisha (privately):
 how do you deal with empty spaces?
 from jake to Keisha (privately):
 What I did is I went through the file and counted the number of ints, then I made an array the size of the number of ints
 from jake to Keisha (privately):
 and I pretty much used the same code in a for loop
 from Keisha to jake (privately):
 hmmm I haven't run into that issue.  My text files is a list of numbers so 1 <enter> 99 <enter> 45 <enter>
 from jake to Keisha (privately):
 Oh sorry, I meant empty sdpaces in the array
 from jake to Keisha (privately):
 like you can't have a null int because that's just 0
 from Keisha to jake (privately):
 oh I initialize it to zero then fill it any extra spaces are still zero.  I just explained  in my design document
 from jake to Keisha (privately):
 but then you can't find the 0
 from jake to Keisha (privately):
 I guess that's not a bad idea though, gets you most of the points still
 from jake to Keisha (privately):
 I'm wondering if a while loop will work
 from jake to Keisha (privately):
 how did you output your sorted array? outFile.put(int) or outFile >> int ?
 from Keisha to jake (privately):
 yeah, I contemplated making them -1 but then theoretically the user could provide a text file with negatives, zeros and positives so I just explained that in my design doc
 from Keisha to jake (privately):
 I think the prof was just using 0 as an example anyway
 from jake to Keisha (privately):
 yeah
 from Keisha to jake (privately):
 I did a for loop
 from Keisha to jake (privately):
 for(int i=0; i<listSize; i++) {
 from Keisha to jake (privately):
 outputFile << numList[i]

 outFileName = getOutputFile();
 outputFile.open(outFileName.c_str());
 
 BubbleSort(intArray, arraySize);
 
 //print sorted array to file
 cout << "copying numbers to file:\n";
 for (int i = 0; i < arraySize; i++) {
 cout << intArray[i] << " ";
 outputFile << intArray[i];
 }
 
 // reset the eof flag, rewind, file, close files
 //   if (allocated) {
 //       inputFile.clear();
 //       inputFile.seekg(0L, std::ios::beg);
 //       inputFile.close();
 //   }
 outputFile.close();
 std::cout << "\n";
 break;
 
 case 'C':
 /*    if (!allocated) {
 inFileName = getInputFile();
 inputFile.open(inFileName.c_str());
 //      }
 outFileName = getOutputFile();
 outputFile.open(outFileName.c_str());
 intSought = getInt();
 
 //     if (!allocated) {
 //count the numbers in the file
 while (!inputFile.eof()) {
 index++;
 }
 //reset file flags and rewind it
 inputFile.clear();
 inputFile.seekg(0L, std::ios::beg);
 
 
 //copy the numbers into a dynamic array
 cout << "copying numbers to file:\n";
 arraySize = index;
 intArray = new int[arraySize];
 i = 0;
 while ( !inputFile.eof()) {
 inputFile >> intArray[i];
 cout << intArray[i] << " ";
 i++;
 }
 /*for (int i = 0; i < arraySize; i++) {
 inputFile >> intArray[i];
 cout << intArray[i] << " ";
 } */
        /*cout << endl << endl;
        
        allocated = true;
        //      }
        outFileName = getOutputFile();
        outputFile.open(outFileName.c_str());
        intSought = getInt();
        
        BubbleSort(intArray, arraySize);
        
        
        //print sorted array to file
        cout << "copying numbers to file:\n";
        for (int i = 0; i < arraySize; i++) {
            cout << intArray[i];
            outputFile << intArray[i];
        }
        
        
        elmnt = binarySearch(intArray, arraySize, intSought);
        if (elmnt == -5)
        cout << "Error, number not found";
        else
        cout << "The number you're looking for is item " << (elmnt + 1)
        << " in the output file.";
        
        
        // reset the eof flag, rewind, file, close files
        //      if (allocated) {
        //         inputFile.clear();
        //          inputFile.seekg(0L, std::ios::beg);
        //           inputFile.close();
        //          }
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


*/