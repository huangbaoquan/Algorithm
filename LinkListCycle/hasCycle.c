// author : bqhuang
// date   : 2015/11/1

/***********************************************************************************
* Given a linked list, determine if it has a cycle in it.
************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	if(head == NULL)
		return false;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while(fast)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL)
			fast = fast->next;
		else
			break;
		if(fast == slow)
			return true;
	}
	return false;
}
