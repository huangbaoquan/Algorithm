//author : bqhuang
//date   : 2015/10/24

/********************************************************************************** 
* Given a linked list, 
* remove the nth node from the end of list and return its head.
* For example,
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, 
* the linked list becomes 1->2->3->5.

* Note:
* Given n will always be valid.
* Try to do this in one pass. 
解答：采用快慢指针思路.
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
	return L->next;
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* myhead = new ListNode(0);
	myhead->next = head;
	ListNode* fast = myhead;
	ListNode* slow = myhead;
	while(n--)
	{
		fast = fast->next;
	}
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	ListNode* temp = slow->next;
	slow->next = temp->next;
	delete temp;
	return myhead->next;
}

int main()
{
	int n;
	scanf("%d",&n);
	ListNode* head = tailInsert(3);
	printList(head);

	printf("remove Nth:\n");
	printList(removeNthFromEnd(head,n));
}
