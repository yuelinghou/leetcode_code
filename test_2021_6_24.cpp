#define _CRT_SECURE_NO_WARNINGS 1

// 二进制中1的个数
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count = 0;
		for (int i = 0; i <= 31; ++i)
		{
			if (n&(1 << i))
			{
				++count;
			}
		}
		return count;
	}
};

// 不用加减乘除左加法
class Solution {
public:
	int add(int a, int b)
	{
		// 进位数为0时，结束循环
		while (b)
		{
			// 得到二者和的无进位的结果
			int notCarry = a ^ b;
			// 得到进位数*10的结果
			b = ((unsigned int)(a&b)) * 2;
			a = notCarry;
		}
		return a;
	}
};

// 二维数组中的查找
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
	{
		if (matrix.size() == 0)
		{
			return  false;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		int j = col - 1;
		while (i < row&&j >= 0)
		{
			if (matrix[i][j] == target)
			{
				return true;
			}
			else if (matrix[i][j] < target)
			{
				++i;
			}
			else if (matrix[i][j] > target)
			{
				--j;
			}
		}
		return false;
	}
};
