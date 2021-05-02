#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	//相同的数异或得0
	//0和任何数异或得任何数
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for (auto e : nums)
		{
			ret ^= e;
		}
		return ret;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		//搞个数组用来统计所有数每一位上一共有多少个1
		//要么3n要么3n+1
		int count[32] = { 0 };
		for (auto e : nums)//遍历vector元素
		{
			for (int i = 0; i < 32; ++i)//遍历每一个元素每一位上的值
			{
				if (e&(1 << i))
				{
					++count[i];
				}
			}
		}
		//根据count得到最后的结果
		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (count[i] % 3)
			{
				ret |= (1 << i);
			}
		}
		return ret;
	}
};

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		// 1.先把所有数与0异或，最后结果为只出现一次的两个值的异或
		int val = 0;
		for (auto e : nums)
		{
			val ^= e;
		}
		// 2.从左到右找到只出现一次的两个值异或结果中第一个位为1的那位
		int flag = 0;
		for (int i = 0; i < 32; i++)
		{
			if (val&(1 << i))
			{
				flag = i;
				break;
			}
		}
		// 3.再次遍历所以的数，根据第二步那位为0还是为1把数分为两组，每组分别与0异或。最终得到两个只出现一次的数
		int ret1 = 0;
		int ret2 = 0;
		for (auto e : nums)
		{
			if (e&(1 << flag))
			{
				ret1 ^= e;
			}
			else
			{
				ret2 ^= e;
			}
		}
		//把两个数放到vector里，最后返回vector
		vector<int> ret;
		ret.push_back(ret1);
		ret.push_back(ret2);
		return ret;
	}
};
