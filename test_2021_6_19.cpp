#define _CRT_SECURE_NO_WARNINGS 

// 1、0~n-1中缺失的数字
class Solution {
public:
	// o异或任何数的任何数
	// 相同的数异或在一起为0
	int missingNumber(vector<int>& nums)
	{
		int ret = 0;
		for (int i = 1; i < nums.size() + 1; ++i)
		{
			ret ^= i;
		}
		for (auto& e : nums)
		{
			ret ^= e;
		}
		return ret;
	}
};

// 2、和为s的两个数字
class Solution {
public:
	// 定义左右指针
	// 保证left<right
	// 如果两数之和大于target，则--right
	// 如果两数之和小于target，则++left
	// 等于target的话就是找到了
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			if (target - nums[right] == nums[left])
			{
				return vector<int>{nums[left], nums[right]};
			}
			else if (target - nums[right] < nums[left])
			{
				--right;
			}
			else
			{
				++left;
			}
		}
		return vector<int>();
	}
};

// 3、和为s的连续正数序列
class Solution {
public:
	// 方法一：遍历法
	vector<vector<int>> findContinuousSequence(int target)
	{
		vector<vector<int>> ret;
		// 因为至少是两个连续的数字，所以上界为target/2
		// 从1开始遍历每个数字
		for (int i = 1; i <= target / 2; ++i)
		{
			int sum = 0;
			vector<int> sub;
			// 从i开始往后累加
			for (int j = i;; ++j)
			{
				sum += j;
				if (sum == target)
				{
					for (int k = i; k <= j; ++k)
					{
						sub.push_back(k);
					}
					ret.push_back(sub);
				}
				else if (sum > target)// 如果sum大于target的话，那i就不是了，直接退出
				{
					break;
				}
			}
		}
		return ret;
	}
};

class Solution {
public:
	// 方法二：双指针
	vector<vector<int>> findContinuousSequence(int target)
	{
		int left = 1;
		int right = 2;
		vector<vector<int>> ret;
		while (left < right)
		{
			int sum = (left + right)*(right - left + 1) / 2;
			vector<int> sub;
			if (sum == target)
			{
				for (int i = left; i <= right; ++i)
				{
					sub.push_back(i);
				}
				++left;
				ret.push_back(sub);
			}
			else if (sum < target)
			{
				++right;
			}
			else
			{
				++left;
			}
		}
		return ret;
	}
};
