#define _CRT_SECURE_NO_WARNINGS 

// 1��0~n-1��ȱʧ������
class Solution {
public:
	// o����κ������κ���
	// ��ͬ���������һ��Ϊ0
	int missingNumber(vector<int>& nums)
	{
		int ret = 0;
		for (int i = 1; i < nums.size() + 1; ++i)
		{
			ret ^= i;
		}
		for (auto& e : nums)
		{
			ret ^= e;
		}
		return ret;
	}
};

// 2����Ϊs����������
class Solution {
public:
	// ��������ָ��
	// ��֤left<right
	// �������֮�ʹ���target����--right
	// �������֮��С��target����++left
	// ����target�Ļ������ҵ���
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			if (target - nums[right] == nums[left])
			{
				return vector<int>{nums[left], nums[right]};
			}
			else if (target - nums[right] < nums[left])
			{
				--right;
			}
			else
			{
				++left;
			}
		}
		return vector<int>();
	}
};

// 3����Ϊs��������������
class Solution {
public:
	// ����һ��������
	vector<vector<int>> findContinuousSequence(int target)
	{
		vector<vector<int>> ret;
		// ��Ϊ�������������������֣������Ͻ�Ϊtarget/2
		// ��1��ʼ����ÿ������
		for (int i = 1; i <= target / 2; ++i)
		{
			int sum = 0;
			vector<int> sub;
			// ��i��ʼ�����ۼ�
			for (int j = i;; ++j)
			{
				sum += j;
				if (sum == target)
				{
					for (int k = i; k <= j; ++k)
					{
						sub.push_back(k);
					}
					ret.push_back(sub);
				}
				else if (sum > target)// ���sum����target�Ļ�����i�Ͳ����ˣ�ֱ���˳�
				{
					break;
				}
			}
		}
		return ret;
	}
};

class Solution {
public:
	// ��������˫ָ��
	vector<vector<int>> findContinuousSequence(int target)
	{
		int left = 1;
		int right = 2;
		vector<vector<int>> ret;
		while (left < right)
		{
			int sum = (left + right)*(right - left + 1) / 2;
			vector<int> sub;
			if (sum == target)
			{
				for (int i = left; i <= right; ++i)
				{
					sub.push_back(i);
				}
				++left;
				ret.push_back(sub);
			}
			else if (sum < target)
			{
				++right;
			}
			else
			{
				++left;
			}
		}
		return ret;
	}
};
