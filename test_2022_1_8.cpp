#define _CRT_SECURE_NO_WARNINGS 1

// 判断字符串的两半是否相似
class Solution
{
private:
	// 判断字符是否是元音字符
	bool CountVowel(const char ch)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			return true;
		else
			return false;
	}
public:
	bool halvesAreAlike(string s)
	{
		size_t countHead = 0;
		size_t countTail = 0;
		// 统计字符串前半部分元音字符个数
		for (size_t i = 0; i < s.size() / 2; ++i)
		{
			if (CountVowel(s[i]))
				++countHead;
		}
		// 统计字符串后半部分元音字符个数
		for (size_t i = s.size() / 2; i < s.size(); ++i)
		{
			if (CountVowel(s[i]))
				++countTail;
		}
		return countHead == countTail;
	}
};

// 有效的字母异位词
class Solution {
public:
	bool isAnagram(string s, string t)
	{
		// 统计s中所有小写字母出现次数
		vector<int> count(26);
		for (const auto e : s)
		{
			++count[e - 'a'];
		}
		// 对照conut中的统计结果，统计t中所有小写字母出现次数
		for (const auto e : t)
		{
			--count[e - 'a'];
		}
		for (const auto e : count)
		{
			if (e != 0)
				return false;
		}
		return true;
	}
};
