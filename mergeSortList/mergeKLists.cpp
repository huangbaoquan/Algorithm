// author : bqhuang
// date   : 2015/10/31


/***********************************************************************************
 * Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 * 解答：使用归并排序的思想，把vector里的链表两两合并，
 * 直到只剩下一个链表就是最终排序的结果。
 * 在vector合并链表操作时用到了一个index控制变量是用来计数每一趟合并后剩下链表个数。
************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	ListNode* Node;
	if(l1->val > l2->val)
	{
		Node = l2;
		Node->next = mergeTwoLists(l1,l2->next);
	}
	else
	{
		Node = l1;
		Node->next = mergeTwoLists(l1->next,l2);
	}
	return Node;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	int len  = lists.size();
	if(lists.size() < 1)
		return NULL;
	while(len > 1)
	{
		int index = (len + 1) / 2;
		for(int i=0;i<len/2;i++)
		{
			lists[i] = mergeTwoLists(lists[i],lists[i + index]);
		}
		len = index;
	}
	return lists[0];
}
