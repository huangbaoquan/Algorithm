// author: bqhuang
// date: 2015/10/24

/***********************************************************************************
* Given a linked list, swap every two adjacent nodes and return its head.
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. 
* You may not modify the values in the list, only nodes itself can be changed.
* *************************************************************************************/

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


ListNode* swapPairs(ListNode* head) {
	if(head == NULL)
		return NULL;
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	ListNode* pre = myhead;
	ListNode* first = head;
	ListNode* second = head->next;
	ListNode* temp;
	while(pre != NULL && first != NULL && second != NULL)
	{
		temp = second->next;	
		pre->next = second;
		second->next = first;
		first->next = temp;

		pre = first;
		first = pre->next;
		if(first == NULL)
			return myhead->next;
		second = first->next;
		if(second == NULL)
			return myhead->next;
	}
	return myhead->next;
}

int main()
{
	ListNode* head = tailInsert(1);
	printList(head);
	printList(swapPairs(head));
}
