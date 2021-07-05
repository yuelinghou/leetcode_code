#define _CRT_SECURE_NO_WARNINGS 1

// �˿����е�˳��
class Solution {
public:
	// ����һ������ģ��
	bool isStraight(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int king = 0;
		// �ź���������Ƚ�
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			// 1���ȼ�¼������С��������
			if (nums[i] == 0)
			{
				++king;
				continue;
			}
			// 2�������ȽϷǴ�С����
			if (nums[i] == nums[i + 1])
			{
				return false;
			}
			else if (nums[i] + 1 == nums[i + 1])
			{
				continue;
			}
			else
			{
				king -= (nums[i + 1] - nums[i] - 1);
				if (king < 0)
				{
					return false;
				}
			}
		}
		return true;
	}
};

class Solution {
	// ��������ӳ��ģ��
public:
	bool isStraight(vector<int>& nums)
	{
		int left = INT_MAX;
		int right = INT_MIN;
		vector<bool> board(14, false);
		for (auto& e : nums)
		{
			// �����Ļ�ֱ������
			if (e == 0)
			{
				continue;
			}
			// �����ƵĻ�
			// ����Ѿ���true���ظ��ˣ�����false
			// �����false�Ͱ�����Ϊtrue�����Ҹ���left��right
			if (board[e])
			{
				return false;
			}
			else
			{
				board[e] = true;
				if (e < left)
				{
					left = e;
				}
				if (e > right)
				{
					right = e;
				}
			}
		}
		// ������ս������5��������5���ƹ��ɴ���5���Ƶ�˳�ӣ����Է���false
		// ����5��˵���պù���˳�ӣ���������Ҳ����û�����������Ļ��ǲ����м�λ�ã�
		// С��5��һ��������������ͷλ�û�����ĩβλ��
		if (right - left + 1 > 5)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

// ȦȦ�����ʣ�µ�����
class Solution {
public:
	// Լɪ������
	// һ����ʱ�����ʣ�µ����ֵ��±���0
	// ������ʱ�����ʣ�������±���һ����ʱ���±�+m��Ϊ�˷�ֹԽ��Ҫģ�ϵ�ǰ����2
	// ...
	int lastRemaining(int n, int m)
	{
		int pos = 0;
		for (int i = 2; i <= n; ++i)
		{
			pos = (pos + m) % i;
		}
		return pos;
	}
};

// ǰk����Ƶ����
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 1��ͳ�Ƶ��ʳ��ֵĴ���
		map<string, int> m;
		for (auto& e : words)
		{
			m[e]++;
		}
		// 2��ͨ���º��������յ��ʳ��ֵĴ����Ӵ�С����
		multimap<int, string, greater<int>>mm;
		for (auto& e : m)
		{
			mm.insert(make_pair(e.second, e.first));
		}
		// 3����ǰk����Ƶ���ʷŵ�������
		vector<string> ret;
		for (auto& e : mm)
		{
			ret.push_back(e.second);
			if (--k == 0)
			{
				break;
			}
		}
		return ret;
	}
};
