//
//  main.cpp
//  labG
//
//  Created by Jacob Karcz on 8/3/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
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
        num,
        index = 0;
    int *intArray;
    const char numC = '0'; //////////////////////
    string numberString;
    int numArray[99990];
    // ADD int Sought PROMPT function
    // ADD error catching function for reutns of -5
    // ADD enqueue and copy to array function, and getIndex() function
    

    
    
    
//MAIN FUNCTION
    
//open input file
    inFileName = getInputFile();
    inputFile.open(inFileName.c_str());

//copy the numbers into a dynamic array
    cout << "copying numbers to file:\n";
 //   intArray = new int[arraySize];

    index = 0;
//    while ( !inputFile.eof()) {
//        numC = inputFile.get();
//        num = atoi (numC);
//        if (num != '\n' || num != ' ') {
//            numArray[index] = num;
//            cout << numArray[i] << " ";
//            index++;
//        }
        
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
        
//    }
    
    while(inputFile >> numArray[index]) {
        cout << numArray[index] << endl;
        index++;
    }

    cout << "\n\n";
    
//Copy the array to a new one to get rid of the "empty" spaces
    intArray = new int[index];
    //copy contents
    for (int i = 0; i < index; i++) {
        intArray[i] = numArray[i];
        cout << intArray[i] << " ";
    }
    arraySize = index;
    cout << endl;
    
//close, rewind, and reset the input file
    inputFile.clear();
    inputFile.seekg(0L, std::ios::beg);
    inputFile.close();
 
    cout << "Ok, the program will first demonstrate linear search:\n";

//Linear Search
    do {
    //prompt the user for int to find with linear search
        intSought = getInt();
        
        cout << "Ok, the program will look for " << intSought
        << " using linear search:\n\n";
        
    //find the number and print location
        elmnt = linearSearch(intArray, arraySize, intSought);
        if (elmnt == 99999)
            cout << "Error, number not found";
        else
            cout << "The number you're looking for is item " << (elmnt + 1)
                 << " in the file.";
    //check if user wants to search again
        std::cout << "\n\n press 1 to stop using linear search\n";
        std::cin >> choice;
        if (choice == 1)
            exit = true;
        
       } while (!exit);
    exit = false;
    
    //get output file name and open in
    outFileName = getOutputFile();
    outputFile.open(outFileName.c_str());
    
    cout << "The program is now sorting the numbers in your file using the "
         << "bubbleSort code and writing the contents to your output file.\n"
         << "Here they are in order:\n";
    
//Bubble Sort
    BubbleSort(intArray, arraySize);
    
    //write the sorted contents to file and display them
    for (int i = 0; i < arraySize; i++) {
        cout << intArray[i] << " ";
        outputFile << intArray[i];
        outputFile << " ";
    }
    cout << "\n\n";
    
    cout << "Ok, the program will now demonstrate binary search:\n";
    
// Binary Search
    do {
        intSought = getInt();
        
        cout << "Ok, the program will now look for " << intSought
        << " using the much more efficient binary search:\n";
        
        elmnt = binarySearch(intArray, arraySize, intSought);
        if (elmnt == -5)
            cout << "Error, number not found\n\n";
        else
            cout << "The number you're looking for is item " << (elmnt + 1)
            << " in the output file.\n\n";
        
        std::cout << "\n\n press 1 to quit\n";
        std::cin >> choice;
        if (choice == 1)
            exit = true;
        
    } while (!exit);
    

    delete [] intArray;
    
    return 0;
}
/*****************************************************************************************
 ** Function:getInt()
 ** Description: simple fucnction that prompts the user for a number and returns it
 ** Parameters: None
 ** Pre-Conditions: none
 ** Post-Conditions: returns the number the user entered
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