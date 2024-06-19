#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "linked_list.h"

template <class T>
class Vector{
public:
    Vector() : lst(nullptr)
    { }

    ~Vector()
    {
        clear();
    }

    //Copy constructor
    Vector(const Vector& vec)
    {
        lst = copy(vec.lst);
    }

    //Assignment operator
    Vector& operator=(const Vector& vec)
    {
        if (this != &vec) {
            clear();
            lst = copy(vec.lst);
        }
        return *this;
    }

    int size() const
    {
        int i = 0;
        LinkedList<T>* l = lst;
        while (l != nullptr) {
            i++;
            l = l->next;
        }
        return i;
    }

    bool isEmpty() const
    {
        return lst == nullptr;
    }

    void clear()
    {
        destroy(lst);
        lst = nullptr;
    }

    T get(int i)
    {
        LinkedList<T> **p = getIth(&lst, i);
        if (p == nullptr)
            return 0;
        else
            return (*p)->value;
    }

    void set(int i, T v)
    {
        LinkedList<T> **p = getIth(&lst, i);
        if (p != nullptr)
            (*p)->value = v;
    }

    void add(T v)
    {
        int sz = size();
        LinkedList<T> **p = getIth(&lst, sz);
        LinkedList<T> *newl = new LinkedList<T>;
        newl->value = v;
        *p = newl;
    }

    void insert(int i, T v);
    void remove(int i);

    T& operator[](int i);


private:
    LinkedList<T>* lst;
};

template <class T>
void Vector<T>::insert(int i, T v)
{
    LinkedList<T> **p = getIth(&lst, i);

    if (p != nullptr) {
        LinkedList<T> *current = *p;
        LinkedList<T> *newl = new LinkedList<T>;
        newl->next = current;
        newl->value = v;
        *p = newl;
    }
}

template <class T>
void Vector<T>::remove(int i)
{
    LinkedList<T> **p = getIth(&lst, i);

    if (p != nullptr) {
        LinkedList<T> *current = *p;
        LinkedList<T> *next = current->next;
        delete current;
        *p = next;
    }
}

// Index operator
template <class T>
T& Vector<T>::operator[](int i)
{
    LinkedList<T> **p = getIth(&lst, i);
    return (*p)->value;
}

#endif // VECTOR_H_INCLUDED
