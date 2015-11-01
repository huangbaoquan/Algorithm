// author: bqhuang
// date: 2015/10/16

/***********************************************************************************
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
***********************************************************************************/

#include <iostream>
#include <queue>
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

vector<vector<int> > levelOrder(TreeNode* root) 
{
	vector<vector<int> > result;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
	}
	return result;
}




