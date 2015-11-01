// author : bqhuang
// date   : 2015/11/1

/***********************************************************************************
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
************************************************************************************/

#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	ListNode* Node;
	if(l1->val > l2->val)
	{
		Node = l2;
		Node->next = mergeTwoLists(l1,l2->next);
	}
	else
	{
		Node = l1;
		Node->next = mergeTwoLists(l1->next,l2);
	}
	return Node;
}
