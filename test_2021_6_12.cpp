#define _CRT_SECURE_NO_WARNINGS 1

// 青蛙跳台阶问题
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

// 用两个栈实现队列
class CQueue {
	stack<int> s1;
	stack<int> s2;
public:
	CQueue()
	{}

	// 就往s1入栈
	void appendTail(int value)
	{
		s1.push(value);
	}

	int deleteHead()
	{
		// 1、两个都不空和s1空但s2不空的情况
		if (!s2.empty())
		{
			int ret = s2.top();
			s2.pop();
			return ret;
		}
		// 2、两个都空的情况
		if (s1.empty())
		{
			return -1;
		}
		// 3、s1不空但s2空的情况
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

// 旋转数组的最小数字
class Solution {
public:
	int minArray(vector<int>& numbers)
	{
		// 拿right和mid下标的值比较，为了区别mid下标的值是在旋转前数组的前半部分还是后半部分
		// 不能拿left和mid下标的值相比较，因为不能保证left下标永远在后半部分，而right下标永远在前半部分
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
