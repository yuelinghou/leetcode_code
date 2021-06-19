#define _CRT_SECURE_NO_WARNINGS 1

// 旋转链表
class Solution {
public:
	// 遍历每个节点，让当前节点的next指向前一个节点
	ListNode* reverseList(ListNode* head)
	{
		// 空链表或者只有一个节点的链表就不用旋转了
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = head->next;
		while (cur)
		{
			// 然当前节点的next指向前一个节点
			cur->next = prev;
			// 迭代往后走
			prev = cur;
			cur = next;
			if (next)
			{
				next = next->next;
			}
		}
		return prev;
	}
};

// 链表中倒数第k个节点
class Solution {
public:
	// 快指针先走k步，之后两个指针一起走
	// 快指针到nullptr时，慢指针指向的节点即为倒数第k个节点
	ListNode* getKthFromEnd(ListNode* head, int k)
	{
		// 空链表或k不合法时的处理
		if (head == nullptr || k <= 0)
		{
			return nullptr;
		}
		ListNode* former = head;
		ListNode* later = head;
		for (int i = 0; i < k; ++i)
		{
			// k不合法时的处理
			if (later == nullptr)
			{
				return nullptr;
			}
			later = later->next;
		}
		// 两个指针一起走
		while (later)
		{
			former = former->next;
			later = later->next;
		}
		return former;
	}
};

// 合并两个排序链表
 /*
class Solution {
public:
	// 递归法
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// 结束的条件
		if(!l1)
		{
			return l2;
		}
		if(!l2)
		{
			return l1;
		}
		// 递归的过程
		if(l1->val<=l2->val)
		{
			l1->next=mergeTwoLists(l1->next,l2);
			return l1;
		}
		else
		{
			l2->next=mergeTwoLists(l1,l2->next);
			return l2;
		}
	}
};
*/

// 遍历法
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// 创建一个哨兵位的头结点
		ListNode* head = new ListNode;
		ListNode* tail = head;
		// 两个链表的每个节点遍历着往后走，找到小节点插到新的排序链表里
		while (l1&&l2)
		{
			if (l1->val <= l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		// 处理最后一段链表，把他整段链到新链表上去
		tail->next = (l1 == nullptr ? l2 : l1);
		return head->next;
	}
};