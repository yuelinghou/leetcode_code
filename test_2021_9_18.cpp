#define _CRT_SECURE_NO_WARNINGS 1

// 最长不含重复字符的子字符串
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		string tmp;
		size_t maxLength = 0;// 记录最长无重复子串长度
		size_t index = 0;
		for (auto& e : s)
		{
			index = tmp.find(e);// 如果存在返回下标，不存在返回-1
			if (-1 != index)// 字符已经存在
			{
				maxLength = max(maxLength, tmp.size());// 更新最长长度
				tmp.erase(0, index + 1);// 删除前面的区间
			}
			tmp += e;// 存在或不存在，都要尾插当前字符
		}
		return max(maxLength, tmp.size());// 遍历完最后还要更新一次
	}
};
