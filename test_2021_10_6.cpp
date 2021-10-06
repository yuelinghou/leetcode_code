#define _CRT_SECURE_NO_WARNINGS 1

// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
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
		// ��һ��Ӹ��ڵ㿪ʼ
		Node* cur = root;
		// ��ǰ�ᱣ֤�������һ�ŵ�Ҷ�ӽڵ㣬����ѭ���ڵ�ÿ���ڵ㶼����������
		while (cur->left)
		{
			// ��¼��һ����ʼλ�ýڵ�
			Node* nextStart = cur->left;
			// �����ò�ڵ�
			while (cur)
			{
				// 1�������ӵ�ǰ�ڵ�����Һ���
				cur->left->next = cur->right;
				// 2�����ӵ�ǰ�ڵ��Һ��Ӻ���һ���ڵ������
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

// ���ÿһ���ڵ����һ���Ҳ�ڵ�ָ��II
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
		// ��ǰ�ᱣ֤��ǰ���нڵ�
		while (start)
		{
			Node* last = nullptr;// ��¼��ǰ�ڵ���ߵĽڵ�
			Node* nextStart = nullptr;// ��¼��һ����ʼλ�ýڵ�
			// ��ǰ����Ǳ�����ǰ��Ľڵ㣬ά������һ������ӵĹ�ϵ
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
			start = nextStart;// ��������һ��
		}
		return root;
	}
};