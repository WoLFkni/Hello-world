#include <iostream>
#include "linked_list.h"

using namespace std;

void print(LinkedList* l) {
    for (LinkedList* p = l; p != nullptr; p = p->next)
        cout << p->value << " ";
    cout << endl;
}

// Add a node to the head of a linked list
void push(LinkedList** l, int value) {
    LinkedList* newl = new LinkedList;
    newl->value = value;
    newl->next = *l;
    *l = newl;
}

// Remove a node in the front
void pop(LinkedList** l) {
    LinkedList *p = *l;
    if (p == nullptr)
        return;
    LinkedList* next = p->next;
    delete p;
    *l = next;
}

void destroy(LinkedList* l) {
    while (l != nullptr)
        pop(&l);
}

void insert(LinkedList** proot, int value)
{
    LinkedList *prev = nullptr, *current = *proot;

    while (current != nullptr && current->value < value) {
        prev = current;
        current = current->next;
    }

    LinkedList *newl = new LinkedList;
    newl->next = current;
    newl->value = value;
    if (prev == nullptr)
        *proot = newl;
    else
        prev->next = newl;
}
