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
		// ��Ϊ�й̶����Ⱥ�˳�����Կ��԰������Ⱥ������жϣ����β���
		// �����Ͳ��ÿ��Ǹ��ָ����������
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

// 3����
class Solution {
public:
	bool isPowerOfThree(int n)
	{
		// n<1ʱ������������Ҳ�Ͳ�������ĿҪ�󣨵�Ȼn������Ϊ0��
		if (n < 1)
		{
			return false;
		}
		// �����3���ݣ�һֱ/=3����n���Ϊ1
		while (n != 1)
		{
			// Ҫ������3����������������3���ݵ����
			if (n % 3)
				return false;
			n /= 3;
		}
		return true;
	}
};

// ��������
class Solution {
public:
	// ����ɸ��
	int countPrimes(int n)
	{
		// �ȼ���ȫ������
		vector v(n, 1);
		int count = 0;
		// ����С������2��ʼ
		for (int i = 2; i < n; ++i)
		{
			if (v[i])
			{
				++count;
				// ɸѡ������ķ�����
				// �������int�ͣ��Ͳ������if����ڲ�������ֻ��������ǿ��װ��һ�¾���
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
