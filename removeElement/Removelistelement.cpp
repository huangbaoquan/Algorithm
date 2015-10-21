// author : bqhuang
// date   : 2015/10/22

/********************************************************************************** 
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
**********************************************************************************/ 

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode* next;
	ListNode(int x): val(x),next(NULL){};
};

ListNode* removeElements(ListNode* head, int val) {
	if(head == NULL)
		return NULL;
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	ListNode* pre = myhead;
	ListNode* node = pre->next;
	while(node)
	{
		if(node->val == val)
		{
			pre->next = node->next;
			delete node;
			node = pre->next;
		}
		else
		{
			pre = node;
			node = node->next;
		}
	}
	return myhead->next;
}
