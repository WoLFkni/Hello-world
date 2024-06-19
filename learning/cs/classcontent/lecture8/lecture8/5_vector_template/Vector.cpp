#include "Linked_List.h"
#include "Vector.h"

Vector::Vector() : lst(nullptr) {}
Vector::~Vector()
{
    clear();
}

//Copy constructor
Vector::Vector(const Vector& vec)
{
    lst = copy(vec.lst);
}

//Assignment operator
Vector& Vector::operator=(const Vector& vec)
{
    if (this != &vec) {
        clear();
        lst = copy(vec.lst);
    }
    return *this;
}


int Vector::size() const
{
    int i = 0;
    LinkedList* l = lst;
    while (l != nullptr) {
        i++;
        l = l->next;
    }
    return i;
}

bool Vector::isEmpty() const
{
    return lst == nullptr;
}

void Vector::clear()
{
    destroy(lst);
    lst = nullptr;
}

int Vector::get(int i)
{
    LinkedList** p = getIth(&lst, i);
    if (p == nullptr)
        return 0;
    else
        return (*p)->value;
}

void Vector::set(int i, int v)
{
    LinkedList **p = getIth(&lst, i);
    if (p != nullptr)
        (*p)->value = v;
}

void Vector::add(int v)
{
    int sz = size();
    LinkedList **p = getIth(&lst, sz);
    LinkedList *newl = new LinkedList;
    newl->value = v;
    *p = newl;
}

void Vector::insert(int i, int v)
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

void Vector::remove(int i)
{
    LinkedList **p = getIth(&lst, i);

    if (p != nullptr) {
        LinkedList *current = *p;
        LinkedList *next = current->next;
        delete current;
        *p = next;
    }
}

// Index operator
int& Vector::operator[](int i)
{
    LinkedList **p = getIth(&lst, i);
    return (*p)->value;
}
