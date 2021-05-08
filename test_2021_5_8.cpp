#define _CRT_SECURE_NO_WARNINGS 1

// 奇偶链表
typedef struct ListNode ListNode;

struct ListNode* oddEvenList(struct ListNode* head)
{
	// 对空链表，只有一个节点，两个节点，三个节点的处理
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return head;
	}
	// 创建奇偶链表，最后把他们合并
	ListNode* odd_head = NULL;
	ListNode* odd_tail = NULL;
	ListNode* even_head = NULL;
	ListNode* even_tail = NULL;
	// 计数器，遍历链表过程中用来区分奇偶节点
	int count = 1;
	// 遍历链表，并处理奇偶链表
	while (head)
	{
		if (count % 2)
		{
			if (!even_head)
			{
				even_head = even_tail = head;
			}
			else
			{
				even_tail->next = head;
				even_tail = head;
			}
		}
		else
		{
			if (!odd_head)
			{
				odd_head = odd_tail = head;
			}
			else
			{
				odd_tail->next = head;
				odd_tail = head;
			}
		}
		++count;
		head = head->next;
	}
	// 连接奇偶链表
	odd_tail->next = NULL;
	even_tail->next = odd_head;
	return even_head;
}

//旋转链表
typedef struct ListNode ListNode;

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	// 空链表，只有一个节点，k为0的处理
	if (!head || !head->next || !k)
	{
		return head;
	}
	// 计算链表长度
	int size = 0;
	ListNode* cur = head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	// 重新计算k的值
	k %= size;
	// 当k为链表长度的整数倍情况的处理
	if (!k)
	{
		return head;
	}
	ListNode* front_part_head = NULL;
	ListNode* frond_part_tail = NULL;
	ListNode* back_part_head = NULL;
	ListNode* back_part_tail = NULL;
	// 遍历原链表
	// 把前size-k个节点拿出来组成一个新链表
	// 把后k个节点拿出来组成另外一个新链表
	// 把前size-k个节点组成的链表拼接到后k个节点组成的链表后
	for (int i = 0; i < size - k; ++i)
	{
		if (!front_part_head)
		{
			front_part_head = frond_part_tail = head;
		}
		else
		{
			frond_part_tail->next = head;
			frond_part_tail = head;
		}
		head = head->next;
	}
	frond_part_tail->next = NULL;// 把最后一个节点的next置为NULL
	for (int i = 0; i < k; ++i)
	{
		if (!back_part_head)
		{
			back_part_head = back_part_tail = head;
		}
		else
		{
			back_part_tail->next = head;
			back_part_tail = head;
		}
		head = head->next;
	}
	// 拼接起来，得到最后的旋转链表
	back_part_tail->next = front_part_head;
	return back_part_head;
}

typedef struct ListNode ListNode;

// 创建新节点
ListNode* BuyNode(int x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

// 两数相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0;   // 进位
	int l1_val = 0;  // l1节点的数
	int l2_val = 0;  // l2节点的数
	int sum = 0;     // 记录每位上相加的和
	ListNode* head = NULL;
	ListNode* tail = NULL;
	// 两个链表对应节点的值相加再加进位
	while (l1 || l2)
	{
		if (l1)
		{
			l1_val = l1->val;
			l1 = l1->next;
		}
		else
		{
			l1_val = 0;
		}
		if (l2)
		{
			l2_val = l2->val;
			l2 = l2->next;
		}
		else
		{
			l2_val = 0;
		}
		sum = l1_val + l2_val + carry;
		carry = 0;
		if (sum > 9)
		{
			sum -= 10;
			carry = 1;
		}
		// 尾插相加之后的节点
		ListNode* tmp = BuyNode(sum);
		if (!head)
		{
			head = tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	// 最后一位后还有进位的话在尾插进位
	if (carry)
	{
		ListNode* tmp = BuyNode(1);
		tail->next = tmp;
	}
	return head;
}

// 回文链表
typedef struct ListNode ListNode;

bool isPalindrome(struct ListNode* head)
{
	// 只有一个节点的处理
	if (head->next == NULL)
	{
		return true;
	}
	ListNode* front_part_head = NULL;
	ListNode* back_part_head = NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	// 遍历链表寻找中间节点，并把前半部分节点头插组成另外一个链表
	while (fast&&fast->next)
	{
		if (!front_part_head)
		{
			front_part_head = slow;
			slow = slow->next;
		}
		else
		{
			ListNode* next_node = slow->next;
			slow->next = front_part_head;
			front_part_head = slow;
			slow = next_node;
		}
		fast = fast->next->next;
	}
	// 确定后部分的头
	if (fast)
	{
		back_part_head = slow->next;
	}
	else
	{
		back_part_head = slow;
	}
	// 把前半部分头插组成的链表和原链表后半部分的val进行比较
	while (back_part_head)
	{
		if (front_part_head->val != back_part_head->val)
		{
			return false;
		}
		front_part_head = front_part_head->next;
		back_part_head = back_part_head->next;
	}
	return true;
}
