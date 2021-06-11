#define _CRT_SECURE_NO_WARNINGS 1

// 罗马数字转整数
class Solution
{
public:
	int romanToInt(string s)
	{
		int sum = 0;
		// 先把第一个数字取出来
		int prev_num = GetNum(s[0]);
		// 从第二个数字开始，每次与前一个数字比较
		// 前一个数字小于后一个数字就是减
		// 前一个数字大于等于后一个数字就是加
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
	// 取出罗马数字对应的阿拉伯数字
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

// 位1的个数
/*
// 方法一：1左移
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count=0;
		// 用1逐次左移去&上n这个数的每一位
		// 如果非0那么这位就不是1；
		// 为0这位就是1
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
// 方法二：n右移
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

// 方法三：BK法
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count=0;
		while(n)
		{
			++count;
			// 每进行一次这个操作，n从右往左依次少一个1
			n=n&(n-1);
		}
		return count;
	}
};

// 汉明距离
class Solution {
public:
	int hammingDistance(int x, int y)
	{
		// ^运算
		// 对应的位相同为0相异为1
		return hammingWeight(x^y);
	}

private:
	int hammingWeight(uint32_t n)
	{
		int count = 0;
		while (n)
		{
			++count;
			// 每进行一次这个操作，n从右往左依次少一个1
			n = n & (n - 1);
		}
		return count;
	}
};
