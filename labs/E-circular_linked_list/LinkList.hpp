
/***************************************************************************************
 ** Program Filename: LinkedList.hpp
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

#ifndef Link_hpp
#define Link_hpp

#include <iostream>
class LinkList {

protected:
    struct Node {
        char data;
        Node *next;
        Node(char ch, Node *nextN = NULL) {
            data = ch;
            next = nextN;
        }
    };
    Node *head;
    Node *tail;
    int counter;
    
public:
    LinkList();
    ~LinkList();
    void addNode(char ch);
    void displayNode() const;
    char getNode() const;
    void cutNode();
    void recursiveDisplay(char);
    int getCount();


};


#endif /* Link_hpp */
