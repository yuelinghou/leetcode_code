#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//����ڵ�����
typedef struct MyLinkedList
{
	int val;//������
	struct MyLinkedList* next;//ָ����
} MyLinkedList;

//����ͷ���
/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
	MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	obj->next = NULL;
	return obj;
}

//�õ�indexλ�õ�ֵ
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
	//�±�С��0�Ϳ���������Ĵ����Ƿ���
	if (index < 0 || obj->next == NULL)
	{
		return -1;
	}
	MyLinkedList* cur = obj->next;
	int n = 0;
	//���±�Ϊ0��ʼ��������
	while (cur)
	{
		//��Ӧ�ڵ���±��index��Ⱦ��ҵ���
		if (n == index)
		{
			return cur->val;
		}
		//���ǵĻ���������һ���±�Ľڵ�
		n++;
		cur = cur->next;
	}
	return -1;
}

//ͷ��
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
	//�����½ڵ�
	MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	newnode->val = val;
	newnode->next = obj->next;//�½ڵ��nextָ��ԭ�����һ���ڵ��λ��
	//���½ڵ���Ϊ����ĵ�һ���ڵ�
	obj->next = newnode;
}

//β��
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
	//�����½ڵ�
	MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	newnode->val = val;
	newnode->next = NULL;
	//��������
	MyLinkedList* cur = obj->next;
	if (cur)//����Ϊ�յ����
	{
		//��β�ڵ�
		while (cur->next)
		{
			cur = cur->next;
		}
		//β�����
		cur->next = newnode;
	}
	else//����Ϊ�յ����
	{
		//�൱��ͷ��
		obj->next = newnode;
	}
}

//��indexλ��ǰ����½ڵ�
/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
	//�±�С��0����Ĵ���ͷ�壩
	if (index <= 0)
	{
		myLinkedListAddAtHead(obj, val);
		return;
	}
	MyLinkedList* cur = obj->next;
	int length = 0;
	//��������
	while (cur)
	{
		++length;
		cur = cur->next;
	}
	//�±�����������ʱ����Ĵ���β�壩
	if (index == length)
	{
		myLinkedListAddAtTail(obj, val);
		return;
	}
	//�±��������������Ĵ����Ƿ���
	else if (index > length)
	{
		return;
	}
	else//�±����0��С������������Ĵ����м�壩
	{
		//�����½ڵ�
		MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
		newnode->val = val;
		newnode->next = NULL;
		cur = obj->next;
		int n = 0;
		//���������ҵ�index-1λ�õĽڵ㣬�ڸýڵ��������½ڵ�
		while (cur)
		{
			if (n == index - 1)
			{
				newnode->next = cur->next;
				cur->next = newnode;
				return;
			}
			++n;
			cur = cur->next;
		}
	}
}

//ɾ��indexλ�õĽڵ�
/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
	//����Ϊ�պ�indexС��0����Ĵ����Ƿ���
	if (obj->next == NULL || index < 0)
	{
		return;
	}
	int n = 0;//��¼�ڵ���±�
	MyLinkedList* cur = obj->next;
	MyLinkedList* prev = cur;
	//��������
	while (cur)
	{
		//�ҵ���Ӧ�±�Ľڵ�
		if (n == index)
		{
			//�����ɾ����һ���ڵ�����
			if (!n)
			{
				MyLinkedList* tmp = cur->next;
				free(cur);
				cur = prev = NULL;
				//��ͷ����ԭ����ĵڶ����ڵ�����
				obj->next = tmp;
				return;
			}
			//ɾ���Ĳ��ǵ�һ���ڵ�����
			//��ǰ��ڵ�������������ɾ����ǰ�ڵ�
			prev->next = cur->next;
			free(cur);
			prev = cur = NULL;
			return ;
		}
		++n;
		prev = cur;
		cur = cur->next;
	}
}

//�ͷ�����
void myLinkedListFree(MyLinkedList* obj)
{
	//���������ѽڵ����ɾ��
	while (obj)
	{
		MyLinkedList* tmp = obj->next;
		free(obj);
		obj = tmp;
	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	//�������ָ��
	ListNode* slow = head;
	ListNode* fast = head;
	//����slowǰһ���ڵ��ָ��
	ListNode* prev = slow;
	//��ָ������n��
	while (n--)
	{
		fast = fast->next;
	}
	////����ָ��ָ��NULL�ǣ���ָ��ָ��Ľڵ���ǵ�����n�ͽڵ�
	while (fast != NULL)
	{
		//����ָ�����һ��
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	//ɾ���ڵ㣬������ǰ�ڵ�
	if (slow == head)// 1.ɾ������ͷ��㣨��ԭ����ĵڶ����ڵ���Ϊ��һ���ڵ㣩
	{
		head = slow->next;
	}
	else// 2.ɾ���Ĳ���ͷ��㣨����ǰ��ڵ㣩
	{
		prev->next = slow->next;
	}
	//ɾ��������n���ڵ�
	free(slow);
	return head;
}
