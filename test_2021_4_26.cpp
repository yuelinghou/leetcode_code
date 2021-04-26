#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Solution {
//public:
//	//判断对应字符是否是字母
//	bool IsAlpha(char c)
//	{
//		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	string reverseOnlyLetters(string S)
//	{
//		int begin = 0;
//		int end = S.size() - 1;
//		while (begin < end)
//		{
//			//begin从左到右找字母
//			while (begin < end && !IsAlpha(S[begin]))
//			{
//				begin++;
//			}
//			//end从右往左找字母
//			while (begin < end && !IsAlpha(S[end]))
//			{
//				end--;
//			}
//			//找到了就交换
//			swap(S[begin], S[end]);
//			//交换各自往前走一步
//			begin++;
//			end--;
//		}
//		return S;
//	}
//};
//
//class Solution {
//public:
//	int firstUniqChar(string s)
//	{
//		//定义一个数组来映射每个字母出现的次数
//		int arr[26] = { 0 };
//		//遍历s，其中每个字母出现一次就映射到数组一次
//		for (auto e : s)
//		{
//			arr[e - 'a']++;
//		}
//		//再次遍历s，按顺序对照数组里的映射次数是否为1
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (arr[s[i] - 'a'] == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//};

//class Solution {
//public:
//	//判断对应的字符是否是字母或数字
//	bool isAlphaOrNumber(char ch)
//	{
//		if ((ch >= 'a'&&ch <= 'z') || (ch >= '0' && ch <= '9'))
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool isPalindrome(string s)
//	{
//		//把所有大写字母都转化为小写字母
//		for (auto& e : s)
//		{
//			if (e >= 'A'&& e <= 'Z')
//			{
//				e += 32;
//			}
//		}
//		int begin = 0;
//		int end = s.size() - 1;
//		while (begin < end)
//		{
//			//begin从前往后寻找字母或数字
//			while (!isAlphaOrNumber(s[begin]) && begin < end)
//			{
//				begin++;
//			}
//			//end从后往前寻找字母或数字
//			while (!isAlphaOrNumber(s[end]) && begin < end)
//			{
//				end--;
//			}
//			//找到后，不相等的话就直接返回false
//			if (s[begin] != s[end])
//			{
//				return false;
//			}
//			else
//			{
//				//相等的话就各自往前再走一步，继续继续下一组
//				begin++;
//				end--;
//			}
//		}
//		return true;
//	}
//};
//
//class Solution {
//public:
//	string addStrings(string num1, string num2)
//	{
//		string ret;//存放最终和的数字
//		int next = 0;//进位
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		//从后往前遍历两个字符串，每个字符转化成数字两两相加
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = 0;
//			int val2 = 0;
//			if (end1 >= 0)
//			{
//				val1 = num1[end1--] - '0';
//			}
//			if (end2 >= 0)
//			{
//				val2 = num2[end2--] - '0';
//			}
//			int valret = val1 + val2 + next;
//			if (valret > 9)
//			{
//				valret -= 10;
//				next = 1;
//			}
//			else
//			{
//				next = 0;
//			}
//			//每一位上相加得到的数字转化成字符尾插到ret中
//			ret += valret + '0';
//		}
//		//最后检查一下是否还有进位
//		if (next)
//		{
//			ret += '1';
//		}
//		//逆置字符串得到最终相加的结果
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};

class Solution {
public:
	string addStrings(string num1, string num2)
	{
		string ret;//存放最终和的数字
		int next = 0;//进位
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		//从后往前遍历两个字符串，每个字符转化成数字两两相加
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = 0;
			int val2 = 0;
			if (end1 >= 0)
			{
				val1 = num1[end1--] - '0';
			}
			if (end2 >= 0)
			{
				val2 = num2[end2--] - '0';
			}
			int valret = val1 + val2 + next;
			if (valret > 9)
			{
				valret -= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}
			//每一位上相加得到的数字转化成字符尾插到ret中
			ret += valret + '0';
		}
		//最后检查一下是否还有进位
		if (next)
		{
			ret += '1';
		}
		//逆置字符串得到最终相加的结果
		reverse(ret.begin(), ret.end());
		return ret;
	}

	string multiply(string num1, string num2)
	{
		string ret("0");
		string count("0");
		while (count != num2)
		{
			ret = addStrings(ret, num1);
			count = addStrings(count, "1");
		}
		return ret;
	}
};

int main()
{
	Solution s;
	string s2(s.multiply("123456789", "987654321"));
	/*Solution s;
	s.isPalindrome("A man, a plan, a canal: Panama");
	cout << s.isPalindrome("A man, a plan, a canal: Panama")<<endl;*/
	return 0;
}
