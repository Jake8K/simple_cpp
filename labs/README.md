# Simple Programs in C++: The Labs

## Lab A
### Write, compile, and test a program that uses dependency files and arrays
static version prompts the user for 10 numbers to sum and average, dynamic version prompts for the number of numbers to sum and average
- to compile :  from the source code directory```make```  to make both versions or ```make static```/```make dynamic```
- to run: ```avg_s``` for the static version and ```avg_d``` for the dynamic version
- to remove: ```make clean```

## Lab B
### Design, write, compile, and test a program that uses class inheritance
The user is prompted with a request for the number of sides in a regular die and a loaded die (rolls have a 10% chance of being augmented by 1), the user is then prompted for the number of times to roll both dice, at which point the program will output the results
- to compile : ```make``` from the source code directory
- to run: ```dice```
- to remove: ```make clean```

## Lab C
### Implement recursive functions and practice file I/O
This programs takes the contents of an input file and outputs the contents into an output file in reverse order. Both files must already exist. The user will be prompted for the file names.
- to compile : ```make``` from the source code directory
- to run: ```rev```
- to remove: ```make clean```

## Lab D
### Refine requirements for a program using inheritance Implement the requirements using polymorphism and Object Oriented Programming
This program takes an input file and either a) copies it into a new file, b) creates a version where the contents are all uppercase, c) outputs a simple encryption of the file, or d) creates a Caesar cyher file
- to compile : ```make``` from the source code directory
- to run: ```manipulate```
- to remove: ```make clean```

## Lab E
### Implement a linked structure structures (circular linked list) using pointers
This program stores characters entered by the user in a circular linked list. The user can peak at the character at the head of the linked list or view (and delete) all the values stored in the circular linked list.
- to compile : ```make``` from the source code directory
- to run: ```cll```
- to remove: ```make clean```

## Lab Fa
### Implement linear data structures using linked structures
Menu driven program featuring stack and queue implementations & demonstration of their differences using a linked list.
- to compile : ```make``` from the source code directory
- to run: ```staque```
- to remove: ```make clean```

## Lab Fb
### Implement linear data structures using linked structures part deux
Use the stack from labFa to implement a Reverse Polish Notation calculator
- to compile : ```make``` from the source code directory
- to run: ```rpn```
- to remove: ```make clean```

## Lab G
### Implement a queue and simple algorithms for searching and sorting
Read numbers from an input file into an array and demonstrate *linear search*, *bubble sort*, and *binary search*. It also ouputs the sorted array into a new file (user specified name/extension).
- to compile : ```make``` from the source code directory
- to run: ```search```
- to remove: ```make clean```


## Lab H
### Compare the runtime of the iterative and recursive implementation of the MergeSort algorithm.
Prompts the user for an input file name and the number of random integers to populate the file with in order to demonstrate MergeSort. The program then runs an iterative and a recursive version of mergeSort and displays the respective runtimes for the algorithm. The output of each algorithm along with the runtimes are also printed to an output file named margeSort.txt
note: append input files generated by the program with .in to have the makefile script remove the file with ```cleanall``` command.
- to compile : ```make``` from the source code directory
- to run: ```ms```
- to remove executable: ```make clean```
- to remove all files generated: ```make cleanall``` (removes executable, files ending in ```.in``` and mergeSort.txt)

