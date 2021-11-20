#define _CRT_SECURE_NO_WARNINGS 1

// �����������
class Solution {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		// count������¼ȷ���±�λ�õ������������
		// һ��ʼ��ֻ���Լ������Զ���Ϊ1
		vector<int> count(nums.size(), 1);
		// ����[0, i-1]�����numsԪ�أ��ҵ�С��nums[i]��Ԫ��
		// ����count��dp[i] = max(dp[i], dp[j]+1);
		// ���ȡcounnt�����ֵ�������ս��
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

// ����˹�����ŷ�����
// sort��Ѵ����ÿһ��Ԫ�ؽ�����֮���ٴ���MyCompare�����Ƚ�
// ����MyCompare�Ĳ�������Ϊvector<int>
// �������true������e1�ŵ�e2֮ǰ
// �������false������e1�ŵ�e2֮��
// ���Ҫ��MyCompare���嵽���ڲ��Ļ���Ҫ��static���Σ�����sort�е���ʱ������Ϊû��thisָ�������
// Ҳ���԰�MyCompare���嵽����
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
