//author: bqhuang
//Date: 2015/10/13

/********************************************************************************** 
* 初阶：复制一个简单链表。假设链表节点只包含data和next。
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
	LNode* tail;//point to last Node of LinkList
	LNode* L = (LNode*)malloc(sizeof(LNode));//Create head node
	L ->next = NULL;
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
	LNode* node = L;
	while(node)
	{
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}
/*
 * print node by interval is one node
 */
void _print(LNode* L)
{
	LNode* node = L;
	while(node)
	{
		printf("%d ",node->data);
		node = node->next->next;
	}
	printf("\n");
}
LNode* CopyLinklist(LNode* List)
{
	if(List == NULL)
		return NULL;
	LNode* node= List;
	while(node)
	{
		LNode* newNode = (LNode*)malloc(sizeof(LNode));
		newNode->data = node->data;
		newNode->next = node->next;
		node->next = newNode;
		node = newNode->next;
	}
	return List;
}

int main()
{
	LNode* Linklist = tailInsert(10);
	printList(Linklist);
	CopyLinklist(Linklist);
	printList(Linklist);
	_print(Linklist);
}
