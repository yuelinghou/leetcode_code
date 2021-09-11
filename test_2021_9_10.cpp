#define _CRT_SECURE_NO_WARNINGS 1

// �������к�Ϊĳһֵ��·��
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
		// �����Ļ�ֱ�ӷ���
		if (!root)
		{
			return;
		}
		// ���յĻ��ȰѸýڵ��ֵ���뵽path���Ӧtarget��ȥ���ֵ
		path.push_back(root->val);
		target -= root->val;
		if (!root->left && !root->right && target == 0)
		{
			ret.push_back(path);
		}
		// ���������·������
		Dfs(root->left, target);
		// �������ұ�·������
		Dfs(root->right, target);
		// ���Ҷ����������ˣ�ɾ���ʼ����path���ֵ
		path.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int target)
	{
		// ������ȱ�������·��
		Dfs(root, target);
		return ret;
	}
};

// ���ϵ��´�ӡ������II
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
			// ���ȡ������
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

// ���ϵ��´�ӡ������III
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
		// ��II˼·һ�������ȡ�����壬�������Ѹò�������뵽retǰ���ж��Ƿ�Ҫ��ת��ʵ�����յ�Z���δ�ӡ
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