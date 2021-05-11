#define _CRT_SECURE_NO_WARNINGS 

// ������Ʊ�����ʱ��
class Solution {
public:
	// ̰���㷨ֱ�����������
	// ͬһ�������������ǵ�����һ��ʲô��û��
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

// �����ظ�Ԫ��
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

// ֻ����һ�ε�����
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
