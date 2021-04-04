#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
//
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	ListNode* pre = NULL;
//	ListNode* cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (cur == head)
//			{
//				cur = cur->next;
//				head = cur;
//				continue;
//			}
//			ListNode* next = cur->next;
//			if (pre)
//			{
//				pre->next = next;
//			}
//			free(cur);
//			cur = next;
//		}
//		else
//		{
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
///*
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//typedef struct ListNode ListNode;
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//	ListNode* slow = head;
//	ListNode* fast = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */

//typedef struct ListNode ListNode;
//
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	if (!pListHead)
//	{
//		return pListHead;
//	}
//	ListNode* slow = pListHead;
//	ListNode* fast = pListHead;
//	while (k--)
//	{
//		if (fast)
//		{
//			fast = fast->next;
//		}
//		else
//		{
//			return NULL;
//		}
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//typedef struct ListNode ListNode;
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL || l2 == NULL)
//	{
//		return l1 == NULL ? l2 : l1;
//	}
//	ListNode* head = NULL;
//	ListNode* tail = head;
//	while (l1&&l2)
//	{
//		if (l1->val < l2->val)
//		{
//			if (!tail)
//			{
//				tail = head = l1;
//				l1 = l1->next;
//				continue;
//			}
//			tail->next = l1;
//			tail = l1;
//			l1 = l1->next;
//		}
//		else
//		{
//			if (!tail)
//			{
//				tail = head = l2;
//				l2 = l2->next;
//				continue;
//			}
//			tail->next = l2;
//			tail = l2;
//			l2 = l2->next;
//		}
//	}
//	if (l1)
//	{
//		tail->next = l1;
//	}
//	else
//	{
//		tail->next = l2;
//	}
//	return head;
//}