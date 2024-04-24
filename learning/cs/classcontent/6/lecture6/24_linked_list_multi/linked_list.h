#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

// Definition of Linked List
struct LinkedList{
    int value;
    LinkedList* next;
};

// Traverse and print the values in the linked list
void print(LinkedList* l);

// Add a node to the head of a linked list
void push(LinkedList** l, int value);

// Remove a node in the front
void pop(LinkedList** l);

// Destroy the list
void destroy(LinkedList* l);

// Insertion
void insert(LinkedList** proot, int value);

#endif // LINKED_LIST_H_INCLUDED
