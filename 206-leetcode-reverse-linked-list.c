#include "stdlib.h"
#include "stdio.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


/* runtime error! version */
struct ListNode* reverseList(struct ListNode* head) 
{
    if (head == NULL || head->next == 0) return head;
    struct ListNode* h = NULL;
    struct ListNode* t = head;
    struct ListNode* n = t->next;

    while(t != NULL) {
        t->next = h;

        h = t;
        t = n;
        n = t->next;
    }
    head = h;
    return h;
}

struct ListNode* reverseList(struct ListNode* head) 
{ 
    struct ListNode* h = NULL;
    struct ListNode* t = head;
    struct ListNode* n = t;

    while(t != NULL) {
        n = t->next;
        t->next = h;

        h = t;
        t = n;
    }
    head = h;
    return h;
}


int main(int argc, char const *argv[])
{
    struct ListNode l[5];
    l[0].val = 1;
    l[0].next = &l[1];

    l[1].val = 2;
    l[1].next = &l[2];

    l[2].val = 3;
    l[2].next = NULL;

    reverseList(&l[0]);

	return 0;
}