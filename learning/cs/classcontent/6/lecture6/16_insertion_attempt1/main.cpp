#include <iostream>

using namespace std;

// Definition of Linked List
struct LinkedList{
    int value;
    LinkedList* next;
};

// Traverse and print the values in the linked list
void print(LinkedList* l) {
    for (LinkedList* p = l; p != nullptr; p = p->next)
        cout << p->value << " ";
    cout << endl;
}

// Add a node to the head of a linked list
void push(LinkedList** proot, int value) {
    LinkedList* newl = new LinkedList;
    newl->value = value;
    newl->next = *proot;
    *proot = newl;
}

// Remove a node in the front
void pop(LinkedList** proot) {
    LinkedList *p = *proot;
    if (p == nullptr)
        return;
    LinkedList* next = p->next;
    delete p;
    *proot = next;
}

void destroy(LinkedList* l) {
    while (l != nullptr)
        pop(&l);
}

// Insertion attempt
void insert(LinkedList* root, int value)
{
    LinkedList *prev = nullptr, *current = root;

    while (current->value < value) {
        prev = current;
        current = current->next;
    }

    LinkedList *newl = new LinkedList;
    newl->next = current;
    newl->value = value;
    prev->next = newl;
}

int main()
{
    LinkedList *list1 = nullptr;
    push(&list1, 10);
    push(&list1, 5);
    push(&list1, 3);
    insert(list1, 6);
    print(list1);
    // insert(list1, 20);
    insert(list1, 2);
    destroy(list1);
    return 0;
}
