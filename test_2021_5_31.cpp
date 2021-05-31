#define _CRT_SECURE_NO_WARNINGS 1

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
	bool isUnivalTree(TreeNode* root)
	{
		// 根节点为空情况的处理
		if (!root)
		{
			return true;
		}
		// 有左孩子，并且左孩子不等于根的val就不是单值二叉树
		if (root->left&&root->left->val != root->val)
		{
			return false;
		}
		// 有有孩子，并且有孩子的值不等于根就不是单值二叉树
		if (root->right&&root->right->val != root->val)
		{
			return false;
		}
		// 利用等于的传递性继续递归他的子树
		return isUnivalTree(root->left) && isUnivalTree(root->right);
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root)
	{
		// 根节点为空情况的处理
		if (!root)
		{
			return 0;
		}
		// 取子树深度大的那个，加上自身的1，就是最大高度
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root)
	{
		// 根节点为空，就返回nullptr
		if (!root)
		{
			return nullptr;
		}
		// 翻转两个孩子
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// 递归翻转两个子树
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

class Solution {
public:
	bool _isSymmetric(TreeNode* leftTree, TreeNode* rightTree)
	{
		// 两个子树都空，算对称
		if (!leftTree && !rightTree)
		{
			return true;
		}
		// 一个空，另外一个不空，不对称
		if (!leftTree || !rightTree)
		{
			return false;
		}
		// 都不空但是他们的值不一样，也不算对称
		if (leftTree->val != rightTree->val)
		{
			return false;
		}
		// 继续迭代他们对应左右位置的数
		return _isSymmetric(leftTree->left, rightTree->right)
			&& _isSymmetric(leftTree->right, rightTree->left);
	}

	bool isSymmetric(TreeNode* root)
	{
		// 1、空树的话，也算对称
		if (!root)
		{
			return true;
		}
		// 2、非空树，判断两个子树是否对称
		return _isSymmetric(root->left, root->right);
	}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		// 根都为空就相同
		if (!p && !q)
		{
			return true;
		}
		// 其中一个为空，了一个不为空就不相同
		if (!p || !q)
		{
			return false;
		}
		// 都不空的话，val不等也就不相同
		if (p->val != q->val)
		{
			return false;
		}
		// 继续递归它们的左子树和右子树
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

class Solution {
public:
	void _preorderTraversal(TreeNode* root, vector<int>& v)
	{
		// 空节点直接退出
		if (!root)
		{
			return;
		}
		// 非空根节点存入数组
		v.push_back(root->val);
		// 继续遍历感觉的左右子树
		_preorderTraversal(root->left, v);
		_preorderTraversal(root->right, v);
	}

	vector<int> preorderTraversal(TreeNode* root)
	{
		// 创建int类型的vector，作为最后返回的结果
		vector<int> ret;
		// 空树的话字节返回空vector
		if (!root)
		{
			return ret;
		}
		// 非空树前序遍历
		_preorderTraversal(root, ret);
		return ret;
	}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		// 根都为空就相同
		if (!p && !q)
		{
			return true;
		}
		// 其中一个为空，了一个不为空就不相同
		if (!p || !q)
		{
			return false;
		}
		// 都不空的话，val不等也就不相同
		if (p->val != q->val)
		{
			return false;
		}
		// 继续递归它们的左子树和右子树
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}

	bool isSubtree(TreeNode* root, TreeNode* subRoot)
	{
		// 后面递归遇到空节点时的处理
		if (!root)
		{
			return false;
		}
		if (isSameTree(root, subRoot))
		{
			return true;
		}
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
};

class Solution {
public:
	void _inorderTraversal(TreeNode* root, vector<int>& v)
	{
		if (!root)
		{
			return;
		}
		_inorderTraversal(root->left, v);
		v.push_back(root->val);
		_inorderTraversal(root->right, v);
	}

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		if (!root)
		{
			return ret;
		}
		_inorderTraversal(root, ret);
		return ret;
	}
};

class Solution {
public:
	void _postorderTraversal(TreeNode* root, vector<int>& v)
	{
		if (!root)
		{
			return;
		}
		_postorderTraversal(root->left, v);
		_postorderTraversal(root->right, v);
		v.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		if (!root)
		{
			return ret;
		}
		_postorderTraversal(root, ret);
		return ret;
	}
};
