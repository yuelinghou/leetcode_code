#define _CRT_SECURE_NO_WARNINGS 1

// 翻转单词顺序
class Solution {
	// 把每个单词取出来放到string数组里
	// 再把数组翻转，把里面的元素依次加到ret字符串里
public:
	string reverseWords(string s)
	{
		s += ' ';
		string tmp;
		vector<string> arr;
		for (auto& e : s)
		{
			if (e == ' ')
			{
				if (!tmp.empty())
				{
					arr.push_back(tmp);
					tmp.clear();
				}
			}
			else
			{
				tmp += e;
			}
		}
		reverse(arr.begin(), arr.end());
		string ret;
		for (auto& e : arr)
		{
			ret += e + " ";
		}
		ret.pop_back();
		return ret;
	}
};

// 错误的集合
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums)
	{
		int xorSum = 0;
		// 1、得到两个数异或的结果
		for (auto& e : nums)
		{
			xorSum ^= e;
		}
		for (int i = 1; i <= nums.size(); ++i)
		{
			xorSum ^= i;
		}
		// 2、找到他们最低的相异的尾为1，其他位为0的数
		int lowBit = xorSum & (-xorSum);
		// 3、得到两个数
		int num1 = 0;
		int num2 = 0;
		for (auto& e : nums)
		{
			if (lowBit&e)
			{
				num1 ^= e;
			}
			else
			{
				num2 ^= e;
			}
		}
		for (int i = 1; i <= nums.size(); ++i)
		{
			if (lowBit&i)
			{
				num1 ^= i;
			}
			else
			{
				num2 ^= i;
			}
		}
		// 4、区分这两个数
		for (auto& e : nums)
		{
			if (e == num1)
			{
				return vector<int>{num1, num2};
			}
		}
		return vector<int>{num2, num1};
	}
};

// 左旋转字符串
class Solution {
	void Reverse(string& s, int left, int right)
	{
		while (left < right)
		{
			swap(s[left], s[right]);
			++left;
			--right;
		}
	}
public:
	string reverseLeftWords(string s, int n)
	{
		int len = s.size() - 1;
		Reverse(s, 0, len);
		Reverse(s, 0, len - n);
		Reverse(s, len - n + 1, len);
		return s;
	}
};
