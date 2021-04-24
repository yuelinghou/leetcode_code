#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//链表节点声明
typedef struct MyLinkedList
{
	int val;//数据域
	struct MyLinkedList* next;//指针域
} MyLinkedList;

//创建头结点
/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
	MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	obj->next = NULL;
	return obj;
}

//得到index位置的值
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
	//下标小于0和空链表情况的处理（非法）
	if (index < 0 || obj->next == NULL)
	{
		return -1;
	}
	MyLinkedList* cur = obj->next;
	int n = 0;
	//从下标为0开始遍历链表
	while (cur)
	{
		//对应节点的下标和index相等就找到了
		if (n == index)
		{
			return cur->val;
		}
		//不是的话继续找下一个下标的节点
		n++;
		cur = cur->next;
	}
	return -1;
}

//头插
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
	//创建新节点
	MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	newnode->val = val;
	newnode->next = obj->next;//新节点的next指向原链表第一个节点的位置
	//把新节点作为链表的第一个节点
	obj->next = newnode;
}

//尾插
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
	//创建新节点
	MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	newnode->val = val;
	newnode->next = NULL;
	//遍历链表
	MyLinkedList* cur = obj->next;
	if (cur)//链表不为空的情况
	{
		//找尾节点
		while (cur->next)
		{
			cur = cur->next;
		}
		//尾插操作
		cur->next = newnode;
	}
	else//链表为空的情况
	{
		//相当于头插
		obj->next = newnode;
	}
}

//在index位置前添加新节点
/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
	//下标小于0情况的处理（头插）
	if (index <= 0)
	{
		myLinkedListAddAtHead(obj, val);
		return;
	}
	MyLinkedList* cur = obj->next;
	int length = 0;
	//求链表长度
	while (cur)
	{
		++length;
		cur = cur->next;
	}
	//下标和链表长度相等时情况的处理（尾插）
	if (index == length)
	{
		myLinkedListAddAtTail(obj, val);
		return;
	}
	//下标大于链表长度情况的处理（非法）
	else if (index > length)
	{
		return;
	}
	else//下标大于0和小于链表长度情况的处理（中间插）
	{
		//创建新节点
		MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
		newnode->val = val;
		newnode->next = NULL;
		cur = obj->next;
		int n = 0;
		//遍历链表，找到index-1位置的节点，在该节点后面插入新节点
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

//删除index位置的节点
/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
	//链表为空和index小于0情况的处理（非法）
	if (obj->next == NULL || index < 0)
	{
		return;
	}
	int n = 0;//记录节点的下标
	MyLinkedList* cur = obj->next;
	MyLinkedList* prev = cur;
	//遍历链表
	while (cur)
	{
		//找到对应下标的节点
		if (n == index)
		{
			//如果是删除第一个节点的情况
			if (!n)
			{
				MyLinkedList* tmp = cur->next;
				free(cur);
				cur = prev = NULL;
				//把头结点和原链表的第二个节点连接
				obj->next = tmp;
				return;
			}
			//删除的不是第一个节点的情况
			//把前面节点连接起来，在删除当前节点
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

//释放链表
void myLinkedListFree(MyLinkedList* obj)
{
	//遍历链表，把节点逐个删除
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
	//定义快慢指针
	ListNode* slow = head;
	ListNode* fast = head;
	//定义slow前一个节点的指针
	ListNode* prev = slow;
	//快指针先走n步
	while (n--)
	{
		fast = fast->next;
	}
	////当快指针指向NULL是，慢指针指向的节点就是倒数第n和节点
	while (fast != NULL)
	{
		//快慢指针各走一步
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	//删除节点，并连接前节点
	if (slow == head)// 1.删除的是头结点（把原链表的第二个节点设为第一个节点）
	{
		head = slow->next;
	}
	else// 2.删除的不是头结点（连接前后节点）
	{
		prev->next = slow->next;
	}
	//删除倒数第n个节点
	free(slow);
	return head;
}
