/*
Linked List Program

A C++ program that asks the user for a file name until they hit *.
With the file name, pulls number from file and adds them to a linked list.
Sorts list and prints by traversing it. Number of items in list printed as well.
Deletes items in the list and catches errors.

Ismail Ahmed
UT Dallas - CS 1337.004
*/

// preprocessor directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Link_List.h"
#include "Link_List.cpp"

using namespace std;

// initialize main function
int main()
{
    double val;
    ifstream infile;
    string fileName;

    cout << "File Name: ";
    cin >> fileName;

    while (fileName != "*")
    {
        ListValues *holder = new ListValues;    // define a NumberList object

        infile.open(fileName.c_str()); // opens with c_string to prevent error

        if (!infile.fail())
        {
            while (!infile.eof()) // don't stop until end of file reached
            {
                infile >> val;
                holder->insertValue(val); // insert number value into node of linked list
            }

            holder->displayList(); // display the values in the list
            cout << endl;
            infile.close();
        }
        else
        {
            cout << "The input file " << '"' << fileName << '"' << " does not exist. Please try again." << endl;
        }

        cout << "File Name: ";
        cin >> fileName;
    }

    return 0; // send 0 to operating system
}
