#define _CRT_SECURE_NO_WARNINGS 1

// ǰK����Ƶ����
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 1��ͳ�Ƶ��ʵ�����
		map<string, int> countMap;
		for (auto& e : words)
		{
			++countMap[e];
		}
		// 2�����÷º������ݵ���������������
		multimap<int, string, greater<int>> sortMap;
		for (auto& e : countMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}
		// 3��������õ�mutimap������õ����
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

// �����ӽṹ
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
		// ��ĿԼ���˿�����������һ�������ӽṹ
		if (A == nullptr || B == nullptr)
		{
			return false;
		}
		// ÿ���ڵ㶼�ж��Ƿ����ӽṹ
		return Recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	// ����ڵ���ж��Ƿ�������
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

// ���ϵ��´�ӡ������
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
	// �������Ĳ������
	vector<int> levelOrder(TreeNode* root)
	{
		// �����Ļ����ؿ�����
		if (!root)
		{
			return vector<int>();
		}
		vector<int> ret;
		// ���ڵ�����ջ
		queue<TreeNode*> q;
		q.push(root);
		// �Ӷ������ó�ͷ�����ݣ�������������Һ��ӵĻ�Ҳ������������ջ
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
