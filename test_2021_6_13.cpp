#define _CRT_SECURE_NO_WARNINGS 1

// 打印从1到最大的n位数
class Solution {
private:
	vector<int> ret;
	string s;

	// 排列所有的情况
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
	// 去除首部的0
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

// 调整数组顺序使奇数位于偶数前面
/*
class Solution {
public:
	// 方法一：首位指针
	//首指从前往后针找偶数的位置，尾指从后往前针找奇数的位置
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

// 方法二：快慢指针
// 慢指针记录前面的偶数的位置，快指针找后面的奇数
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

// 删除链表的节点
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val)
	{
		// 先处理空链表和第一个节点的值就是val的情况
		if (!head)
		{
			return nullptr;
		}
		else if (head->val == val)
		{
			return head->next;
		}
		// 双指针，记录前一个节点和当前节点遍历着往下走，看看当前节点的值是否为val
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

