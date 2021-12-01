#define _CRT_SECURE_NO_WARNINGS 1

// 乘积最大子数组
class Solution {
public:
	int maxProduct(vector<int>& nums)
	{
		int ret = nums[0];
		int curMax = nums[0];
		int curMin = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			int mx = curMax;
			int mn = curMin;
			curMax = max(nums[i], max(nums[i] * mx, nums[i] * mn));
			curMin = min(nums[i], min(nums[i] * mx, nums[i] * mn));
			ret = max(curMax, ret);
		}
		return ret;
	}
};

// 最长递增子序列的个数
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums)
	{
		int ret = 1;
		int maxLen = 1;
		vector<int> dp(nums.size(), 1);
		vector<int> cnt(nums.size(), 1);
		for (size_t i = 1; i < nums.size(); ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					if (dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
						cnt[i] = cnt[j];// 重置计数
					}
					else if (dp[j] + 1 == dp[i])
					{
						cnt[i] += cnt[j];// 更新计数
					}
				}
			}
			if (dp[i] > maxLen)
			{
				maxLen = dp[i];
				ret = cnt[i];
			}
			else if (dp[i] == maxLen)
			{
				ret += cnt[i];
			}
		}
		return ret;
	}
};

// 环形子数组的最大和
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums)
	{
		int sum = nums[0];
		int curMax = nums[0];
		int curMin = nums[0];
		int allMax = nums[0];
		int allMin = nums[0];
		// 1、正常计算该数组的最大子数组和
		for (size_t i = 1; i < nums.size(); ++i)
		{
			sum += nums[i];
			curMax = max(nums[i], curMax + nums[i]);
			allMax = max(allMax, curMax);
		}
		// 2、正常计算该数组的最小子数组和
		// 循环终止条件是“i < nums.size() - 1”的原因：
		// 如果最大连续子数组和跨越了头尾，根据ret = sum - allMin
		// allMin一定不会包括最后一个因素，这个元素一定是在ret中的，当然不减一也可以通过。
		for (size_t i = 1; i < nums.size() - 1; ++i)
		{
			curMin = min(nums[i], curMin + nums[i]);
			allMin = min(allMin, curMin);
		}
		// 3、看是中间的连续子数组大还是贯穿头尾的连续子数组大
		return max(allMax, sum == allMin ? sum : sum - allMin);
	}
};