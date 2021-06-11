#define _CRT_SECURE_NO_WARNINGS 1

// ��������ת����
class Solution
{
public:
	int romanToInt(string s)
	{
		int sum = 0;
		// �Ȱѵ�һ������ȡ����
		int prev_num = GetNum(s[0]);
		// �ӵڶ������ֿ�ʼ��ÿ����ǰһ�����ֱȽ�
		// ǰһ������С�ں�һ�����־��Ǽ�
		// ǰһ�����ִ��ڵ��ں�һ�����־��Ǽ�
		for (int i = 1; i < s.size(); ++i)
		{
			int cur_num = GetNum(s[i]);
			if (prev_num < cur_num)
			{
				sum -= prev_num;
			}
			else
			{
				sum += prev_num;
			}
			prev_num = cur_num;
		}
		return sum += prev_num;
	}

private:
	// ȡ���������ֶ�Ӧ�İ���������
	int GetNum(char ch)
	{
		switch (ch)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};

// λ1�ĸ���
/*
// ����һ��1����
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count=0;
		// ��1�������ȥ&��n�������ÿһλ
		// �����0��ô��λ�Ͳ���1��
		// Ϊ0��λ����1
		for(int i=0;i<32;++i)
		{
			if(n&(1<<i))
			{
				++count;
			}
		}
		return count;
	}
};
*/

/*
// ��������n����
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count=0;
		for(int i=0;i<32;++i)
		{
			if((n>>i)&1)
			{
				++count;
			}
		}
		return count;
	}
};
*/

// ��������BK��
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count=0;
		while(n)
		{
			++count;
			// ÿ����һ�����������n��������������һ��1
			n=n&(n-1);
		}
		return count;
	}
};

// ��������
class Solution {
public:
	int hammingDistance(int x, int y)
	{
		// ^����
		// ��Ӧ��λ��ͬΪ0����Ϊ1
		return hammingWeight(x^y);
	}

private:
	int hammingWeight(uint32_t n)
	{
		int count = 0;
		while (n)
		{
			++count;
			// ÿ����һ�����������n��������������һ��1
			n = n & (n - 1);
		}
		return count;
	}
};
