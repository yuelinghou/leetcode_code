#define _CRT_SECURE_NO_WARNINGS 1

// ��������1�ĸ���
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

// ���üӼ��˳���ӷ�
class Solution {
public:
	int add(int a, int b)
	{
		// ��λ��Ϊ0ʱ������ѭ��
		while (b)
		{
			// �õ����ߺ͵��޽�λ�Ľ��
			int notCarry = a ^ b;
			// �õ���λ��*10�Ľ��
			b = ((unsigned int)(a&b)) * 2;
			a = notCarry;
		}
		return a;
	}
};

// ��ά�����еĲ���
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
