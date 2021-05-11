#define _CRT_SECURE_NO_WARNINGS 

// 买卖股票的最佳时机
class Solution {
public:
	// 贪心算法直接求最大利润
	// 同一天卖出和买入是等于那一天什么都没干
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() == 0 || prices.size() == 1)
		{
			return 0;
		}
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i - 1] < prices[i])
			{
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
};

// 存在重复元素
class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (nums.size() == 0 || nums.size() == 1)
		{
			return false;
		}
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i - 1] == nums[i])
			{
				return false;
			}
		}
		return true;
	}
};

// 只出现一次的数字
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for (auto e : nums)
		{
			ret ^= e;
		}
		return ret;
	}
};
