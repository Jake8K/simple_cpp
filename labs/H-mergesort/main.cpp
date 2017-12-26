/***************************************************************************************
 ** Program Filename: main.cpp
 ** Author: Jacob Karcz
 ** Date: 7.10.2016
 ** Description: This is the driver function, the main function to test the relative 
 *               speed of an iterative mergeSort algorithm and a recursive mergeSort 
 *               algorithm. It also creates a file with the user specified number of 
 *               digits between 0 and 1,000 in random order and a file called mergeSort 
 *               with the times of the 2 functions and their printed results.
 ** Input: the number of digits to send to the functions and print to the files
 *         when prompted by the class
 ** Output: the specified input file and a file called mergeSort.txt with the results
 ***************************************************************************************/

#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>      /* clock  */
#include <chrono>     /* precision clock */ //c++ 11+
#include "OpenFiles.hpp"
#include "recursiveMergeSort.hpp"
#include "iterativeMergeSort.hpp"

//#include "iterativeMS.hpp"  // second found code, seg faults earlier
//#include "recursiveMS.hpp"  // second found code, seg faults earlier


using std::cin;
using std::cout;
using std::endl;
using std:: string;

int getSize();



/*****************************************************************************************
 ** Function: Main Function
 ** Description: a function that tests the 2 versions of mergeSort by first asking the 
 *               user for the name of an input file and the number of random digits 
 *               (0-1,000) that they wish to populate the file with. The file is written 
 *               with the random numbers and then the numbers are extracted into a 
 *               dynamic array. The array is copied so that each version of mergeSort 
 *               (iterative and recursive) can receive the same identical unsorted array 
 *               to work on. The arrays are then passed to each function and the runtime
 *               measured using chronos before and after its execution. The time (in ms)
 *               and the sorted array are printed to the output file mergeSort.txt and
 *               the timer results of each is displayed on the screen for immidiate 
 *               comparisson.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: 2 files, the user specified input file name with a list of unsorted 
 *                   numbers and a second file mergeSort.txt with the timer results of
 *                   each function and their respective sorted arrays.
 ****************************************************************************************/
int main() {
    
    int choice = 0;
    bool exit = false;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inFileName,
                outFileName;
    int arraySize,
        num,
        index = 0;
    int *unsortedArray,
        *recusriveArray,
        *iterativeArray;
    //const char numC = '0'; //////////////////////
    //string numberString;
    //int numArray[99990];

    srand(time(0));
    
    
    
    
//MAIN FUNCTION
    
//get number of digits and create input file
//*******************************************
    //open output file
    outFileName = getOutputFile();
    outputFile.open(outFileName.c_str());

    //prompt for number of digits in file
    arraySize = getSize();
    
    //populate the file with digits
    for (int i = 0; i < arraySize; i++) {
        num = (rand() % 1000);
        outputFile << num;
        outputFile << " ";
    }
    
    //close the file
    outputFile.close();
    

//get the numbers from the file and add them to arrays
//******************************************************
    //open file for input
    inFileName = outFileName;
    inputFile.open(inFileName.c_str());
    
    
   //create dynamic array and add the digits to it
    unsortedArray = new int[arraySize];
    index = 0;
    while(inputFile >> unsortedArray[index]) {
        //cout << unsortedArray[index] << endl;
        index++;
    }
    
    //create arrays to pass to each function and populate with unsorted array
    recusriveArray = new int[arraySize];
    iterativeArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        recusriveArray[i] = unsortedArray[i];
        iterativeArray[i] = unsortedArray[i];
    }

    
    //close the file
    inputFile.close();

    cout << "\n\n";
    

 //open a file as output to write results
    outputFile.open("mergeSort.txt");

    
//Complete recursive MergeSort
//******************************************************
    std::chrono::time_point<std::chrono::system_clock> start, end; //declare timer
    
    start = std::chrono::system_clock::now(); //start precision timer
    
    rMergeSort(recusriveArray, 0, arraySize); //perform mergeSort
    //mergesort(recusriveArray, arraySize);
    end = std::chrono::system_clock::now(); //stop precision timer
    
    std::chrono::duration<double> elapsed_seconds = end - start; //calc time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);// exact endTime
    
    cout << "recursive time: " << std::fixed << 1000 * elapsed_seconds.count() << " milliseconds" << endl;
    //cout << "finished recursive computation at " << std::ctime(&end_time)
    //          << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    outputFile << "\n\n Time to complete recursive MergeSort on " << arraySize << " digits: ";
    outputFile << std::fixed << 1000 * elapsed_seconds.count() << " milliseconds" << endl;

    
    
//Complete iterative MergeSort
//******************************************************
    start = std::chrono::system_clock::now(); //start precision timer
    
    iMergeSort(iterativeArray, arraySize); //perform mergeSort
    //merge_sort(iterativeArray, arraySize);
               
    end = std::chrono::system_clock::now(); //stop precision timer
    end_time = std::chrono::system_clock::to_time_t(end); //exact endTime
    
    elapsed_seconds = end - start; //calculate operation time
    
    cout << "iterative time: " << std::fixed << 1000 * elapsed_seconds.count() << " milliseconds" << endl;
    //std::cout << "Finished iterative computation at " << std::ctime(&end_time)
    //          << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    outputFile << "\n\n Time to complete iterative MergeSort on " << arraySize << " digits: ";
    outputFile << std::fixed << 1000 * elapsed_seconds.count() << " milliseconds" << endl;


    
//Print sorted digits from  MergeSort
//******************************************************

    outputFile << "\n\nThe output of recursive mergesort:\n";
    for (int i = 0; i < arraySize; i++) {
        outputFile << recusriveArray[i];
        outputFile << " ";
    }
    outputFile << endl << endl;
    
    outputFile << "\n\nThe output of iterative mergesort:\n";
    for (int i = 0; i < arraySize; i++) {
        outputFile << iterativeArray[i];
        outputFile << " ";
    }
    
    cout << endl << endl;

    outputFile.close();
    
    cout << "Please find mergeSort results in new file, mergeSort.txt\n\n";
    
    //deallocate the memory
    delete [] unsortedArray;
    delete [] recusriveArray;
    delete [] iterativeArray;
    
    return 0;
}
/*****************************************************************************************
 ** Function:getInt()
 ** Description: simple fucnction that prompts the user for a number and returns it
 ** Parameters: None
 ** Pre-Conditions: none
 ** Post-Conditions: returns the number the user entered
 ****************************************************************************************/
int getSize() {
    int num;
    cout << "How many digits would you like to populate the file with? \n"
         << "note: numbers less than 100 or greater than 2,000,000 maye cause a \n"
         << "segmentation fault due to a bug in the iterative implementation of MergeSort\n";
    cin >> num;
    
    return num;
}

/*
 //Complete recursive MergeSort
 //******************************************************
 
 double startRecursive = clock(); //start timing
 
 rMergeSort(recusriveArray, 0, arraySize); //perform mergeSort
 
 double stopRecursive = clock(); //stop timing
 
 cout << "recursive time: " << std::fixed << (stopRecursive - startRecursive)/double(CLOCKS_PER_SEC)*1000 << endl;
 outputFile << "\n\n Time to complete recursive MergeSort on " << arraySize << " digits: ";
 outputFile << std::fixed << (stopRecursive - startRecursive)/double(CLOCKS_PER_SEC)*1000 << endl;
 //cout using << std::fixed << instead of << std::setprecision(5)
 */
