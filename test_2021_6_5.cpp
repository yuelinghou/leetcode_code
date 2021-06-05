#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;;

//// �������
//class Solution {
//public:
//	string countAndSay(int n)
//	{
//		// nΪ0ʱ�����ؿմ�
//		if (!n)
//		{
//			return "";
//		}
//		string ret("1");// ��¼��󷵻صĽ��
//		string tmp;     // ��¼�µ��������
//		int count = 0;    // ͳ����ͬ���ֳ��ֵĴ���
//		for (int i = 1; i < n; ++i)
//		{
//			// ������һ���������֮ǰ���Ȱ�tmp��Ϊ��
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
//				tmp += count + '0';// �ȷŴ���
//				tmp += ch;       // �ٷ�����
//			}
//			ret = tmp;
//		}
//		return ret;
//	}
//};

// �ַ���ת������ (atoi)
class Solution {
public:
	int myAtoi(string s)
	{
		// �մ�����0
		if (s == "")
		{
			return 0;
		}
		int flag = 1;       // ��־����
		int ret = 0;        // ��¼�����
		int i = 0;          // �ַ������±�
		int size = s.size();// �ַ�������
		// ȥ��ǰ��Ŀո�
		while (i < size&&s[i] == ' ')
		{
			++i;
		}
		// ����ַ���ȫΪ�յĵĻ������ڼ�����
		if (i == size)
		{
			return 0;
		}
		// ��ȡ��һ���ǿո��ַ�
		switch (s[i])
		{
			// 1.��һ���ǿո��ַ�Ϊ�����ŵĻ�������flag
		case '+':
			++i;
			break;
		case '-':
			flag = -1;
			++i;
			break;
			// 2.��һ���ǿո��ַ�Ϊ����0��9�Ļ�����������ּӵ�ret��
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
			// 3.�����ַ��Ļ��ͷǷ���ֱ�ӷ���0
		default:
			return 0;
		}
		// �жϺ����Ƿ����ַ�
		while (i == size)
		{
			return ret;
		}
		// ���������������֣������Ǽӵ�ret���棬ע�ⲻ�ܳ����ַ����ĳ���
		while (i < size && (s[i] >= '0'&&s[i] <= '9'))
		{
			// 1.Խ������Ĵ���
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
			// 2.û��Խ��Ļ��Ͱ����ּӵ�ret����
			ret = ret * 10 + (s[i++] - '0');
		}
		return ret * flag;
	}
};

// �����ǰ׺
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		// �մ��Ļ�ֱ�ӷ��ؿ�
		if (!strs.size())
		{
			return "";
		}
		// �ѵ�һ���Ӵ���Ϊ�ʼ�Ĺ���ǰ׺
		string ret(strs[0]);
		// �ӵڶ����Ӵ���ʼ��һ���ַ�һ���ַ��ıȽϣ����¹���ǰ׺
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
			// ���º�Ĺ���ǰ׺���Ϊ�գ�ֱ�ӷ��ؿ�
			if (!ret.size())
			{
				return "";
			}
		}
		return ret;
	}
};