// author: bqhuang
// date: 2015/10/16

/***********************************************************************************
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
***********************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * Create Tree By Recursive
 */
TreeNode* CreateTree(TreeNode* T)
{
	int data;
	scanf("%d",&data);
	if(data == 0)
	{
		T = NULL;
		return T;
	}
	T = (TreeNode*)malloc(sizeof(TreeNode));	
	T->val = data;
	T->left = CreateTree(T->left);
	T->right = CreateTree(T->right);
	return T;
}

/*
 * tranversal Tree By Recursive
 */
void Post(TreeNode* T)
{
	if(T == NULL)
	{
		return;
	}
	Post(T->left);
	Post(T->right);
	printf("%d ",T->val);
}
/*
 * 后序遍历：left->right->root,而在先序遍历的非递归代码，
 * 先访问当前节点，然后访问左子树，然后右子树。
 * 然后root->right->left，倒过来就是后序遍历顺序，所以用两个栈可以实现后序遍历。
 */
vector<int> postorderTraversal(TreeNode* root) 
{
	vector<int> result;
	stack<TreeNode*> stk1,stk2;
	if(root != NULL)
	{
		stk1.push(root);
		while(!stk1.empty())
		{
			TreeNode* p = stk1.top();
			stk1.pop();
			stk2.push(p);
			if(p->right)
				stk1.push(p->right);
			if(p->left)
				stk1.push(p->left);
		}
		while(!stk2.empty())
		{
			TreeNode* node = stk2.top();
			printf("%d ",node->val);
			result.push_back(node->val);
			stk2.pop();
		}
	}
	return result;
}

int main()
{	
	TreeNode* treeNode;
	TreeNode* T = CreateTree(treeNode);
	Post(T);
	printf("\n");
	postorderTraversal(T);
}
