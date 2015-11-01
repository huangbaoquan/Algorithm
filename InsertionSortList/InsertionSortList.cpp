// author : bqhuang
// date   : 2015/10/25

/********************************************************************************** 
Sort a linked list using insertion sort.
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

void Insert(ListNode* myhead,ListNode* node)
{
	ListNode* curr = myhead; 
	while(curr->val< node->val)
	{
		curr = curr->next;
	}
}


ListNode* InsertionSortList(ListNode* head)
{
	ListNode* node = head;
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	while(node)
	{
		ListNode* cur = node;
		Insert(myhead,cur);
	}
	return myhead->next;
}
