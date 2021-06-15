#define _CRT_SECURE_NO_WARNINGS 1

// ��β��ͷ��ӡ����
// ����һ��
// ���������������val�ŵ�ջ��
// �����γ�ջ������������
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> reversePrint(ListNode* head)
	{
		vector<int> ret;
		stack<int> s;
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty())
		{
			ret.push_back(s.top());
			s.pop();
		}
		return ret;
	}
};

// ������
// �ݹ�
class Solution {
public:
	vector<int> reversePrint(ListNode* head)
	{
		if (!head)
		{
			return vector<int>();
		}
		vector ret = reversePrint(head->next);
		ret.push_back(head->val);
		return ret;
	}
};

// �滻�ո�
class Solution {
public:
	string replaceSpace(string s)
	{
		string ret;
		for (auto& e : s)
		{
			if (e == ' ')
			{
				ret += "%20";
			}
			else
			{
				ret += e;
			}
		}
		return ret;
	}
};

// 쳲���������
// ����һ���ݹ鷨��
class Solution {
public:
	int fib(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return (fib(n - 1) + fib(n - 2)) % 1000000007;
		}
	}
};

// �����������䷨��
// ����һ��쳲���������ǰ������ǰ������ֵ
class Solution {
public:
	int fib(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		int a = 0;
		int b = 1;
		int c = 0;
		for (int i = 2; i <= n; ++i)
		{
			c = (a + b) % 1000000007;
			a = b;
			b = c;
		}
		return c;
	}
};



