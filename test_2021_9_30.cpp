#define _CRT_SECURE_NO_WARNINGS 1

// 平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
	bool _isBalanced(TreeNode* root, int& high)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHigh = 0;
		int rightHigh = 0;
		bool bLeft = _isBalanced(root->left, leftHigh);
		bool bRight = _isBalanced(root->right, rightHigh);
		high = max(leftHigh, rightHigh) + 1;// 更新给父亲节点该树的高度
		return bLeft && bRight && abs(leftHigh - rightHigh) < 2;// 返回给父亲节点，该树是否是平衡树
	}

public:
	bool isBalanced(TreeNode* root)
	{
		// 1、根节点为空也算平衡树
		if (root == nullptr)
		{
			return true;
		}
		// 2、根节点不为空，后序遍历二叉树，并记录左右子树的高度
		int leftHigh = 0;
		int rightHigh = 0;
		return _isBalanced(root->left, leftHigh)
			&& _isBalanced(root->right, rightHigh)
			&& abs(leftHigh - rightHigh) < 2;
	}
};
