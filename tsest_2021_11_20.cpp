#define _CRT_SECURE_NO_WARNINGS 1

// 最长递增子序列
class Solution {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		// count用来记录确定下标位置的最长递增子序列
		// 一开始都只算自己，所以都置为1
		vector<int> count(nums.size(), 1);
		// 遍历[0, i-1]区间的nums元素，找到小于nums[i]的元素
		// 更新count的dp[i] = max(dp[i], dp[j]+1);
		// 最后取counnt中最大值就是最终结果
		for (size_t i = 1; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					count[i] = max(count[i], count[j] + 1);
				}
			}
		}
		return *max_element(count.begin(), count.end());
	}
};

// 俄罗斯套娃信封问题
// sort会把传入的每一个元素解引用之后再传入MyCompare中作比较
// 所以MyCompare的参数类型为vector<int>
// 如果返回true，则让e1排到e2之前
// 如果返回false，则让e1排到e2之后
// 如果要把MyCompare定义到类内部的话需要加static修饰，这样sort中调用时不会因为没有this指针而报错
// 也可以把MyCompare定义到类外
int MyCompare(const vector<int>& e1, const vector<int>& e2)
{
	if (e1[0] < e2[0])
	{
		return 1;
	}
	else if (e1[0] == e2[0] && e1[1] > e2[1])
	{
		return 1;
	}
	return 0;
}

class Solution
{
public:
	int maxEnvelopes(vector<vector<int>>& envelopes)
	{
		sort(envelopes.begin(), envelopes.end(), MyCompare);
		vector<int> count(envelopes.size(), 1);
		for (int i = 1; i < envelopes.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (envelopes[j][1] < envelopes[i][1])
				{
					count[i] = max(count[i], count[j] + 1);
				}
			}
		}
		return *max_element(count.begin(), count.end());
	}
};
