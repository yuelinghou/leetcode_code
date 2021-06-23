#define _CRT_SECURE_NO_WARNINGS 1

// �����г��ִ�������һ�������
class Solution {
public:
	// Ħ��ͶƱ��
	// ��ͬ������������
	// ����һ����������
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

// ��һ��ֻ���ֵ�һ�ε��ַ�
class Solution {
public:
	// ����һ��26Сд��ĸ������
	// �����ַ�������ÿ���ַ�ӳ�䵽������
	// �ٴα����ַ���������Ӧ�ַ����ַ����е�Ӱ�����
	// ��һ��Ϊ1�ľ��ǵ�һ��ֻ����һ�ε��ַ�
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

// ��������ĵ�һ�������ڵ�
 // ����һ
 // �������������ĳ���
 // �������������ͬһ���ȵ���㿪ʼ��
 // �������ж������ڵ��Ƿ����
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
	// ������
	// ����ָ��һ���ߣ��ߵ��վ�������һ������
	// �����϶�������
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