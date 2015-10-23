//author : bqhuang
//date   : 2015/10/23

/********************************************************************************** 
 * Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
* Credits:
* Special thanks to @stellari for adding this problem and creating all test cases.
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


ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA == NULL || headB == NULL)
		return NULL;
	int lena = 0;
	int lenb = 0;
	int gap = 0;
	ListNode* nodeA = headA;
	ListNode* nodeB = headB;
	while(nodeA)
	{
		lena++;
		nodeA=nodeA->next;
	}
	while(nodeB)
	{
		lenb++;
		nodeB=nodeB->next;
	}
	gap = (lena > lenb) ? (lena-lenb):(lenb-lena);
	printf("gap length: %d\n",gap);
	nodeA = headA;
	nodeB = headB;
	if(lena > lenb)
	{
		for(int i=0;i<gap;i++)
			nodeA = nodeA->next;
	}
	else
	{
		for(int j=0;j<gap;j++)
			nodeB = nodeB->next;
	}
	while(nodeA)
	{
		if(nodeA->val == nodeB->val)
		{
			printf("the first common node: %d",nodeA->val);
			return nodeA;
		}
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
	return NULL;
}

int main()
{
	ListNode* headA = tailInsert(10);
	printList(headA);
	ListNode* headB = tailInsert(6);
	printList(headB);
	getIntersectionNode(headA,headB);
}
