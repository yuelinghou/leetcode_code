#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

// 反转字符串
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin++], s[end--]);
		}
	}
};

// 整数反转
class Solution {
public:
	int reverse(int x)
	{
		int ret = 0;
		int digit = 0;
		// 每次拿到最后一个数字保存到ret
		while (x)
		{
			// 整型溢出的提前判断
			if (ret<INT_MIN / 10 || ret>INT_MAX / 10)
			{
				return 0;
			}
			digit = x % 10;
			x /= 10;
			ret = ret * 10 + digit;
		}
		return ret;
	}
};

// 有效的字母异位词
class Solution {
public:
	// 因为只包含小写字母，如果长度都不一样的话二者肯定不是字母异位词关系
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size())
		{
			return false;
		}
		// 长度一样的话，二者排好序如果相等就是字母异位词
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};


