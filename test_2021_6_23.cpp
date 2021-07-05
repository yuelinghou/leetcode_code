#define _CRT_SECURE_NO_WARNINGS 1

// 扑克牌中的顺子
class Solution {
public:
	// 方法一：排序模拟
	bool isStraight(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int king = 0;
		// 排好序后两两比较
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			// 1、先记录下来大小王的数量
			if (nums[i] == 0)
			{
				++king;
				continue;
			}
			// 2、两两比较非大小王牌
			if (nums[i] == nums[i + 1])
			{
				return false;
			}
			else if (nums[i] + 1 == nums[i + 1])
			{
				continue;
			}
			else
			{
				king -= (nums[i + 1] - nums[i] - 1);
				if (king < 0)
				{
					return false;
				}
			}
		}
		return true;
	}
};

class Solution {
	// 方法二：映射模拟
public:
	bool isStraight(vector<int>& nums)
	{
		int left = INT_MAX;
		int right = INT_MIN;
		vector<bool> board(14, false);
		for (auto& e : nums)
		{
			// 有王的话直接跳过
			if (e == 0)
			{
				continue;
			}
			// 非王牌的话
			// 如果已经是true就重复了，返回false
			// 如果是false就把他置为true，并且更新left和right
			if (board[e])
			{
				return false;
			}
			else
			{
				board[e] = true;
				if (e < left)
				{
					left = e;
				}
				if (e > right)
				{
					right = e;
				}
			}
		}
		// 如果最终结果大于5，不可能5张牌构成大于5张牌的顺子，所以返回false
		// 等于5，说明刚好构成顺子（可能有王也可能没有王，有王的话是补到中间位置）
		// 小于5，一定有王，不到开头位置或者是末尾位置
		if (right - left + 1 > 5)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

// 圈圈中最后剩下的数字
class Solution {
public:
	// 约瑟夫环问题
	// 一个人时，最后剩下的数字的下标是0
	// 两个人时，最后剩下数字下标是一个人时的下标+m，为了防止越界要模上当前人数2
	// ...
	int lastRemaining(int n, int m)
	{
		int pos = 0;
		for (int i = 2; i <= n; ++i)
		{
			pos = (pos + m) % i;
		}
		return pos;
	}
};

// 前k个高频单词
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 1、统计单词出现的次数
		map<string, int> m;
		for (auto& e : words)
		{
			m[e]++;
		}
		// 2、通过仿函数，按照单词出现的次数从大到小排序
		multimap<int, string, greater<int>>mm;
		for (auto& e : m)
		{
			mm.insert(make_pair(e.second, e.first));
		}
		// 3、把前k个高频单词放到数组里
		vector<string> ret;
		for (auto& e : mm)
		{
			ret.push_back(e.second);
			if (--k == 0)
			{
				break;
			}
		}
		return ret;
	}
};
