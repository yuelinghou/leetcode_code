#define _CRT_SECURE_NO_WARNINGS 1

// 顺时针打印矩阵
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		// 矩阵为空的情况
		if (!matrix.size())
		{
			return vector<int>();
		}
		// 先设置上下左右四个方位的坐标
		int up = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		vector<int> ret;
		while (1)
		{
			// 1、从左上往右走
			for (int i = left; i <= right; ++i)
			{
				ret.push_back(matrix[up][i]);
			}
			// 2、从右上往下走
			if (++up > down)
			{
				break;
			}
			for (int i = up; i <= down; ++i)
			{
				ret.push_back(matrix[i][right]);
			}
			// 3、从右下往左走
			if (--right < left)
			{
				break;
			}
			for (int i = right; i >= left; --i)
			{
				ret.push_back(matrix[down][i]);
			}
			// 4、从左下往上走
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

// 包含min函数的栈
class MinStack {
	stack<int> s;
	stack<int> min_s;
public:
	/** initialize your data structure here. */
	MinStack()
	{}

	void push(int x)
	{
		// 先给普通栈入栈了
		s.push(x);
		// 最小栈如果空的话也给入栈
		// 不空的话，要满足该元素小于等于最小栈栈顶元素才可以入
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
		// 如果普通栈栈顶元素等于最小栈栈顶元素，那么最小栈也得出栈
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

// 连续子数组的最大和
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		// 只有一个元素情况的处理
		if (nums.size() == 1)
		{
			return nums[0];
		}
		int sum = nums[0];    //记录当前子数组最大和
		int maxSum = nums[0]; //记录历史最大子数组和
		for (int i = 1; i < nums.size(); ++i)
		{
			// 如果sum是负数，没有起到促进作用，就把他更新为0
			sum = max(sum, 0);
			sum += nums[i];
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};
