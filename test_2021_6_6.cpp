#define _CRT_SECURE_NO_WARNINGS 1

// 第一个错误的版本
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n)
	{
		int left = 1;
		int right = n;
		// 当left==right时二者的值就是第一个错误版本
		while (left < right)
		{
			// 为了防止整型溢出，算mid时要做特殊处理
			int mid = left + (right - left) / 2;
			// ifmid是错误版本，那第一个错误版本只可能在left和mid之间（包括mid）
			if (isBadVersion(mid))
			{
				right = mid;
			}
			// 如果mid不是错误版本，那么第一个错误版本只可能是在mid+1到right之间
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

// 爬楼梯
/*
// 循环法
class Solution {
public:
	int climbStairs(int n)
	{
		int n1=0;
		int n2=0;
		int n3=1;
		for(int i=1;i<=n;++i)
		{
			n1=n2;
			n2=n3;
			n3=n1+n2;
		}
		return n3;
	}
};
*/

// 递归法(超时)
class Solution {
public:
	int climbStairs(int n)
	{
		if (n == 0)
		{
			return 1;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return climbStairs(n - 1) + climbStairs(n - 2);
		}
	}
};

// 买卖股票的最佳时机
class Solution {
public:
	// 最开始利润为0，最小价格为数组第一个数，贪心算法遍历一遍得到最大的利润
	int maxProfit(vector<int>& prices)
	{
		int max_profit = 0;
		int min_price = prices[0];
		for (int i = 1; i < prices.size(); ++i)
		{
			min_price = min(min_price, prices[i]);
			max_profit = max(max_profit, prices[i] - min_price);
		}
		return max_profit;
	}
};