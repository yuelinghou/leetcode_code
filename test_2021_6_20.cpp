#define _CRT_SECURE_NO_WARNINGS 1

// 雪糕的最大数量
class Solution {
	// 方法一：排序
public:
	int maxIceCream(vector<int>& costs, int coins)
	{
		// 先对数组升序
		sort(costs.begin(), costs.end());
		int count = 0;
		for (auto& e : costs)
		{
			// 扣钱买雪糕
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
	// 方法二：映射计数
public:
	int maxIceCream(vector<int>& costs, int coins)
	{
		// 1、映射每种价格的雪糕的数量到数组freq中，其下标代表价格，里面的值代表数量
		vector<int> freq(100001);
		for (auto& e : costs)
		{
			++freq[e];
		}
		// 2、从左到右遍历freq数组，模拟买雪糕的过程
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

// 最后一个单词的长度
class Solution {
public:
	int lengthOfLastWord(string s)
	{
		// 存储单个单词
		string tmp;
		// 存储所有单词
		vector<string> ret;
		// 为了实现下面逻辑能够把最后一个单词加到ret里，原字符串后面加个空格
		s += " ";
		// 把每个单词取出来放到ret中
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
		// 返回最后一个单词的长度
		return ret.size() == 0 ? 0 : ret[ret.size() - 1].size();
	}
};

// 反转字符串的单词III
class Solution {
public:
	string reverseWords(string s)
	{
		s += ' ';// 为了实现下面逻辑能够使最后一个单词加到arr里，给s末尾加上个空格
		string tmp;// 保存单个单词的字符串
		vector<string> arr;// 保存所有单词的数组
		// 把s中的单词加到arr里
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
		// 倒序arr的string类元素，再把arr元素加到ret里
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
