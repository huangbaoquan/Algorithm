// author : bqhuang
// date   : 2015/10/22

/********************************************************************************** 
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example:Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
***********************************************************************************/ 

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if(head == NULL)
		return NULL;
	ListNode* pre = head;
	ListNode* next = head->next;
	while(next)
	{
		if(pre->val == next->val)
		{
			ListNode* temp = next->next;
			pre->next = temp;
			delete next;
			next = pre->next;
		}
		else
		{
			pre = next;
			next = next->next;
		}
	}
	return head;
}
