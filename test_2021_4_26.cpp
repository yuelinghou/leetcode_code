#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Solution {
//public:
//	//�ж϶�Ӧ�ַ��Ƿ�����ĸ
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
//			//begin����������ĸ
//			while (begin < end && !IsAlpha(S[begin]))
//			{
//				begin++;
//			}
//			//end������������ĸ
//			while (begin < end && !IsAlpha(S[end]))
//			{
//				end--;
//			}
//			//�ҵ��˾ͽ���
//			swap(S[begin], S[end]);
//			//����������ǰ��һ��
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
//		//����һ��������ӳ��ÿ����ĸ���ֵĴ���
//		int arr[26] = { 0 };
//		//����s������ÿ����ĸ����һ�ξ�ӳ�䵽����һ��
//		for (auto e : s)
//		{
//			arr[e - 'a']++;
//		}
//		//�ٴα���s����˳������������ӳ������Ƿ�Ϊ1
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
//	//�ж϶�Ӧ���ַ��Ƿ�����ĸ������
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
//		//�����д�д��ĸ��ת��ΪСд��ĸ
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
//			//begin��ǰ����Ѱ����ĸ������
//			while (!isAlphaOrNumber(s[begin]) && begin < end)
//			{
//				begin++;
//			}
//			//end�Ӻ���ǰѰ����ĸ������
//			while (!isAlphaOrNumber(s[end]) && begin < end)
//			{
//				end--;
//			}
//			//�ҵ��󣬲���ȵĻ���ֱ�ӷ���false
//			if (s[begin] != s[end])
//			{
//				return false;
//			}
//			else
//			{
//				//��ȵĻ��͸�����ǰ����һ��������������һ��
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
//		string ret;//������պ͵�����
//		int next = 0;//��λ
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		//�Ӻ���ǰ���������ַ�����ÿ���ַ�ת���������������
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
//			//ÿһλ����ӵõ�������ת�����ַ�β�嵽ret��
//			ret += valret + '0';
//		}
//		//�����һ���Ƿ��н�λ
//		if (next)
//		{
//			ret += '1';
//		}
//		//�����ַ����õ�������ӵĽ��
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};

class Solution {
public:
	string addStrings(string num1, string num2)
	{
		string ret;//������պ͵�����
		int next = 0;//��λ
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		//�Ӻ���ǰ���������ַ�����ÿ���ַ�ת���������������
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
			//ÿһλ����ӵõ�������ת�����ַ�β�嵽ret��
			ret += valret + '0';
		}
		//�����һ���Ƿ��н�λ
		if (next)
		{
			ret += '1';
		}
		//�����ַ����õ�������ӵĽ��
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
