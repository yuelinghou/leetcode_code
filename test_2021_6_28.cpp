#define _CRT_SECURE_NO_WARNINGS 1

// 排序数组
class Solution {
public:
	vector<int> sortArray(vector<int>& nums)
	{
		int n = nums.size();
		int gap = n;
		// 1、预排序，直到gap为1，就是直接插入排序
		while (gap > 1)
		{
			gap = gap / 3 + 1;// 最后的+1保证gap最后可以为1
			// 2、对gap为间隔的每一组进行排序
			for (int i = 0; i < n - gap; ++i)
			{
				int end = i;
				int tmp = nums[end + gap];
				// 3、单次预排序
				while (end >= 0)
				{
					if (nums[end] > tmp)
					{
						nums[end + gap] = nums[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				nums[end + gap] = tmp;
			}
		}
		return nums;
	}
};

// 电话号码的数字组合
class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		// 空数组的话我们也返回空数组
		if (digits.size() == 0)
		{
			return vector<string>();
		}
		vector<string> phone{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ret;
		ret.push_back("");
		// 排列组合
		for (auto& digit : digits)
		{
			vector<string> tmp;
			for (auto& s : ret)
			{
				for (auto& ch : phone[digit - '0'])
				{
					tmp.push_back(s + ch);
				}
			}
			ret = tmp;
		}
		return ret;
	}
};

// 栈的压入、弹出序列
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
	{
		stack<int> s;
		int i = 0;
		// 遍历pushed数组
		// 模拟栈的压入和弹出
		for (auto& e : pushed)
		{
			s.push(e);
			while (!s.empty() && s.top() == popped[i])
			{
				s.pop();
				++i;
			}
		}
		// 最后如果栈空了就是正确的弹出序列
		return s.empty();
	}
};