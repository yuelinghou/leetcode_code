#define _CRT_SECURE_NO_WARNINGS 1

// 数组中出现次数超过一半的数字
class Solution {
public:
	// 摩恩投票法
	// 不同的两个数抵消
	// 超过一半的留到最后
	int majorityElement(vector<int>& nums)
	{
		int x = 0;
		int vote = 0;
		for (auto& e : nums)
		{
			if (vote == 0)
			{
				x = e;
			}
			vote += (e == x ? 1 : -1);
		}
		return x;
	}
};

// 第一次只出现第一次的字符
class Solution {
public:
	// 构建一个26小写字母的数组
	// 遍历字符串，把每个字符映射到数组里
	// 再次遍历字符串看看对应字符在字符串中的影射次数
	// 第一个为1的就是第一个只出现一次的字符
	char firstUniqChar(string s)
	{
		vector<int> alphabet(26, 0);
		for (auto& e : s)
		{
			++alphabet[e - 'a'];
		}
		for (auto& e : s)
		{
			if (alphabet[e - 'a'] == 1)
			{
				return e;
			}
		}
		return ' ';
	}
};

// 两个链表的第一个公共节点
 // 方法一
 // 先求出两个链表的长度
 // 在让两个链表从同一长度的起点开始走
 // 过程中判断两个节点是否相等
class Solution {
	size_t GetLength(ListNode* head)
	{
		size_t length = 0;
		while (head)
		{
			++length;
			head = head->next;
		}
		return length;
	}
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		size_t lengthA = GetLength(headA);
		size_t lengthB = GetLength(headB);
		while (lengthA != lengthB)
		{
			if (lengthA > lengthB)
			{
				headA = headA->next;
				--lengthA;
			}
			else
			{
				headB = headB->next;
				--lengthB;
			}
		}
		while (lengthA != 0)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
			--lengthA;
		}
		return nullptr;
	}
};

class Solution {
public:
	// 方法二
	// 两个指针一起走，走到空就走另外一个链表
	// 到最后肯定会相遇
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode* A = headA;
		ListNode* B = headB;
		while (A != B)
		{
			A = (A == nullptr ? headB : A->next);
			B = (B == nullptr ? headA : B->next);
		}
		return A;
	}
};