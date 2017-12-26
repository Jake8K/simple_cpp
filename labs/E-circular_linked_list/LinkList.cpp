
/***************************************************************************************
 ** Program Filename: LinkedList.cpp
 ** Author: Jacob Karcz
 ** Date: 7.20.2016
 ** Description: The function implementation file for class LinkList. It manages a list of
 *               char data, implemented with Node structs that hold a char data member and 
 *               a pointer to the next node on the list. It's a circular list so the head
 *               pointer points to the first node on the list and the tail pointer points
 *               to the last one on the list. The class displays and erases nodes at the 
 *               head pointer and adds nodes at the tail end of the list.
 ** Input: as needed by the fucntions, otherwise dependent on programmer implementation
 ** Output: a circular linked list containing char data variables
 ***************************************************************************************/

#include "LinkList.hpp"

/*****************************************************************************************
 ** Function: default constructor
 ** Description: default constructor for LinkList class, 
 *               initializes head and tial pointers to NULL
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: An instance of LinkList with an empty node & all pointers set to NULL
 ****************************************************************************************/
LinkList::LinkList() {
    this->head = NULL;
    this->tail = NULL;
    }
/*****************************************************************************************
 ** Function: addNode(char ch)
 ** Description: Adds a node to the linked list with the character passed. If it's the
 *               first node of the list then it creates a node where the head and tail 
 *               pointers all point to the first node. Ele if it's not the first node it
 *               creates a node at the tail pointer location, stores the char to the 
 *               member char data variable and updates the tail.
 ** Parameters: a char
 ** Pre-Conditions: the list has been instantiated by the constructor (pointers == NULL)
 ** Post-Conditions: a first or new node containing the passed data is added to 
 *                   the circular linked list
 ****************************************************************************************/
void LinkList::addNode(char ch) {
    
    if (head == NULL) {
        head = new Node(ch);
        head->next = head; //IS THIS RIGHT?????????????
        tail = head;
        counter = 1;
    }
    
    else if (tail->data == NULL) {
        tail->data = ch;
        tail = tail->next;
    }
    
    else {
        Node *previousNode = tail; // placeHolder
        tail->next = new Node(ch, previousNode->next);
        tail = tail->next;
        
        counter++;
        
        
        
        //std::cout << "this is addNode, tailPtr = " << tail;
//        tail->next = new Node(ch);
//        tail = tail->next; //connect this to head somehow here, without changing the adding dynamics!!!!!!!!!!!!!!!!!
        //std::cout << " & now tailPtr = " << tail << std::endl;
    }
    
}

/*****************************************************************************************
 ** Function: displayNode()
 ** Description: Displays the node pointed to by the head pointer
 ** Parameters: None
 ** Pre-Conditions: The node exists (if it doesn't, nothing happens... returns NULL)
 ** Post-Conditions: returns the char data member of the node
 ****************************************************************************************/
void LinkList::displayNode() const {
    if (head != NULL) {
        std::cout << head->data;
    }
}

/*****************************************************************************************
 ** Function: getNode()
 ** Description: Displays the node pointed to by the head pointer
 ** Parameters: None
 ** Pre-Conditions: The node exists (if it doesn't, nothing happens... returns NULL)
 ** Post-Conditions: returns the char data member of the node
 ****************************************************************************************/
char LinkList::getNode() const {
    if (head != NULL) {
        return head->data;
    }
    else
        return NULL;
}
/*****************************************************************************************
 ** Function: getCount()
 ** Description: returns the number of nodes that have been created
 ** Parameters: None
 ** Pre-Conditions: A list exists
 ** Post-Conditions: returns the number of nodes in the list.
 ****************************************************************************************/
int LinkList::getCount(){
    return counter;
}

/*****************************************************************************************
 ** Function: cutNode()
 ** Description: deletes the data in the "first" node on the list
 ** Parameters: None
 ** Pre-Conditions: A list exists
 ** Post-Conditions: the node pointed to by head is deallocated
 ****************************************************************************************/
void LinkList::cutNode(){
    
    if (!head)
        return;
    else {
        head->data = NULL;
        head = head->next;
        
        /*Node *garbage = head;
         head = head->next;
         delete garbage;*/
    }
}

/*****************************************************************************************
 ** Function: Destructor
 ** Description: Deallocates the data contained in the LinkedList object
 ** Parameters: None
 ** Pre-Conditions: An instance of the class
 ** Post-Conditions: Poof. The instance is gone and the memory is free again.
 ****************************************************************************************/
LinkList::~LinkList()
{
    Node *nodePtr = this->head;  // Start at head of list
    
    if(head)
    {
        while(nodePtr->next != head) {
            // garbage keeps track of next node to be deleted
            Node *garbage = nodePtr;

            // Delete the "garbage" node
            delete garbage;
            
            // Move on to the next node, if any
            nodePtr = nodePtr->next;
        }
        delete head;
    }
}


