//#define _CRT_SECURE_NO_WARNINGS 1
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//typedef struct ListNode ListNode;
//
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	if (!headA || !headB)
//	{
//		return NULL;
//	}
//	int len1 = 0;
//	int len2 = 0;
//	ListNode* cur1 = headA;
//	ListNode* cur2 = headB;
//	while (cur1)
//	{
//		len1++;
//		cur1 = cur1->next;
//	}
//	while (cur2)
//	{
//		len2++;
//		cur2 = cur2->next;
//	}
//	int len = len1 > len2 ? (len1 - len2) : (len2 - len1);
//	if (len1 > len2)
//	{
//		while (len--)
//		{
//			headA = headA->next;
//		}
//	}
//	else
//	{
//		while (len--)
//		{
//			headB = headB->next;
//		}
//	}
//	while (headA)
//	{
//		if (headA == headB)
//		{
//			return headA;
//		}
//		headA = headA->next;
//		headB = headB->next;
//	}
//	return NULL;
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//typedef struct ListNode ListNode;
//
//bool hasCycle(struct ListNode *head)
//{
//	if (!head)
//	{
//		return false;
//	}
//	ListNode* slow = head;
//	ListNode* fast = head;
//	while (fast)
//	{
//		slow = slow->next;
//		if (fast->next == NULL)
//		{
//			return false;
//		}
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			return true;
//		}
//	}
//	return false;
//}
