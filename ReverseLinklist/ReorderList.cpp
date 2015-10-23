//author : bqhuang
//date   : 2015/10/23

/********************************************************************************** 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 
 * 解答：
 * 第一步，找到链表的中间节点(使用快慢指针)
 * 第二步，反转中点节点后面的节点(采用三个指针法)
 * 第三步，把中间节点之前的链表和反转后的链表合并起来
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
 * reverse listnode
 */
ListNode* reverse(ListNode* head)
{
	if(head == NULL)
		return NULL;
	ListNode* pre = NULL; 
	ListNode* node = head;
	ListNode* next = node->next;
	while(node)
	{
		node->next = pre;
		pre = node;
		node = next;
		if(node == NULL)
			return pre;
		next = next->next;
	}
	return NULL;
}

ListNode* Reorder(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast)
	{
		fast = fast->next;
		if(fast == NULL)
			break;
		fast = fast->next;
		if(fast == NULL)
			break;
		slow = slow->next;
		if(slow == NULL)
			return NULL;
	}
	// reverse the second list
	ListNode* firstlist= head;
	ListNode* secondlist = reverse(slow);
	// merge two list
	while(secondlist != NULL && firstlist != NULL &&secondlist != firstlist)
	{
		ListNode* temp = secondlist->next;
		secondlist->next = firstlist->next;
		firstlist->next = secondlist;
		firstlist = secondlist->next;
		secondlist = temp;
	}
	return head;
}

int main()
{
	ListNode* head = tailInsert(10);
	printList(head);
	ListNode* reversehead = Reorder(head);
	printList(reversehead);
}
