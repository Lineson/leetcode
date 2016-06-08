/*Definition for singly-linked list.*/

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head) return head;
    struct ListNode *h = head;
    struct ListNode *cur = head->next;
    struct ListNode *t;
    int h_val;

    while(cur) {
	    h_val = h->val;
    	if (cur->val != h_val) {
    		h = cur;
    		cur = cur->next;
    	}
    	else {
    		t = cur->next;
    		if (t) {
	    		while(t->val == h_val) {
	    			struct ListNode *tmp = t;
	    			t = t->next;
	    			free(tmp);
	    			if (!t) break;
	    		}
    		}
    		h->next = t;
    		h = t;
    		if(h) cur = h->next;
    		else cur = 0;
    	}
    }
    return head;
}