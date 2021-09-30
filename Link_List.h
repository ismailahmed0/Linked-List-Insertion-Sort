#ifndef LINK_LIST_H_INCLUDED
#define LINK_LIST_H_INCLUDED

class ListValues
{
    private:
        struct Node // data structure
        {
            double value; // node value
            struct Node *next; // points to next node
        };

        Node *head;
    public:
        // constructor
        ListValues()
        {
            head = nullptr;
        }
        // destructor
        ~ListValues();

        //Linked list operations

        void insertValue(double); // mutator
        void displayList() const; // accessors
};

#endif // LINK_LIST_H_INCLUDED
