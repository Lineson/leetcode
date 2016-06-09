#include "stdlib.h"
#include "stdio.h"


/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    struct ListNode *next;
};


/*Your runtime beats 88.96% of csubmissions.*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *cur = NULL;
	struct ListNode *res = NULL;
	int sum = 0;
	int isfirst = 1;

	while(l1 || l2 || sum){
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next; 
		}
		
		if (isfirst) {
			cur = (struct ListNode *)malloc(sizeof(struct ListNode));
			cur->next = NULL;
			isfirst = 0;
			res = cur;
		}
		else {
			cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			cur = cur->next;
		}

		cur->val = sum%10;
		cur->next = NULL;
		sum /= 10; 
	}
	return res;
}

/*Your runtime beats 20.30% of csubmissions.*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;  
    if(l2 == NULL) return l1;

	struct ListNode *cur;
	cur = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *res = cur;

	int sum = 0;

	while(l1 || l2){
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next; 
		}

		cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = sum%10;

		sum /= 10; 
	}
	if (sum)
	{
		cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = sum%10;
	}
	cur->next = NULL;
	return res->next;
}










//-----------------------------JUST A joking blew---------------------------//
void print_list(struct ListNode *head) {
	while(head){
		printf("%d, ", head->val);
		head = head->next;
	}
	printf(".\n");
}


int reserve_list(struct ListNode **head) {
	int len = 0;
	struct ListNode *s = NULL;
	struct ListNode *cur = *head;
	struct ListNode *t;
	while(cur) {
		len++;
		t = cur->next;
		cur->next = s;
		s = cur;
		cur = t;
	}
	*head = s;
	return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int len1, len2;
	int sum, e1;
	// print_list(l1);
	// print_list(l2);

    len1 = reserve_list(&l1);
    len2 = reserve_list(&l2);

	// print_list(l1);
	// print_list(l2);

	struct ListNode *l1_bk = l1;
	struct ListNode *l2_bk = l2;


    if (len1 >= len2) {
    	while(len1 > len2) {
    		l1 = l1->next;
    		len1--;
    	}
    	sum = 0;
    	e1 = 0;
    	while(l1) {
    		l1->val = l1->val + l2->val + e1;
    		if (l1->val >= 10) {
    			l1->val = l1->val - 10;
    			e1 = 1;
    		}
    		else {
    			e1 = 0;
    		}
    		l1 = l1->next;
    		l2 = l2->next;
    	}
    	if (e1 > 0) {
    		l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    		l1 = l1->next;
    		l1->next = NULL;
    		l1->val = 1;
    	}
    	// reserve_list(&l1_bk);
		// print_list(l1_bk);
    	return l1_bk;
    }
    else {
    	while(len1 < len2) {
    		l2 = l2->next;
    		len2--;
    	}
    	sum = 0;
    	e1 = 0;
    	while(l2) {
    		l2->val = l1->val + l2->val + e1;
    		if (l2->val >= 10) {
    			l2->val = l2->val - 10;
    			e1 = 1;
    		}
    		else {
    			e1 = 0;
    		}
    		l1 = l1->next;
    		l2 = l2->next;
    	}
    	if (e1 > 0) {
    		l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    		l2 = l2->next;
    		l2->next = NULL;
    		l2->val = 1;
    	}
    	reserve_list(&l2_bk);
		// print_list(l2_bk);
    	return l2_bk;
    }
}


int main(int argc, char const *argv[])
{
    struct ListNode l1[5];
    l1[0].val = 1;
    l1[0].next = &l1[1];

    l1[1].val = 4;
    l1[1].next = &l1[2];

    l1[2].val = 3;
    l1[2].next = NULL;

    struct ListNode l2[5];
    l2[0].val = 5;
    l2[0].next = &l2[1];

    l2[1].val = 6;
    l2[1].next = &l2[2];

    l2[2].val = 4;
    l2[2].next = NULL;


    struct ListNode *lis1;
    struct ListNode *lis2;

    lis1 = &l1[0];
    lis2 = &l2[0];

    addTwoNumbers(lis1, lis2);

	return 0;
}