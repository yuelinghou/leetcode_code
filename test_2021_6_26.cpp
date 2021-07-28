#define _CRT_SECURE_NO_WARNINGS 1

// 剪绳子II
class Solution {
public:
	int cuttingRope(int n)
	{
		if (n < 4)
		{
			return n - 1;
		}
		long ret = 1;
		while (n > 4)
		{
			ret = (ret * 3 % 1000000007);
			n -= 3;
		}
		ret = ret * n % 1000000007;
		return (int)ret;
	}
};

// 反转字符串II
class Solution {
public:
	string reverseStr(string s, int k)
	{
		int begin = 0;
		int n = s.size();
		// 至少左边界存在，才可以反转
		while (begin < n)
		{
			int end = min(begin + k - 1, n - 1);// 拿到反转区间的右边界
			reverse(s.begin() + begin, s.begin() + end + 1);
			begin += 2 * k;// 更新左边界
		}
		return s;
	}
};

// 创建二叉树
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
	// prevI要传引用，他代表子树的更节点，在递归创建左好左子树后，要更新它的值来创建右子树
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prevI, int inBegin, int inEnd)
	{
		// 没有区间也就没有节点
		if (inBegin > inEnd)
		{
			return nullptr;
		}
		// 创建根节点
		TreeNode* root = new TreeNode(preorder[prevI]);
		// 在中序中找到根的val
		int inI = inBegin;
		while (inorder[inI] != preorder[prevI])
		{
			++inI;
		}
		// 创建左子树
		if (inBegin <= inI - 1)
		{
			root->left = _buildTree(preorder, inorder, ++prevI, inBegin, inI - 1);
		}
		else
		{
			root->left = nullptr;
		}
		// 创建右子树
		if (inI + 1 <= inEnd)
		{
			root->right = _buildTree(preorder, inorder, ++prevI, inI + 1, inEnd);
		}
		else
		{
			root->right = nullptr;
		}
		// 返回根
		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int prevI = 0;// 根节点的val
		return _buildTree(preorder, inorder, prevI, 0, inorder.size() - 1);
	}
};
