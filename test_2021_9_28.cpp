#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树的最近公共祖先
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
	TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// 1、先排判断当前节点为空或者当前节点就是p或q的话，返回当前节点
		if (!root || root->val == p->val || root->val == q->val)
		{
			return root;
		}
		// 2、如果当前节点即不空也不是p、q的话，到它的左右子树去找
		TreeNode* leftTree = _lowestCommonAncestor(root->left, p, q);
		TreeNode* rightTree = _lowestCommonAncestor(root->right, p, q);
		// 3、左右子树查找完成后的三种情况
		//     a:都在它的左子树，直接返回左子树中找到的最近公共祖先
		//     b:都在它的右子树，直接返回右子树中找到的最近公共祖先
		//     c:左右子树个找到一个，说明该节点就是最近公共祖先
		if (leftTree && !rightTree)
		{
			return leftTree;
		}
		else if (!leftTree && rightTree)
		{
			return rightTree;
		}
		else if (leftTree && rightTree)
		{
			return root;
		}
		// 实际不会走到这里，为了满足函数的最终返回值才写的
		return nullptr;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		return _lowestCommonAncestor(root, p, q);
	}
};

// 二叉树的镜象
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
	TreeNode* _mirrorTree(TreeNode* root)
	{
		if (!root)
		{
			return nullptr;
		}
		swap(root->left, root->right);
		_mirrorTree(root->left);
		_mirrorTree(root->right);
		return root;
	}

public:
	TreeNode* mirrorTree(TreeNode* root)
	{
		return _mirrorTree(root);
	}
};

// 对称的二叉树
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
	bool _isSymmetric(TreeNode* subL, TreeNode* subR)
	{
		if (subL == nullptr && subR == nullptr)// 1、两个节点都为空也算对称
		{
			return true;
		}
		else if (subL == nullptr || subR == nullptr)// 2、其中一个为空，另一个不空，不对称
		{
			return false;
		}
		else if (subL->val != subR->val)// 3、两个节点都不空，但val不一样也不对称
		{
			return false;
		}
		// 4、两个节点都不空且val相等，再往下递归看它们的孩子是否对称
		return _isSymmetric(subL->left, subR->right) && _isSymmetric(subL->right, subR->left);
	}
public:
	bool isSymmetric(TreeNode* root)
	{
		return _isSymmetric(root, root);
	}
};