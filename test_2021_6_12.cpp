#define _CRT_SECURE_NO_WARNINGS 1

// ������̨������
class Solution {
public:
	int numWays(int n)
	{
		int a = 1;
		int b = 1;
		int c = 0;
		if (n == 0 || n == 1)
		{
			return 1;
		}
		for (int i = 2; i <= n; ++i)
		{
			c = ((a + b) % 1000000007);
			a = b;
			b = c;
		}
		return c;
	}
};

// ������ջʵ�ֶ���
class CQueue {
	stack<int> s1;
	stack<int> s2;
public:
	CQueue()
	{}

	// ����s1��ջ
	void appendTail(int value)
	{
		s1.push(value);
	}

	int deleteHead()
	{
		// 1�����������պ�s1�յ�s2���յ����
		if (!s2.empty())
		{
			int ret = s2.top();
			s2.pop();
			return ret;
		}
		// 2���������յ����
		if (s1.empty())
		{
			return -1;
		}
		// 3��s1���յ�s2�յ����
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		int ret = s2.top();
		s2.pop();
		return ret;
	}
};

// ��ת�������С����
class Solution {
public:
	int minArray(vector<int>& numbers)
	{
		// ��right��mid�±��ֵ�Ƚϣ�Ϊ������mid�±��ֵ������תǰ�����ǰ�벿�ֻ��Ǻ�벿��
		// ������left��mid�±��ֵ��Ƚϣ���Ϊ���ܱ�֤left�±���Զ�ں�벿�֣���right�±���Զ��ǰ�벿��
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (numbers[mid] > numbers[right])
			{
				left = mid + 1;
			}
			else if (numbers[mid] < numbers[right])
			{
				right = mid;
			}
			else
			{
				right -= 1;
			}
		}
		return numbers[left];
	}
};
