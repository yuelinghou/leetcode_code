#define _CRT_SECURE_NO_WARNINGS 1

// �˻����������
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

// ����������еĸ���
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
						cnt[i] = cnt[j];// ���ü���
					}
					else if (dp[j] + 1 == dp[i])
					{
						cnt[i] += cnt[j];// ���¼���
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

// ���������������
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums)
	{
		int sum = nums[0];
		int curMax = nums[0];
		int curMin = nums[0];
		int allMax = nums[0];
		int allMin = nums[0];
		// 1��������������������������
		for (size_t i = 1; i < nums.size(); ++i)
		{
			sum += nums[i];
			curMax = max(nums[i], curMax + nums[i]);
			allMax = max(allMax, curMax);
		}
		// 2������������������С�������
		// ѭ����ֹ�����ǡ�i < nums.size() - 1����ԭ��
		// ����������������Ϳ�Խ��ͷβ������ret = sum - allMin
		// allMinһ������������һ�����أ����Ԫ��һ������ret�еģ���Ȼ����һҲ����ͨ����
		for (size_t i = 1; i < nums.size() - 1; ++i)
		{
			curMin = min(nums[i], curMin + nums[i]);
			allMin = min(allMin, curMin);
		}
		// 3�������м��������������ǹᴩͷβ�������������
		return max(allMax, sum == allMin ? sum : sum - allMin);
	}
};