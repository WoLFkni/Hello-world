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
LinkedList* push(LinkedList* root, int value) {
    LinkedList* newl = new LinkedList;
    newl->value = value;
    newl->next = root;
    return newl;
}

// Remove a node in the front
LinkedList* pop(LinkedList* root) {
    if (root == nullptr)
        return nullptr;
    LinkedList* next = root->next;
    delete root;
    return next;
}

void destroy(LinkedList* root) {
    while (root != nullptr)
        root = pop(root);
}

int main()
{
    LinkedList *list1 = nullptr;
    list1 = push(list1, 10);
    list1 = push(list1, 3);
    list1 = push(list1, 5);
    print(list1);

    destroy(list1);
    return 0;
}
