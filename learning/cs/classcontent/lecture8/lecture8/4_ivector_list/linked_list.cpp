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

LinkedList* copy(LinkedList* l)
{
    if (l == nullptr)
        return nullptr;

    LinkedList* newl = new LinkedList;
    newl->value = l->value;
    newl->next = copy(l->next);
    return newl;
}

void destroy(LinkedList* l) {
    while (l != nullptr)
        pop(&l);
}

void insert(LinkedList** proot, int value)
{
    LinkedList *current = *proot;
    LinkedList *newl = new LinkedList;
    newl->next = current;
    newl->value = value;
    *proot = newl;
}

LinkedList** getIth(LinkedList** l, int i)
{
    LinkedList **pcurrent = l, *current;

    for (int k = 0; k < i; k++) {
        current = *pcurrent;
        if (current == nullptr)
            return nullptr;
        pcurrent = &current->next;
    }

    return pcurrent;
}
