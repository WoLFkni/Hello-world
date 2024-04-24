#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
    LinkedList *list1 = nullptr;
    push(&list1, 10);
    push(&list1, 5);
    push(&list1, 3);
    insert(&list1, 6);
    insert(&list1, 20);
    insert(&list1, 2);
    print(list1);

    destroy(list1);
    return 0;
}
