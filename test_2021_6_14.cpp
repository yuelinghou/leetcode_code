#define _CRT_SECURE_NO_WARNINGS 1

// ��ת����
class Solution {
public:
	// ����ÿ���ڵ㣬�õ�ǰ�ڵ��nextָ��ǰһ���ڵ�
	ListNode* reverseList(ListNode* head)
	{
		// ���������ֻ��һ���ڵ������Ͳ�����ת��
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = head->next;
		while (cur)
		{
			// Ȼ��ǰ�ڵ��nextָ��ǰһ���ڵ�
			cur->next = prev;
			// ����������
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

// �����е�����k���ڵ�
class Solution {
public:
	// ��ָ������k����֮������ָ��һ����
	// ��ָ�뵽nullptrʱ����ָ��ָ��Ľڵ㼴Ϊ������k���ڵ�
	ListNode* getKthFromEnd(ListNode* head, int k)
	{
		// �������k���Ϸ�ʱ�Ĵ���
		if (head == nullptr || k <= 0)
		{
			return nullptr;
		}
		ListNode* former = head;
		ListNode* later = head;
		for (int i = 0; i < k; ++i)
		{
			// k���Ϸ�ʱ�Ĵ���
			if (later == nullptr)
			{
				return nullptr;
			}
			later = later->next;
		}
		// ����ָ��һ����
		while (later)
		{
			former = former->next;
			later = later->next;
		}
		return former;
	}
};

// �ϲ�������������
 /*
class Solution {
public:
	// �ݹ鷨
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// ����������
		if(!l1)
		{
			return l2;
		}
		if(!l2)
		{
			return l1;
		}
		// �ݹ�Ĺ���
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

// ������
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// ����һ���ڱ�λ��ͷ���
		ListNode* head = new ListNode;
		ListNode* tail = head;
		// ���������ÿ���ڵ�����������ߣ��ҵ�С�ڵ�嵽�µ�����������
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
		// �������һ��������������������������ȥ
		tail->next = (l1 == nullptr ? l2 : l1);
		return head->next;
	}
};