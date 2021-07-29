#define _CRT_SECURE_NO_WARNINGS 1

// 数值的整数次方
class Solution {
public:
	double myPow(double x, int n)
	{
		// 如果指数是负数的话，x要变为倒数，分母不能为0，所以这里先处理
		if (x == 0)
		{
			return 0;
		}
		// 为了能存储INT_MIN的相反数，所以类型转换成long
		long exponent = n;
		if (n < 0)
		{
			x = 1 / x;
			exponent = -exponent;// 不能exponent=-n，当n=INT_MIN时-n为int类型存不下
		}
		double ret = 1.0;
		// n变为二进制转十进制的公式来处理
		while (exponent > 0)
		{
			if (exponent & 1)
			{
				ret *= x;
			}
			x *= x;
			exponent >>= 1;
		}
		return ret;
	}
};

// 字符串相乘
class Solution {
public:
	string multiply(string num1, string num2)
	{
		// 其中一个为0就返回"0"
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		int len1 = num1.size();
		int len2 = num2.size();
		string ret(len1 + len2, '0');
		// 模拟乘法的过程
		for (int i = len1 - 1; i >= 0; --i)
		{
			for (int j = len2 - 1; j >= 0; --j)
			{
				// 一个数字去乘另外一个数字还要加上进位
				int part = (num1[i] - '0') * (num2[j] - '0') + (ret[i + j + 1] - '0');
				// 转化成字符放到对应位置
				ret[i + j + 1] = part % 10 + '0';
				// 处理上一个位置的进位
				ret[i + j] = (ret[i + j] - '0') + part / 10 + '0';
			}
		}
		// 去除前面多余的0
		for (int i = 0; i < len1 + len2; ++i)
		{
			if (ret[i] != '0')
			{
				return ret.substr(i);
			}
		}
		return "0";
	}
};

// 删除有序数组中的重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		// i下标从前往后遍历数组
		// index从0下标开始
		// 如果nums[i]!=nums[index]，就把i对应的值覆盖到++index位置
		// 最后index+1就是删除后数组的新长度,如果nums为空就要单独处理
		if (nums.size() == 0)
		{
			return 0;
		}
		int index = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[index] != nums[i])
			{
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};
