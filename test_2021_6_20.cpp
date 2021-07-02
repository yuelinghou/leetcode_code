#define _CRT_SECURE_NO_WARNINGS 1

// ѩ����������
class Solution {
	// ����һ������
public:
	int maxIceCream(vector<int>& costs, int coins)
	{
		// �ȶ���������
		sort(costs.begin(), costs.end());
		int count = 0;
		for (auto& e : costs)
		{
			// ��Ǯ��ѩ��
			if (e <= coins)
			{
				coins -= e;
				++count;
			}
			else
			{
				break;
			}
		}
		return count;
	}
};

class Solution {
	// ��������ӳ�����
public:
	int maxIceCream(vector<int>& costs, int coins)
	{
		// 1��ӳ��ÿ�ּ۸��ѩ�������������freq�У����±����۸������ֵ��������
		vector<int> freq(100001);
		for (auto& e : costs)
		{
			++freq[e];
		}
		// 2�������ұ���freq���飬ģ����ѩ��Ĺ���
		int singleCount = 0;
		int allCount = 0;
		for (int i = 1; i <= 100000; ++i)
		{
			if (i <= coins && freq[i] != 0)
			{
				singleCount = min(freq[i], coins / i);
				coins -= singleCount * i;
				allCount += singleCount;
			}
			else if (i > coins)
			{
				break;
			}
		}
		return allCount;
	}
};

// ���һ�����ʵĳ���
class Solution {
public:
	int lengthOfLastWord(string s)
	{
		// �洢��������
		string tmp;
		// �洢���е���
		vector<string> ret;
		// Ϊ��ʵ�������߼��ܹ������һ�����ʼӵ�ret�ԭ�ַ�������Ӹ��ո�
		s += " ";
		// ��ÿ������ȡ�����ŵ�ret��
		for (auto& e : s)
		{
			if (e == ' ')
			{
				if (!tmp.empty())
				{
					ret.push_back(tmp);
					tmp.clear();
				}
			}
			else
			{
				tmp += e;
			}
		}
		s.pop_back();
		// �������һ�����ʵĳ���
		return ret.size() == 0 ? 0 : ret[ret.size() - 1].size();
	}
};

// ��ת�ַ����ĵ���III
class Solution {
public:
	string reverseWords(string s)
	{
		s += ' ';// Ϊ��ʵ�������߼��ܹ�ʹ���һ�����ʼӵ�arr���sĩβ���ϸ��ո�
		string tmp;// ���浥�����ʵ��ַ���
		vector<string> arr;// �������е��ʵ�����
		// ��s�еĵ��ʼӵ�arr��
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
		// ����arr��string��Ԫ�أ��ٰ�arrԪ�ؼӵ�ret��
		string ret;
		for (auto& e : arr)
		{
			reverse(e.begin(), e.end());
			ret += e + " ";
		}
		ret.pop_back();
		s.pop_back();
		return ret;
	}
};
