#define _CRT_SECURE_NO_WARNINGS 1

// 最大子序和
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = 0;
		int ret = nums[0];
		for (auto& e : nums)
		{
			if (sum >= 0)
			{
				sum += e;
			}
			// 如果sum<0,对我们当前的最大和没有增益效果，所以从当前数开始重新计算和
			else
			{
				sum = e;
			}
			// ret记录前面的最大的和
			ret = max(ret, sum);
		}
		return ret;
	}
};

// 打家劫舍
class Solution {
public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		// 才有一间的话，最高金额就是这间的钱
		if (size == 1)
		{
			return nums[0];
		}
		int first = nums[0];              // 记录到前一间时，所偷窃到的最高金额
		int second = max(nums[0], nums[1]);// 记录到当间时，所偷窃到的最高金额
		// 从第三间开始迭代往后走，更新second（当前房间）所持有的最高金额
		for (int i = 2; i < size; ++i)
		{
			int tmp = second;
			second = max(first + nums[i], second);
			first = tmp;
		}
		return second;
	}
};

// 打乱数组
class Solution {
public:
	// 构造函数
	Solution(vector<int>& nums)
		:v(nums.begin(), nums.end())
	{}

	// 直接返回v
	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		vector<int> shuffleArray(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			swap(shuffleArray[i], shuffleArray[i + rand() % (v.size() - i)]);
		}
		return shuffleArray;
	}

private:
	vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
