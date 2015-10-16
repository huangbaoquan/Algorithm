// author: bqhuang
// date: 2015/10/15

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

思路：root是指向当前需要访问的节点，初始指向根节点。
如果root不为空，就把root的左孩子入栈。
如果root为空，输出root并把root右孩子入栈。
*************************************************************************************/

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
void Inorder(TreeNode* T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	printf("%d ",T->val);
	Inorder(T->right);
}
/*
 * traversal Inorder Tree
 */
vector<int> InorderTraversal(TreeNode* root)
{
	vector<int>	result;
	if(root != NULL)
	{
		stack<TreeNode*> S;
		TreeNode* temp = root;
		while(temp || !S.empty())
		{
			if(temp != NULL)
			{
				S.push(temp);
				temp = temp->left;
			}
			else
			{
				temp = S.top();
				printf("%d ",temp->val);
				S.pop();
				temp = temp->right;
			}
		}
	}
	return result;
}

int main()
{
	TreeNode* treeNode;
	TreeNode* T = CreateTree(treeNode);
	Inorder(T);
	printf("\n");
	InorderTraversal(T);
}
