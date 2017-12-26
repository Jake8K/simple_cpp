/***************************************************************************************
 ** Program Filename: labC.cpp
 ** Author: Jacob Karcz
 ** Date: 7.07.2016
 ** Description: This is a simple program that prompts the user for an input file, 
 *                  from which it extracts the contents into an array of chars. The 
 *                  array is then passed to a recursive function which reverses the 
 *                  order of its contents. The user is then prompted for the name of an 
 *                  exiting output file. once successfully accessed, the contents of 
 *                  the array are written into the output file.
 ** Input: A file with writing, or numbers (function worked on a file of ints) 
 *          & an existing output file. Tested onyl on .txt files.
 ** Output: The output file now contains the contents of the first file, in reverse.
 ***************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;



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
    
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string inFileName,
                outFileName,
                chars;
    int arraySize = 50,
        index = 0;
    char *charArray;
    //recursive function declaration
    void reverse(char array[], int, int);
    
    
    charArray = new char[arraySize];
    for (int i = 0; i < arraySize; i++)
        charArray[i] = ' ';
    
//GET INPUT
    cout << "This program will take the contents of an input file and output them in reverse order to an output file.\nBoth the input file and the output file must already exist (I know, the output part is annoying).\n\n";
    cout << "What's the name of your input file?\n";
    cin >> inFileName;
    inputFile.open(inFileName.c_str());
    
    if(inputFile) {
        while (!inputFile.eof())
        {   //add file contents to array
            inputFile.get(charArray[index]);
            index++;
            
            //if the array fills up, double the size of the array
            if (index == arraySize) {
                int newSize = arraySize * 2;
                char *newArray = new char[newSize];
                for (int i = 0; i < index; i++)
                    newArray[i] = charArray[i];
                char * temp = charArray;
                charArray = newArray;
                delete [] temp;
                arraySize = newSize;
            }

        }
    }
        else { //if the file wasn't accessible
            while (!inputFile) {
                cout << "Could not access file. Did you forget to add the extension?\n";
                cout << "What's the name of your input file?\n";
                cin >> inFileName;
                inputFile.open(inFileName.c_str());
            }
            if(inputFile) { //finally gained access to the file
                while (!inputFile.eof()) {
                    //copy the file into the array, as above
                    inputFile.get(charArray[index]);
                    index++;
                    if (index == arraySize) {
                        int newSize = arraySize * 2;
                        char *newArray = new char[newSize];
                        for (int i = 0; i < index; i++)
                            newArray[i] = charArray[i];
                        char * temp = charArray;
                        charArray = newArray;
                        delete [] temp;
                        arraySize = newSize;
                    }
                }
            }
        }
    
    //close the input file
    inputFile.close();
    
    
//REVERSE THE ARRAY
    reverse(charArray, 0, index);

    
    
//OUTPUT THE RESULTS
    cout << "What's the name of your output file?\n";
    cin >> outFileName;
    
    //check file exists by treating as input
    inputFile.open(outFileName.c_str());
    
    if(inputFile) {
        //close the file
        inputFile.close();
        //open file as output
        outputFile.open(outFileName.c_str());
        //write the reversed array to file
        for(int k = 0; k < arraySize ; k++)
            outputFile << charArray[k];
        
    }
    else {
        while (!inputFile) {
            cout << "Could not access file. Did you forget about the extension?\n";
            cout << "What's the name of your output file?\n";
            cin >> outFileName;
            inputFile.open(outFileName.c_str());
        }
        if (inputFile) {
            inputFile.close();
            outputFile.open(outFileName.c_str());
            for(int k = 0; k < arraySize ; k++)
                outputFile << charArray[k];
        }
    }

    // close file
    outputFile.close();
    
    return 0;
}

/*****************************************************************************************
 ** Function: reverse( char array [], int start, int end)
 ** Description: This is a recursive function that accepts an array as an arguement, 
 *                along with the first and last elements of the array. The function then
 *                reverses the array by swapping the first and last elements of the array,
 *                and passing the array and the next element from the start and the next
 *                element from the end as parameters. The function continues to swap the 
 *                first and last elements and pass the next section of the center of 
 *                the array to itself until it has worked its way to the middle of the 
 *                array, at which point the task is complete and the function no longer 
 *                calls itself. The array from the calling function will be reversed once
 *                the algorithm completes.
 ** Parameters: (char array, index of first element, array size or index of last element)
 ** Pre-Conditions: An array of chars
 ** Post-Conditions: The array is reversed, therefore it must be passed by reference
 ****************************************************************************************/
void reverse(char array[], int start, int end) {
 
    if (start < end) {
        char temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        reverse(array, start + 1, end -1);
    }
    
}

