#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED


// Definition of Linked List
template <class T>
struct LinkedList{
    T value;
    LinkedList* next;

    LinkedList() : value(), next(nullptr)
    {}
};


// Add a node to the head of a linked list
template <class T>
void push(LinkedList<T>** l, T value)
{
    LinkedList<T>* newl = new LinkedList<T>;
    newl->value = value;
    newl->next = *l;
    *l = newl;
}

// Remove a node in the front
template <class T>
void pop(LinkedList<T>** l)
{
    LinkedList<T> *p = *l;
    if (p == nullptr)
        return;
    LinkedList<T> *next = p->next;
    delete p;
    *l = next;
}

// Copy the list
template <class T>
LinkedList<T>* copy(LinkedList<T>* l)
{
    if (l == nullptr)
        return nullptr;

    LinkedList<T>* newl = new LinkedList<T>;
    newl->value = l->value;
    newl->next = copy(l->next);
    return newl;
}

// Destroy the list
template <class T>
void destroy(LinkedList<T>* l)
{
    while (l != nullptr)
        pop(&l);
}

// Get a pointer l-value that points to the ith element of the list
template <class T>
LinkedList<T>** getIth(LinkedList<T>** l, int i)
{
    LinkedList<T> **pcurrent = l, *current;

    for (int k = 0; k < i; k++) {
        current = *pcurrent;
        if (current == nullptr)
            return nullptr;
        pcurrent = &current->next;
    }

    return pcurrent;
}



#endif // LINKED_LIST_H_INCLUDED
