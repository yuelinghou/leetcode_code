#define _CRT_SECURE_NO_WARNINGS 1

// ��ת����˳��
class Solution {
	// ��ÿ������ȡ�����ŵ�string������
	// �ٰ����鷭ת���������Ԫ�����μӵ�ret�ַ�����
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

// ����ļ���
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums)
	{
		int xorSum = 0;
		// 1���õ����������Ľ��
		for (auto& e : nums)
		{
			xorSum ^= e;
		}
		for (int i = 1; i <= nums.size(); ++i)
		{
			xorSum ^= i;
		}
		// 2���ҵ�������͵������βΪ1������λΪ0����
		int lowBit = xorSum & (-xorSum);
		// 3���õ�������
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
		// 4��������������
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

// ����ת�ַ���
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
