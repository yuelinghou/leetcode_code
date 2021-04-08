#define _CRT_SECURE_NO_WARNINGS 1
//
////头文件的声明
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
////节点存储的数据类型
//typedef int QDataType;
//
//// 链式结构：表示队列
//typedef struct QListNode
//{
//	struct QListNode* _pnext;
//	QDataType _data;
//}QNode;
//
//// 队列的结构
//typedef struct Queue
//{
//	QNode* _head;
//	QNode* _tail;
//}Queue;
//
//// 初始化队列
//void QueueInit(Queue* q)
//{
//	//断言，保证指针的有效性
//	assert(q);
//	//把指向第一个和最后一个节点的指针初始化为NULL
//	q->_head = q->_tail = NULL;
//}
//
//// 队尾入队列
//void QueuePush(Queue* q, QDataType data)
//{
//	assert(q);
//	//新开辟一个新的节点
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	//对新的节点初始化
//	newnode->_data = data;
//	newnode->_pnext = NULL;
//	//1.队列没有节点的情况
//	if (q->_tail == NULL)
//	{
//		q->_head = q->_tail = newnode;
//	}
//	else//2.队列已经有节点的情况
//	{
//		q->_tail->_pnext = newnode;
//		q->_tail = newnode;
//	}
//}
//
//// 队头出队列
//void QueuePop(Queue* q)
//{
//	assert(q);
//	//1.队列只有一个节点的情况
//	//释放了空间后还要把原来指向第一个和最后一个节点的指针置为NULL
//	if (q->_head->_pnext == NULL)
//	{
//		free(q->_head);
//		q->_head = q->_tail = NULL;
//	}
//	//2.队列至少一个节点的情况
//	else
//	{
//		//释放第一个节点前要保留第二个节点的地址
//		QNode* next = q->_head->_pnext;
//		//释放第一个节点
//		free(q->_head);
//		//之前的第二个节点变为第一个节点
//		q->_head = next;
//	}
//}
//
//// 获取队列头部元素
//QDataType QueueFront(Queue* q)
//{
//	assert(q);
//	return q->_head->_data;
//}
//
//// 获取队列队尾元素
//QDataType QueueBack(Queue* q)
//{
//	assert(q);
//	return q->_tail->_data;
//}
//
//// 获取队列中有效元素个数
//int QueueSize(Queue* q)
//{
//	assert(q);
//	QNode* cur = q->_head;
//	int n = 0;
//	//遍历队列
//	while (cur)
//	{
//		n++;
//		cur = cur->_pnext;
//	}
//	return n;
//}
//
//// 检测队列是否为空，如果为空返回1，如果非空返回0
//int QueueEmpty(Queue* q)
//{
//	assert(q);
//	return q->_head == NULL ? 1 : 0;
//}
//
//// 销毁队列
//void QueueDestroy(Queue* q)
//{
//	assert(q);
//	QNode* cur = q->_head;
//	//遍历队列
//	while (cur)
//	{
//		//销毁之前保留后一个节点的地址
//		QNode* next = cur->_pnext;
//		free(cur);
//		cur = next;
//	}
//	//防止野指针
//	q->_head = q->_tail = NULL;
//}
//
//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//
///** Initialize your data structure here. */
//
//MyStack* myStackCreate()
//{
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//	return obj;
//}
//
///** Push element x onto stack. */
//void myStackPush(MyStack* obj, int x)
//{
//	if (QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q2, x);
//	}
//	else
//	{
//		QueuePush(&obj->q1, x);
//	}
//}
//
///** Removes the element on top of the stack and returns that element. */
//int myStackPop(MyStack* obj)
//{
//	Queue* isempty = &obj->q1;
//	Queue* noempty = &obj->q2;
//	if (QueueEmpty(&obj->q2))
//	{
//		isempty = &obj->q2;
//		noempty = &obj->q1;
//	}
//	while (QueueSize(noempty) > 1)
//	{
//		QueuePush(isempty, QueueFront(noempty));
//		QueuePop(noempty);
//	}
//	int tmp = QueueBack(noempty);
//	QueuePop(noempty);
//	return tmp;
//}
//
///** Get the top element. */
//int myStackTop(MyStack* obj)
//{
//	Queue* isempty = &obj->q1;
//	Queue* noempty = &obj->q2;
//	if (QueueEmpty(&obj->q2))
//	{
//		isempty = &obj->q2;
//		noempty = &obj->q1;
//	}
//	return QueueBack(noempty);
//}
//
///** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj)
//{
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
//
//typedef int STDataType;
//
//// 栈的声明
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top; // 栈顶
//	int _capacity; // 容量
//}Stack;
//
//// 初始化栈
//void StackInit(Stack* ps)
//{
//	//断言，保证指针的有效性
//	assert(ps);
//	ps->_a = NULL;
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//
//// 入栈
//void StackPush(Stack* ps, STDataType data)
//{
//	assert(ps);
//	// 入栈之前判断容量是否满了
//	if (ps->_capacity == ps->_top)
//	{
//		int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
//		STDataType* tmp = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
//		//判断是否成功开辟空间
//		if (!tmp)
//		{
//			printf("Realloc Fail!\n");
//			exit(-1);
//		}
//		ps->_a = tmp;
//		ps->_capacity = newcapacity;
//	}
//	ps->_a[ps->_top++] = data;
//}
//
//// 出栈
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	ps->_top--;
//}
//
//// 获取栈顶元素
//STDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	return ps->_a[ps->_top - 1];
//}
//
//// 获取栈中有效元素个数
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->_top;
//}
//
//// 检测栈是否为空，如果为空返回1，如果不为空返回0
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top == 0 ? 1 : 0;
//}
//
//// 销毁栈
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	//释放空间之前先判断是否开辟了空间
//	if (ps->_a != NULL)
//	{
//		free(ps->_a);
//		ps->_a = NULL;
//	}
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//
//
//typedef struct
//{
//	Stack pushst;
//	Stack popst;
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate()
//{
//	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&q->pushst);
//	StackInit(&q->popst);
//	return q;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x)
//{
//	StackPush(&obj->pushst, x);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj)
//{
//	if (!StackSize(&obj->popst))
//	{
//		while (!StackEmpty(&obj->pushst))
//		{
//			StackPush(&obj->popst, StackTop(&obj->pushst));
//			StackPop(&obj->pushst);
//		}
//	}
//	int tmp = StackTop(&obj->popst);
//	StackPop(&obj->popst);
//	return tmp;
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj)
//{
//	if (!StackSize(&obj->popst))
//	{
//		while (!StackEmpty(&obj->pushst))
//		{
//			StackPush(&obj->popst, StackTop(&obj->pushst));
//			StackPop(&obj->pushst);
//		}
//	}
//	return StackTop(&obj->popst);
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj)
//{
//	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
//}
//
//void myQueueFree(MyQueue* obj)
//{
//	StackDestroy(&obj->pushst);
//	StackDestroy(&obj->popst);
//	free(obj);
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/

//typedef struct
//{
//	int* a;
//	int n;
//	int front;
//	int rear;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	cq->a = (int*)malloc(sizeof(int)*(k + 1));
//	cq->n = k + 1;
//	cq->front = 0;
//	cq->rear = 0;
//	return cq;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	return obj->front == obj->rear;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	return obj->front == ((obj->rear + 1) % obj->n);
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	if (myCircularQueueIsFull(obj))
//	{
//		return false;
//	}
//	obj->a[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % obj->n;
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return false;
//	}
//	obj->front = (obj->front + 1) % obj->n;
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	return obj->a[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	int rear_flag = obj->rear - 1;
//	if (!(obj->rear))
//	{
//		rear_flag = obj->n - 1;
//	}
//	return obj->a[rear_flag];
//}
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->a);
//	free(obj);
//}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
