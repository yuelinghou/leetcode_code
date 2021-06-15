#define _CRT_SECURE_NO_WARNINGS 1

// ȱʧ����
class Solution {
public:
	int missingNumber(vector<int>& nums)
	{
		// 0���κ������Ϊ0
		// ��ͬ���������һ��Ϊ0
		int ret = nums.size();
		for (int i = 0; i < nums.size(); ++i)
		{
			ret ^= (i^nums[i]);
		}
		return ret;
	}
};

// �ߵ�������λ
class Solution {
public:
	// ����λ���㣬��λ�ߵ�
	uint32_t reverseBits(uint32_t n)
	{
		int ret = 0;
		for (int i = 31; i >= 0; --i)
		{
			ret |= ((n & 1) << i);
			n >>= 1;
		}
		return ret;
	}
};

// �������ظ�������
class Solution {
public:
	int findRepeatNumber(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int k = nums[i];
			if (k < 0)
			{
				k += n;
			}
			if (nums[k] < 0)
			{
				return k;
			}
			nums[k] -= n;
		}
		return -1;
	}
};