#define _CRT_SECURE_NO_WARNINGS 1

// 前K个高频单词
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 1、统计单词的数量
		map<string, int> countMap;
		for (auto& e : words)
		{
			++countMap[e];
		}
		// 2、利用仿函数依据单词数量进行排序
		multimap<int, string, greater<int>> sortMap;
		for (auto& e : countMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}
		// 3、从排序好的mutimap中整理得到结果
		vector<string> ret;
		for (auto& e : sortMap)
		{
			if (k--)
			{
				ret.push_back(e.second);
			}
			else
			{
				break;
			}
		}
		return ret;
	}
};

// 树的子结构
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
	bool isSubStructure(TreeNode* A, TreeNode* B)
	{
		// 题目约定了空树不是任意一个树的子结构
		if (A == nullptr || B == nullptr)
		{
			return false;
		}
		// 每个节点都判断是否是子结构
		return Recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	// 逐个节点地判断是否是子树
	bool Recur(TreeNode* Anode, TreeNode* Bnode)
	{
		if (Bnode == nullptr)
		{
			return true;
		}
		if (Anode == nullptr || Anode->val != Bnode->val)
		{
			return false;
		}
		return Recur(Anode->left, Bnode->left) && Recur(Anode->right, Bnode->right);
	}
};

// 从上到下打印二叉树
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
	// 二叉树的层序遍历
	vector<int> levelOrder(TreeNode* root)
	{
		// 空树的话返回空数组
		if (!root)
		{
			return vector<int>();
		}
		vector<int> ret;
		// 根节点先入栈
		queue<TreeNode*> q;
		q.push(root);
		// 从队列中拿出头部数据，如果它还有左右孩子的话也让它们依次入栈
		while (!q.empty())
		{
			TreeNode* node = q.front();
			ret.push_back(node->val);
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
		return ret;
	}
};
