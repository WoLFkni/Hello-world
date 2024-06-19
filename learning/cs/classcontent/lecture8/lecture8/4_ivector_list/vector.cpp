#include "Linked_List.h"
#include "Vector.h"

IVector::IVector() : lst(nullptr) {}
IVector::~IVector()
{
    clear();
}

//Copy constructor
IVector::IVector(const IVector& vec)
{
    lst = copy(vec.lst);
}

//Assignment operator
IVector& IVector::operator=(const IVector& vec)
{
    if (this != &vec) {
        clear();
        lst = copy(vec.lst);
    }
    return *this;
}


int IVector::size() const
{
    int i = 0;
    LinkedList* l = lst;
    while (l != nullptr) {
        i++;
        l = l->next;
    }
    return i;
}

bool IVector::isEmpty() const
{
    return lst == nullptr;
}

void IVector::clear()
{
    destroy(lst);
    lst = nullptr;
}

int IVector::get(int i)
{
    LinkedList** p = getIth(&lst, i);
    if (p == nullptr)
        return 0;
    else
        return (*p)->value;
}

void IVector::set(int i, int v)
{
    LinkedList **p = getIth(&lst, i);
    if (p != nullptr)
        (*p)->value = v;
}

void IVector::add(int v)
{
    int sz = size();
    LinkedList **p = getIth(&lst, sz);
    LinkedList *newl = new LinkedList;
    newl->value = v;
    *p = newl;
}

void IVector::insert(int i, int v)
{
    LinkedList **p = getIth(&lst, i);

    if (p != nullptr) {
        LinkedList *current = *p;
        LinkedList *newl = new LinkedList;
        newl->next = current;
        newl->value = v;
        *p = newl;
    }
}

void IVector::remove(int i)
{
    LinkedList **p = getIth(&lst, i);

    if (p != nullptr) {
        LinkedList *current = *p;
        LinkedList *next = current->next;
        delete current;
        *p = next;
    }
}
