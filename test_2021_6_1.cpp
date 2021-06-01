#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool _isBalanced(TreeNode* root, int& i)
	{
		// 空树也算平衡二叉树
		if (!root)
		{
			++i;
			return true;
		}
		// 判断左子树是不是平衡二叉树
		int lefthigh = 0;
		if (!_isBalanced(root->left, lefthigh))
		{
			return false;
		}
		// 判断右子树是不是平衡二叉树
		int rightgigh = 0;
		if (!_isBalanced(root->right, rightgigh))
		{
			return false;
		}
		// 把当前树的高度返回
		i = max(lefthigh, rightgigh) + 1;
		// 判断当前树是否是平衡二叉树
		return abs(lefthigh - rightgigh) <= 1;
	}

	bool isBalanced(TreeNode* root)
	{
		int i = 0;
		return _isBalanced(root, i);
	}
};
