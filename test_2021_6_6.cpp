#define _CRT_SECURE_NO_WARNINGS 1

// ��һ������İ汾
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n)
	{
		int left = 1;
		int right = n;
		// ��left==rightʱ���ߵ�ֵ���ǵ�һ������汾
		while (left < right)
		{
			// Ϊ�˷�ֹ�����������midʱҪ�����⴦��
			int mid = left + (right - left) / 2;
			// ifmid�Ǵ���汾���ǵ�һ������汾ֻ������left��mid֮�䣨����mid��
			if (isBadVersion(mid))
			{
				right = mid;
			}
			// ���mid���Ǵ���汾����ô��һ������汾ֻ��������mid+1��right֮��
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};

// ��¥��
/*
// ѭ����
class Solution {
public:
	int climbStairs(int n)
	{
		int n1=0;
		int n2=0;
		int n3=1;
		for(int i=1;i<=n;++i)
		{
			n1=n2;
			n2=n3;
			n3=n1+n2;
		}
		return n3;
	}
};
*/

// �ݹ鷨(��ʱ)
class Solution {
public:
	int climbStairs(int n)
	{
		if (n == 0)
		{
			return 1;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
		{
			return climbStairs(n - 1) + climbStairs(n - 2);
		}
	}
};

// ������Ʊ�����ʱ��
class Solution {
public:
	// �ʼ����Ϊ0����С�۸�Ϊ�����һ������̰���㷨����һ��õ���������
	int maxProfit(vector<int>& prices)
	{
		int max_profit = 0;
		int min_price = prices[0];
		for (int i = 1; i < prices.size(); ++i)
		{
			min_price = min(min_price, prices[i]);
			max_profit = max(max_profit, prices[i] - min_price);
		}
		return max_profit;
	}
};