#define _CRT_SECURE_NO_WARNINGS 1

// Ŀ���
class Solution
{
	int count = 0;
	void BackTrack(const vector<int>& nums, int target, int index, int sum)
	{
		// ����±굽ͷ��˵���Ѿ��õ���һ��Ŀ��ͣ���ʱֻ���ж�sum�Ƿ����target����
		// ����±껹û��ͷ��sum���ϻ��ȥ��ǰ�±��Ӧ��ֵ�������ݹ鵽��һ���±��λ��
		if (index == nums.size())
		{
			if (target == sum)
			{
				++count;
			}
		}
		else
		{
			BackTrack(nums, target, index + 1, sum + nums[index]);
			BackTrack(nums, target, index + 1, sum - nums[index]);
		}
	}
public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		BackTrack(nums, target, 0, 0);
		return count;
	}
};

// �ַ�������
class Solution
{
public:
	// ��������ջ������ջ���ַ�ջ
	// �����ַ���
	// ���������ַ����Ȱ����洢���ַ���number��
	// ����']'�ַ������ַ�ջ���Ԫ�����γ�ջ�ŵ����뵽tmp��洢������ֱ������'['Ϊֹ���õ�����ջջ������tmp�ظ��Ĵ����������ظ�֮���ٰ�tmp���ַ�ջ��
	// ����'['��˵��s��ǰ�����ַ������֣���ʱ���ַ���numberת�����������뵽����ջ��
	// ������ʣ��ͨ��ĸ�ˣ�ֱ�����ַ�ջ
	string decodeString(string s)
	{
		stack<int> digitS;
		stack<char> charS;
		string number;
		for (auto e : s)
		{
			if (e >= '0' && e <= '9')
			{
				number += e;
			}
			else if (e == ']')
			{
				int count = digitS.top();
				digitS.pop();
				string tmp;
				while (charS.top() != '[')
				{
					tmp += charS.top();
					charS.pop();
				}
				charS.pop();
				reverse(tmp.begin(), tmp.end());
				string copy(tmp);
				while (--count)
				{
					tmp += copy;
				}
				for (auto ch : tmp)
				{
					charS.push(ch);
				}
			}
			else if (e == '[')
			{
				charS.push(e);
				digitS.push(stoi(number));
				number.clear();
			}
			else
			{
				charS.push(e);
			}
		}
		string ret;
		while (!charS.empty())
		{
			ret += charS.top();
			charS.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
