#define _CRT_SECURE_NO_WARNINGS 1

// ��������
class Solution {
public:
	vector<int> sortArray(vector<int>& nums)
	{
		int n = nums.size();
		int gap = n;
		// 1��Ԥ����ֱ��gapΪ1������ֱ�Ӳ�������
		while (gap > 1)
		{
			gap = gap / 3 + 1;// ����+1��֤gap������Ϊ1
			// 2����gapΪ�����ÿһ���������
			for (int i = 0; i < n - gap; ++i)
			{
				int end = i;
				int tmp = nums[end + gap];
				// 3������Ԥ����
				while (end >= 0)
				{
					if (nums[end] > tmp)
					{
						nums[end + gap] = nums[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				nums[end + gap] = tmp;
			}
		}
		return nums;
	}
};

// �绰������������
class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		// ������Ļ�����Ҳ���ؿ�����
		if (digits.size() == 0)
		{
			return vector<string>();
		}
		vector<string> phone{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ret;
		ret.push_back("");
		// �������
		for (auto& digit : digits)
		{
			vector<string> tmp;
			for (auto& s : ret)
			{
				for (auto& ch : phone[digit - '0'])
				{
					tmp.push_back(s + ch);
				}
			}
			ret = tmp;
		}
		return ret;
	}
};

// ջ��ѹ�롢��������
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
	{
		stack<int> s;
		int i = 0;
		// ����pushed����
		// ģ��ջ��ѹ��͵���
		for (auto& e : pushed)
		{
			s.push(e);
			while (!s.empty() && s.top() == popped[i])
			{
				s.pop();
				++i;
			}
		}
		// ������ջ���˾�����ȷ�ĵ�������
		return s.empty();
	}
};