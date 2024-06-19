#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

// Definition of Linked List
struct LinkedList{
    int value;
    LinkedList* next;

    LinkedList() : value(), next(nullptr)
    {}
};

// Traverse and print the values in the linked list
void print(LinkedList* l);

// Add a node to the head of a linked list
void push(LinkedList** l, int value);

// Remove a node in the front
void pop(LinkedList** l);

// Copy the list
LinkedList* copy(LinkedList* l);

// Destroy the list
void destroy(LinkedList* l);

// Get a pointer l-value that points to the ith element of the list
LinkedList** getIth(LinkedList** l, int i);

void add(int v);



#endif // LINKED_LIST_H_INCLUDED
