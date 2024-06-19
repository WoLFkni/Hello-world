# include "link.h"

void push(ListNode **root, int val){
}

ListNode* BuildList(int num[], int length){
    ListNode dummy;
    ListNode *p = &dummy;
    for (int i = 0; i < length; i++){
        ListNode* numi = new ListNode;
        numi->val = num[i];
        p->next = numi;
        p = numi;
    }
    p->next = nullptr;
    return dummy.next;
}  // Todo: Build a list of node and return the head node.
ListNode* removeKthFromEnd(ListNode* head, int k){
    ListNode dummy;
    dummy.next = head;
    ListNode *current = &dummy;
    ListNode *newhead = head;
    for (int i = 0; i < k; i++){
        head = head->next;
    }
    while (head != nullptr){
        head = head->next;
        current = current->next;
    }
    if (current != &dummy){
        ListNode *del = current->next;
        (*current).next = del->next;
        current = current->next;
        delete del;
        return newhead;
    }else{
        ListNode *del = newhead;
        newhead = newhead->next;
        delete del;
        return newhead;
    }
} // Todo: Remove the Kth node from end, and return the head node after that.
void deleteAllNodes(ListNode* head){
    ListNode *current = nullptr;
    while (head != nullptr){
        current = head;
        head = head->next;
        delete current;
        current = nullptr;
    }
} // Todo: Remove all nodes in the list.
