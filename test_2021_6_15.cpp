#define _CRT_SECURE_NO_WARNINGS 1

// ˳ʱ���ӡ����
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		// ����Ϊ�յ����
		if (!matrix.size())
		{
			return vector<int>();
		}
		// ���������������ĸ���λ������
		int up = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		vector<int> ret;
		while (1)
		{
			// 1��������������
			for (int i = left; i <= right; ++i)
			{
				ret.push_back(matrix[up][i]);
			}
			// 2��������������
			if (++up > down)
			{
				break;
			}
			for (int i = up; i <= down; ++i)
			{
				ret.push_back(matrix[i][right]);
			}
			// 3��������������
			if (--right < left)
			{
				break;
			}
			for (int i = right; i >= left; --i)
			{
				ret.push_back(matrix[down][i]);
			}
			// 4��������������
			if (--down < up)
			{
				break;
			}
			for (int i = down; i >= up; --i)
			{
				ret.push_back(matrix[i][left]);
			}
			if (++left > right)
			{
				break;
			}
		}
		return ret;
	}
};

// ����min������ջ
class MinStack {
	stack<int> s;
	stack<int> min_s;
public:
	/** initialize your data structure here. */
	MinStack()
	{}

	void push(int x)
	{
		// �ȸ���ͨջ��ջ��
		s.push(x);
		// ��Сջ����յĻ�Ҳ����ջ
		// ���յĻ���Ҫ�����Ԫ��С�ڵ�����Сջջ��Ԫ�زſ�����
		if (min_s.empty())
		{
			min_s.push(x);
		}
		else if (x <= min_s.top())
		{
			min_s.push(x);
		}
	}

	void pop()
	{
		// �����ͨջջ��Ԫ�ص�����Сջջ��Ԫ�أ���ô��СջҲ�ó�ջ
		if (s.top() == min_s.top())
		{
			min_s.pop();
		}
		s.pop();
	}

	int top()
	{
		return s.top();
	}

	int min()
	{
		return min_s.top();
	}
};

// ���������������
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		// ֻ��һ��Ԫ������Ĵ���
		if (nums.size() == 1)
		{
			return nums[0];
		}
		int sum = nums[0];    //��¼��ǰ����������
		int maxSum = nums[0]; //��¼��ʷ����������
		for (int i = 1; i < nums.size(); ++i)
		{
			// ���sum�Ǹ�����û���𵽴ٽ����ã��Ͱ�������Ϊ0
			sum = max(sum, 0);
			sum += nums[i];
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};
