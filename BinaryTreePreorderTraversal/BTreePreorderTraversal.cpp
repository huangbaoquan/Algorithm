// author: bqhuang
// date: 2015/10/14

/***********************************************************************************
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*************************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
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
void preOrder(TreeNode* T)
{
	if(T == NULL)
	{
		return;
	}
	printf("%d ",T->val);
	preOrder(T->left);
	preOrder(T->right);
}

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	stack<int> S;
	return result;
}

int main()
{
	TreeNode* treeNode;
	TreeNode* T = CreateTree(treeNode);
	preOrder(T);
}
