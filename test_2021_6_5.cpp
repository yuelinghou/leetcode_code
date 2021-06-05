#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;;

//// 外观数列
//class Solution {
//public:
//	string countAndSay(int n)
//	{
//		// n为0时，返回空串
//		if (!n)
//		{
//			return "";
//		}
//		string ret("1");// 记录最后返回的结果
//		string tmp;     // 记录新的外观数列
//		int count = 0;    // 统计相同数字出现的次数
//		for (int i = 1; i < n; ++i)
//		{
//			// 计算下一项外观数列之前，先把tmp置为空
//			tmp = "";
//			string::iterator it = ret.begin();
//			while (it < ret.end())
//			{
//				char ch = *it;
//				count = 1;
//				while (++it < ret.end() && *it == ch)
//				{
//					++count;
//				}
//				tmp += count + '0';// 先放次数
//				tmp += ch;       // 再放数字
//			}
//			ret = tmp;
//		}
//		return ret;
//	}
//};

// 字符串转换整数 (atoi)
class Solution {
public:
	int myAtoi(string s)
	{
		// 空串返回0
		if (s == "")
		{
			return 0;
		}
		int flag = 1;       // 标志正负
		int ret = 0;        // 记录最后结果
		int i = 0;          // 字符串的下标
		int size = s.size();// 字符串长度
		// 去除前面的空格
		while (i < size&&s[i] == ' ')
		{
			++i;
		}
		// 如果字符串全为空的的话，现在即结束
		if (i == size)
		{
			return 0;
		}
		// 获取第一个非空格字符
		switch (s[i])
		{
			// 1.第一个非空格字符为正负号的话，处理flag
		case '+':
			++i;
			break;
		case '-':
			flag = -1;
			++i;
			break;
			// 2.第一个非空格字符为数字0到9的话，把这个数字加到ret上
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			ret = s[i++] - '0';
			break;
			// 3.其他字符的话就非法，直接返回0
		default:
			return 0;
		}
		// 判断后面是否还有字符
		while (i == size)
		{
			return ret;
		}
		// 继续处理后面的数字，把它们加到ret后面，注意不能超出字符串的长度
		while (i < size && (s[i] >= '0'&&s[i] <= '9'))
		{
			// 1.越界情况的处理
			if (flag == 1 && ret > INT_MAX / 10)
			{
				return INT_MAX;
			}
			else if (flag == -1 && ret*-1 < INT_MIN / 10)
			{
				return INT_MIN;
			}
			else if (flag == 1 && ret == INT_MAX / 10)
			{
				if (i + 1 < size)
				{
					return INT_MAX;
				}
				else if (s[i] >= '7')
				{
					return INT_MAX;
				}
			}
			else if (flag == -1 && ret*-1 == INT_MIN / 10)
			{
				if (i + 1 < size)
				{
					return INT_MIN;
				}
				else if (s[i] >= '8')
				{
					return INT_MIN;
				}
			}
			// 2.没有越界的话就把数字加到ret后面
			ret = ret * 10 + (s[i++] - '0');
		}
		return ret * flag;
	}
};

// 最长公共前缀
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		// 空串的话直接返回空
		if (!strs.size())
		{
			return "";
		}
		// 把第一个子串作为最开始的公共前缀
		string ret(strs[0]);
		// 从第二个子串开始，一个字符一个字符的比较，更新公共前缀
		for (int i = 1; i < strs.size(); ++i)
		{
			int j = 0;
			while (j < ret.size() && j < strs[i].size())
			{
				if (ret[j] == strs[i][j])
				{
					++j;
				}
				else
				{
					break;
				}
			}
			ret = ret.substr(0, j);
			// 更新后的公共前缀如果为空，直接返回空
			if (!ret.size())
			{
				return "";
			}
		}
		return ret;
	}
};