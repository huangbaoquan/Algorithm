// author: bqhuang
// date  : date

/***********************************************************************************
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
************************************************************************************/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 *Create Linklist
 */
ListNode* tailInsert(int len)
{
	ListNode* tail;//point to last Node of LinkList
	ListNode* L = (ListNode*)malloc(sizeof(ListNode));//Create head node
	L ->next = NULL;
	tail = L;
	while(len--)
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->val= rand() % 100;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	return L;
}

/*
 * Tranversal
 */
void printList(ListNode* L)
{
	ListNode* node = L;
	while(node)
	{
		printf("%d ",node->val);
		node = node->next;
	}
	printf("\n");
}

ListNode* reverseList(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* pre = NULL;
	ListNode* node = head;
	ListNode* suf = node->next;
	while(node)
	{
		node->next = pre;
		pre = node;
		node = suf;
		if(node == NULL)
			return pre;
		suf = suf->next;
	}
	return NULL;
}

bool isPalindrome(ListNode* head)
{
	if(head == NULL)
		return false;
	ListNode* newhead = new ListNode(0);
	newhead->next = head;
	ListNode* slow = newhead;
	ListNode* fast = newhead;
	while(fast)
	{
		fast = fast->next;
		if(fast)
			fast = fast->next;
		else
			break;
		slow = slow->next;
	}
	ListNode* tailhead= reverseList(slow->next);
	while(head && tailhead)
	{
		if(head->val != tailhead->val)
			return false;
		head = head->next;
		tailhead = tailhead->next;
	}
	return true;
}

int main()
{
	ListNode* head = tailInsert(10);
	printList(head);
	printList(reverseList(head));
}
