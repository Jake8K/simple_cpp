/***************************************************************************************
 ** Program Filename: Stack.cpp
 ** Author: a student in cs162
 ** Date: 7.10.2016
 ** Description: This is the function implementation file for a stack to hold ints
 ** Input: As required by the function
 ** Output: as defined in the functions
 ***************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Stack.hpp"

using std::cout;


/*********************************************************************
** Function: Stack
** Description: Constructor sets top pointer to NULL
** Parameters: N/A
*********************************************************************/
Stack::Stack()
{
	top = NULL; 
}

/*********************************************************************
** Function: push
** Description: pushes the argument onto the stack
** Parameters: int input
*********************************************************************/
void Stack::push(int input)
{
	top = new StackNode(input, top);
}

/*********************************************************************
** Function: peek
** Description: returns the value on top of the stack
*********************************************************************/
int Stack::peek()
{

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		return top->value;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();
	return top->value;*/
}

/*********************************************************************
** Function: pop
** Description: removes the value at the top of the stack
** Parameters: int input
*********************************************************************/
void Stack::pop()
{
	StackNode* temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		temp = top;
		top = top->next;
		delete temp;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();	
	temp = top;
	top = top->next;
	delete temp;*/
	
}

/*********************************************************************
** Function: isEmpty
** Description: returns true if the stack is empty or false if stack
is not empty
*********************************************************************/
bool Stack::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}