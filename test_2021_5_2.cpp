#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	//��ͬ��������0
	//0���κ��������κ���
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
		//�����������ͳ��������ÿһλ��һ���ж��ٸ�1
		//Ҫô3nҪô3n+1
		int count[32] = { 0 };
		for (auto e : nums)//����vectorԪ��
		{
			for (int i = 0; i < 32; ++i)//����ÿһ��Ԫ��ÿһλ�ϵ�ֵ
			{
				if (e&(1 << i))
				{
					++count[i];
				}
			}
		}
		//����count�õ����Ľ��
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
		// 1.�Ȱ���������0��������Ϊֻ����һ�ε�����ֵ�����
		int val = 0;
		for (auto e : nums)
		{
			val ^= e;
		}
		// 2.�������ҵ�ֻ����һ�ε�����ֵ������е�һ��λΪ1����λ
		int flag = 0;
		for (int i = 0; i < 32; i++)
		{
			if (val&(1 << i))
			{
				flag = i;
				break;
			}
		}
		// 3.�ٴα������Ե��������ݵڶ�����λΪ0����Ϊ1������Ϊ���飬ÿ��ֱ���0������յõ�����ֻ����һ�ε���
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
		//���������ŵ�vector���󷵻�vector
		vector<int> ret;
		ret.push_back(ret1);
		ret.push_back(ret2);
		return ret;
	}
};
