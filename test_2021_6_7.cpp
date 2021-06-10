#define _CRT_SECURE_NO_WARNINGS 1

// ��������
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = 0;
		int ret = nums[0];
		for (auto& e : nums)
		{
			if (sum >= 0)
			{
				sum += e;
			}
			// ���sum<0,�����ǵ�ǰ������û������Ч�������Դӵ�ǰ����ʼ���¼����
			else
			{
				sum = e;
			}
			// ret��¼ǰ������ĺ�
			ret = max(ret, sum);
		}
		return ret;
	}
};

// ��ҽ���
class Solution {
public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		// ����һ��Ļ�����߽���������Ǯ
		if (size == 1)
		{
			return nums[0];
		}
		int first = nums[0];              // ��¼��ǰһ��ʱ����͵�Ե�����߽��
		int second = max(nums[0], nums[1]);// ��¼������ʱ����͵�Ե�����߽��
		// �ӵ����俪ʼ���������ߣ�����second����ǰ���䣩�����е���߽��
		for (int i = 2; i < size; ++i)
		{
			int tmp = second;
			second = max(first + nums[i], second);
			first = tmp;
		}
		return second;
	}
};

// ��������
class Solution {
public:
	// ���캯��
	Solution(vector<int>& nums)
		:v(nums.begin(), nums.end())
	{}

	// ֱ�ӷ���v
	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		vector<int> shuffleArray(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			swap(shuffleArray[i], shuffleArray[i + rand() % (v.size() - i)]);
		}
		return shuffleArray;
	}

private:
	vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
