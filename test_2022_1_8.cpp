#define _CRT_SECURE_NO_WARNINGS 1

// �ж��ַ����������Ƿ�����
class Solution
{
private:
	// �ж��ַ��Ƿ���Ԫ���ַ�
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
		// ͳ���ַ���ǰ�벿��Ԫ���ַ�����
		for (size_t i = 0; i < s.size() / 2; ++i)
		{
			if (CountVowel(s[i]))
				++countHead;
		}
		// ͳ���ַ�����벿��Ԫ���ַ�����
		for (size_t i = s.size() / 2; i < s.size(); ++i)
		{
			if (CountVowel(s[i]))
				++countTail;
		}
		return countHead == countTail;
	}
};

// ��Ч����ĸ��λ��
class Solution {
public:
	bool isAnagram(string s, string t)
	{
		// ͳ��s������Сд��ĸ���ִ���
		vector<int> count(26);
		for (const auto e : s)
		{
			++count[e - 'a'];
		}
		// ����conut�е�ͳ�ƽ����ͳ��t������Сд��ĸ���ִ���
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
