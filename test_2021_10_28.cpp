#define _CRT_SECURE_NO_WARNINGS 1

// 目标和
class Solution
{
	int count = 0;
	void BackTrack(const vector<int>& nums, int target, int index, int sum)
	{
		// 如果下标到头了说明已经得到了一组目标和，这时只需判断sum是否等于target即可
		// 如果下标还没到头，sum加上或减去当前下标对应的值，继续递归到下一个下标的位置
		if (index == nums.size())
		{
			if (target == sum)
			{
				++count;
			}
		}
		else
		{
			BackTrack(nums, target, index + 1, sum + nums[index]);
			BackTrack(nums, target, index + 1, sum - nums[index]);
		}
	}
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		BackTrack(nums, target, 0, 0);
		return count;
	}
};

// 字符串解码
class Solution
{
public:
	// 建立两个栈：数字栈、字符栈
	// 遍历字符串
	// 遇到数字字符，先把它存储到字符串number中
	// 遇到']'字符，把字符栈里的元素依次出栈放到加入到tmp里存储起来，直到遇到'['为止，拿到数字栈栈顶就是tmp重复的次数，处理重复之后再把tmp入字符栈。
	// 遇到'['，说明s的前几个字符是数字，此时把字符串number转化成整数加入到数字栈中
	// 其他就剩普通字母了，直接入字符栈
	string decodeString(string s)
	{
		stack<int> digitS;
		stack<char> charS;
		string number;
		for (auto e : s)
		{
			if (e >= '0' && e <= '9')
			{
				number += e;
			}
			else if (e == ']')
			{
				int count = digitS.top();
				digitS.pop();
				string tmp;
				while (charS.top() != '[')
				{
					tmp += charS.top();
					charS.pop();
				}
				charS.pop();
				reverse(tmp.begin(), tmp.end());
				string copy(tmp);
				while (--count)
				{
					tmp += copy;
				}
				for (auto ch : tmp)
				{
					charS.push(ch);
				}
			}
			else if (e == '[')
			{
				charS.push(e);
				digitS.push(stoi(number));
				number.clear();
			}
			else
			{
				charS.push(e);
			}
		}
		string ret;
		while (!charS.empty())
		{
			ret += charS.top();
			charS.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
