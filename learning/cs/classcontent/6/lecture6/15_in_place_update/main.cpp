#include <iostream>

using namespace std;

// Definition of Linked List
struct LinkedList{
    int value;
    LinkedList* next;
};

// Traverse and print the values in the linked list
void print(LinkedList* root) {
    for (LinkedList* p = root; p != nullptr; p = p->next)
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

int main()
{
    LinkedList *list1 = nullptr;
    push(&list1, 10);
    push(&list1, 3);
    push(&list1, 5);
    print(list1);

    destroy(list1);
    return 0;
}
