#define _CRT_SECURE_NO_WARNINGS 1

// 从尾到头打印链表
// 方法一：
// 遍历链表，把链表的val放到栈里
// 在依次出栈并放入数组里
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

// 方法二
// 递归
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

// 替换空格
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

// 斐波那契数列
// 方法一（递归法）
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

// 方法二（记忆法）
// 算下一个斐波那契数列前，保留前两个的值
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



