#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

// ��ת�ַ���
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

// ������ת
class Solution {
public:
	int reverse(int x)
	{
		int ret = 0;
		int digit = 0;
		// ÿ���õ����һ�����ֱ��浽ret
		while (x)
		{
			// �����������ǰ�ж�
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

// ��Ч����ĸ��λ��
class Solution {
public:
	// ��Ϊֻ����Сд��ĸ��������ȶ���һ���Ļ����߿϶�������ĸ��λ�ʹ�ϵ
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size())
		{
			return false;
		}
		// ����һ���Ļ��������ź��������Ⱦ�����ĸ��λ��
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};


