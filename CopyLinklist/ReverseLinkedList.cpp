// author : bqhuang
// date   : 2015/10/22

/********************************************************************************** 
* Reverse a singly linked list.
* click to show more hints.
* Hint:
* A linked list can be reversed either iteratively or recursively. 
* Could you implement both?
***********************************************************************************/ 

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

/*
 * reverse List
 */
ListNode* reverseList(ListNode* head) {
	if(head == NULL)
		return NULL;
	ListNode* pre = NULL;
	ListNode* node = head;
	ListNode* next = head->next;
	while(node)
	{
		node->next = pre;
		pre = node;
		node = next;
		if(node == NULL)
			return pre;
		next = next->next;
	}
	return pre;
}

int main()
{
	ListNode* head = tailInsert(10);
	printList(head);

	ListNode* reversehead = reverseList(head);
	printList(reversehead);
}
