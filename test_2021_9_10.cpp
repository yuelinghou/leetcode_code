#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树中和为某一值的路径
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	vector<vector<int>> ret;
	vector<int> path;

public:
	void Dfs(TreeNode* root, int target)
	{
		// 空树的话直接返回
		if (!root)
		{
			return;
		}
		// 不空的话先把该节点的值加入到path里，对应target减去这个值
		path.push_back(root->val);
		target -= root->val;
		if (!root->left && !root->right && target == 0)
		{
			ret.push_back(path);
		}
		// 继续往左边路径遍历
		Dfs(root->left, target);
		// 继续往右边路径遍历
		Dfs(root->right, target);
		// 左右都遍历结束了，删除最开始假如path里的值
		path.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int target)
	{
		// 深度优先遍历所有路径
		Dfs(root, target);
		return ret;
	}
};

// 从上到下打印二叉树II
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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		if (!root)
		{
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> path;
			// 逐层取、逐层放
			for (int i = q.size(); i > 0; --i)
			{
				TreeNode* node = q.front();
				q.pop();
				path.push_back(node->val);
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
			ret.push_back(path);
		}

		return ret;
	}
};

// 从上到下打印二叉树III
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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		if (!root)
		{
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);
		int falg = 0;
		// 和II思路一样：逐层取，逐层插，都是最后把该层数组插入到ret前，判断是否要翻转来实现最终的Z字形打印
		while (!q.empty())
		{
			vector<int> path;
			for (int i = q.size(); i > 0; --i)
			{
				TreeNode* node = q.front();
				path.push_back(node->val);
				q.pop();
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
			if (falg % 2 != 0)
			{
				reverse(path.begin(), path.end());
			}
			++falg;
			ret.push_back(path);
		}
		return ret;
	}
};