// author : bqhuang
// date   : 2015/10/25

/********************************************************************************** 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* return 1->4->3->2->5->NULL.
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
*
* 解题思路：此题的思路是保存指定开始翻转位置的当前节点和前一节点位置
* 翻转操作完成后，把反转后的链表头和尾对应接到上述两个节点
**********************************************************************************/ 

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

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if(head == NULL)
		return NULL;
	if(head != NULL && m == n)
		return head;
	int count = 0;
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	ListNode* pre = head;
	ListNode* tail;

	ListNode* before; 
	ListNode* after;
	ListNode* mNode = myhead;
	while(count < m)
	{
		//pre记录翻转链表断点前位置
		pre = mNode;
		mNode = mNode->next;
		if(mNode == NULL)
			break;
		count++;
	}
	//tail记录翻转链表断开位置
	tail = pre->next;
	//翻转链表
	before = NULL;
	after = mNode->next;
	while(count <= n)
	{
		mNode->next = before;
		before = mNode;
		mNode = after;
		if(mNode == NULL)
			break;
		after = after->next;
		count++;
	}
	pre->next = before;
	tail->next = mNode;
	return myhead->next;
}

int main()
{
	ListNode* head = tailInsert(10);
	printList(head);
	ListNode* reversehead = reverseBetween(head,1,2);
	printList(reversehead);
}
