#define _CRT_SECURE_NO_WARNINGS 1

// ��ӡ��1������nλ��
class Solution {
private:
	vector<int> ret;
	string s;

	// �������е����
	void Divide(int end, int index)
	{
		if (index == end)
		{
			Save();
			return;
		}
		for (int i = 0; i <= 9; ++i)
		{
			s[index] = i + '0';
			Divide(end, index + 1);
		}
	}
	// ȥ���ײ���0
	void Save()
	{
		int start = 0;
		while (s[start] == '0'&&start < s.size())
		{
			++start;
		}
		if (start != s.size())
		{
			ret.push_back(stoi(s.substr(start)));
		}
	}

public:
	vector<int> printNumbers(int n)
	{
		s.resize(n, '0');
		Divide(n, 0);
		return ret;
	}
};

// ��������˳��ʹ����λ��ż��ǰ��
/*
class Solution {
public:
	// ����һ����λָ��
	//��ָ��ǰ��������ż����λ�ã�βָ�Ӻ���ǰ����������λ��
	vector<int> exchange(vector<int>& nums)
	{
		int left=0;
		int right=nums.size()-1;
		while(left<right)
		{
			if(nums[left]%2==1)
			{
				++left;
				continue;
			}
			if(nums[right]%2==0)
			{
				--right;
				continue;
			}
			swap(nums[left],nums[right]);
		}
		return nums;
	}
};
*/

// ������������ָ��
// ��ָ���¼ǰ���ż����λ�ã���ָ���Һ��������
class Solution {
public:
	vector<int> exchange(vector<int>& nums)
	{
		int slow = 0;
		int fast = 0;
		while (fast < nums.size())
		{
			if (nums[fast] % 2 == 1)
			{
				swap(nums[slow], nums[fast]);
				++slow;
			}
			++fast;
		}
		return nums;
	}
};

// ɾ������Ľڵ�
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val)
	{
		// �ȴ��������͵�һ���ڵ��ֵ����val�����
		if (!head)
		{
			return nullptr;
		}
		else if (head->val == val)
		{
			return head->next;
		}
		// ˫ָ�룬��¼ǰһ���ڵ�͵�ǰ�ڵ�����������ߣ�������ǰ�ڵ��ֵ�Ƿ�Ϊval
		ListNode* prev = head;
		ListNode* cur = head->next;
		while (cur)
		{
			if (cur->val == val)
			{
				prev->next = cur->next;
				return head;
			}
			prev = cur;
			cur = cur->next;
		}
		return head;
	}
};

