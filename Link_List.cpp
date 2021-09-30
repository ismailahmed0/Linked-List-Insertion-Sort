#include "Link_List.h"
#include <iostream>

using namespace std;

void ListValues::displayList() const
{
    Node *nodePtr; // to move through the list
    int n = 0;
    nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << endl; // display node value

        nodePtr = nodePtr->next; // next node
        n++;
    }
    cout << "Number of items in list: " << n << endl;
    n = 0;
}

void ListValues::insertValue(double num)
{
    Node *newNode; // new node
    Node *nodePtr; // traverse list
    Node *previousNode = nullptr; // previous node

    // allocate a new node and store num there
    newNode = new Node;
    newNode->value = num;

    // if no nodes in list
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head; // position at head of list
        previousNode = nullptr; // initialize previousNode to nullptr

        // skip nodes values less than num
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if new node 1st on list
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

ListValues::~ListValues()
{
    Node *nodePtr; // traverse list intent
    Node *nextNode; // point to next node

    nodePtr = head; // head of list

    while (nodePtr != nullptr) // while not at end
    {
        nextNode = nodePtr->next; // save pointer
        delete nodePtr; // delete node
        nodePtr = nextNode; // new node position
    }
}
