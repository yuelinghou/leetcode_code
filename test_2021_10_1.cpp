#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树的深度
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxDepth(TreeNode* root)
	{
		// 递归结束条件：空树算高度为0
		if (root == nullptr)
		{
			return 0;
		}
		// 不空的话，仅自己就有一个高度，再加上左右子树中更高的那棵树的高度就是这棵树的高度
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
