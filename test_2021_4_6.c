#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//typedef struct ListNode ListNode;
//
//struct ListNode *detectCycle(struct ListNode *head)
//{
//	ListNode* slow = head;
//	ListNode* fast = head;
//	while (fast&&fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			ListNode* meet = slow;
//			while (1)
//			{
//				if (head == meet)
//				{
//					return head;
//				}
//				head = head->next;
//				meet = meet->next;
//			}
//		}
//	}
//	return NULL;
//}

//bool isValid(char * s)
//{
//	char* bracket[3] = { "()","{}","[]" };
//	Stack d;
//	StackInit(&d);
//	while (*s)
//	{
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			StackPush(&d, *s);
//		}
//		else
//		{
//			if (StackEmpty(&d))
//			{
//				return false;
//			}
//			for (int i = 0; i < 3; i++)
//			{
//				if (*s == bracket[i][1] && StackTop(&d) != bracket[i][0])
//				{
//					return false;
//				}
//			}
//			StackPop(&d);
//		}
//		s++;
//	}
//	if (StackEmpty(&d))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}