//author: bqhuang
//Date: 2015/10/13

/********************************************************************************** 
* Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both? 
***********************************************************************************/ 

#include <iostream>
#include <stdlib.h>
using namespace std;

struct LNode
{
	int data;
	LNode* next;
};

/*
 *Create Linklist
 */
LNode* tailInsert(int len)
{
	LNode* L = (LNode*)malloc(sizeof(LNode));//Create head node
	L ->next = NULL;
	LNode* tail;//point to last Node of LinkList
	tail = L;
	while(len--)
	{
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node->data = rand() % 100;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	return L;
}

/*
 * Tranversal
 */
void printList(LNode* L)
{
	if(L == NULL)
	{
		printf("list is null by printList");
		return;
	}
	LNode* node = L;
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}

/*
* Reverse a singly linked list.
*/
LNode* ReverseLinklist(LNode* L)
{
	if(L == NULL)
	{
		printf("list is null by ReverseLinklist");
		return NULL;
	}
	LNode* pre = NULL;
	LNode* next = NULL;
	LNode* curr = L;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	return pre;
}

int main()
{
	LNode* L = tailInsert(10);
	printList(L);
	printf("after reversal:\n");
	LNode* RList = ReverseLinklist(L);
	printList(RList);
}
