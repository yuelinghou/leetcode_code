#define _CRT_SECURE_NO_WARNINGS 1

// 填充每个节点的下一个右侧节点指针
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root)
	{
		if (root == nullptr)
		{
			return root;
		}
		// 第一层从根节点开始
		Node* cur = root;
		// 大前提保证不是最后一排的叶子节点，这样循环内的每个节点都有两个孩子
		while (cur->left)
		{
			// 记录下一层起始位置节点
			Node* nextStart = cur->left;
			// 遍历该层节点
			while (cur)
			{
				// 1、先连接当前节点的左右孩子
				cur->left->next = cur->right;
				// 2、连接当前节点右孩子和下一个节点的左孩子
				Node* nextNode = cur->next;
				if (nextNode)
				{
					cur->right->next = nextNode->left;
				}
				cur = nextNode;
			}
			cur = nextStart;
		}
		return root;
	}
};

// 填充每一个节点的下一个右侧节点指针II
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
private:
	void _connect(Node*& last, Node*& cur, Node*& nextStart)
	{
		if (last)
		{
			last->next = cur;
		}
		if (!nextStart)
		{
			nextStart = cur;
		}
		last = cur;
	}

public:
	Node* connect(Node* root)
	{
		Node* start = root;
		// 大前提保证当前层有节点
		while (start)
		{
			Node* last = nullptr;// 记录当前节点左边的节点
			Node* nextStart = nullptr;// 记录下一层起始位置节点
			// 次前提就是遍历当前层的节点，维护好下一层的连接的关系
			for (Node* cur = start; cur != nullptr; cur = cur->next)
			{
				if (cur->left)
				{
					_connect(last, cur->left, nextStart);
				}
				if (cur->right)
				{
					_connect(last, cur->right, nextStart);
				}
			}
			start = nextStart;// 迭代到下一层
		}
		return root;
	}
};