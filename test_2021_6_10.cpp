#define _CRT_SECURE_NO_WARNINGS 1

// 缺失数字
class Solution {
public:
	int missingNumber(vector<int>& nums)
	{
		// 0和任何数异或都为0
		// 相同的数异或在一起为0
		int ret = nums.size();
		for (int i = 0; i < nums.size(); ++i)
		{
			ret ^= (i^nums[i]);
		}
		return ret;
	}
};

// 颠倒二进制位
class Solution {
public:
	// 利用位运算，逐位颠倒
	uint32_t reverseBits(uint32_t n)
	{
		int ret = 0;
		for (int i = 31; i >= 0; --i)
		{
			ret |= ((n & 1) << i);
			n >>= 1;
		}
		return ret;
	}
};

// 数组中重复的数字
class Solution {
public:
	int findRepeatNumber(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int k = nums[i];
			if (k < 0)
			{
				k += n;
			}
			if (nums[k] < 0)
			{
				return k;
			}
			nums[k] -= n;
		}
		return -1;
	}
};