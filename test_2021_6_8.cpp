#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Fizz Buzz
class Solution {
public:
	vector<string> fizzBuzz(int n)
	{
		string apart;
		vector<string> ret;
		// 因为有固定的先后顺序，所以可以按照其先后依次判断，依次插入
		// 这样就不用考虑各种各样的情况了
		for (int i = 1; i <= n; ++i)
		{
			if (i % 3 == 0)
			{
				apart += "Fizz";
			}
			if (i % 5 == 0)
			{
				apart += "Buzz";
			}
			if (i % 3 != 0 && i % 5 != 0)
			{
				apart += to_string(i);
			}
			ret.push_back(apart);
			apart.clear();
		}
		return ret;
	}
};

// 3的幂
class Solution {
public:
	bool isPowerOfThree(int n)
	{
		// n<1时，不是整数，也就不符合题目要求（当然n不可能为0）
		if (n < 1)
		{
			return false;
		}
		// 如果是3的幂，一直/=3最终n会变为1
		while (n != 1)
		{
			// 要考虑是3的整数倍，但不是3的幂的情况
			if (n % 3)
				return false;
			n /= 3;
		}
		return true;
	}
};

// 计数质数
class Solution {
public:
	// 埃氏筛法
	int countPrimes(int n)
	{
		// 先假设全是质数
		vector v(n, 1);
		int count = 0;
		// 从最小的质数2开始
		for (int i = 2; i < n; ++i)
		{
			if (v[i])
			{
				++count;
				// 筛选出后面的非质数
				// 如果超过int型，就不会进入if语句内部，所以只用在这里强制装换一下就行
				if ((long long)i*i < n)
				{
					for (int j = i * i; j < n; j += i)
					{
						v[j] = 0;
					}
				}
			}
		}
		return count;
	}
};


int main()
{
	vector<string> ret = Solution().fizzBuzz(3);
	for (auto& e : ret)
	{
		cout << e << endl;
	}
	return 0;
}
