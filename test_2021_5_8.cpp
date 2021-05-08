#define _CRT_SECURE_NO_WARNINGS 1

// ��ż����
typedef struct ListNode ListNode;

struct ListNode* oddEvenList(struct ListNode* head)
{
	// �Կ�����ֻ��һ���ڵ㣬�����ڵ㣬�����ڵ�Ĵ���
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return head;
	}
	// ������ż�����������Ǻϲ�
	ListNode* odd_head = NULL;
	ListNode* odd_tail = NULL;
	ListNode* even_head = NULL;
	ListNode* even_tail = NULL;
	// �������������������������������ż�ڵ�
	int count = 1;
	// ����������������ż����
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
	// ������ż����
	odd_tail->next = NULL;
	even_tail->next = odd_head;
	return even_head;
}

//��ת����
typedef struct ListNode ListNode;

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	// ������ֻ��һ���ڵ㣬kΪ0�Ĵ���
	if (!head || !head->next || !k)
	{
		return head;
	}
	// ����������
	int size = 0;
	ListNode* cur = head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	// ���¼���k��ֵ
	k %= size;
	// ��kΪ�����ȵ�����������Ĵ���
	if (!k)
	{
		return head;
	}
	ListNode* front_part_head = NULL;
	ListNode* frond_part_tail = NULL;
	ListNode* back_part_head = NULL;
	ListNode* back_part_tail = NULL;
	// ����ԭ����
	// ��ǰsize-k���ڵ��ó������һ��������
	// �Ѻ�k���ڵ��ó����������һ��������
	// ��ǰsize-k���ڵ���ɵ�����ƴ�ӵ���k���ڵ���ɵ������
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
	frond_part_tail->next = NULL;// �����һ���ڵ��next��ΪNULL
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
	// ƴ���������õ�������ת����
	back_part_tail->next = front_part_head;
	return back_part_head;
}

typedef struct ListNode ListNode;

// �����½ڵ�
ListNode* BuyNode(int x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

// �������
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int carry = 0;   // ��λ
	int l1_val = 0;  // l1�ڵ����
	int l2_val = 0;  // l2�ڵ����
	int sum = 0;     // ��¼ÿλ����ӵĺ�
	ListNode* head = NULL;
	ListNode* tail = NULL;
	// ���������Ӧ�ڵ��ֵ����ټӽ�λ
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
		// β�����֮��Ľڵ�
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
	// ���һλ���н�λ�Ļ���β���λ
	if (carry)
	{
		ListNode* tmp = BuyNode(1);
		tail->next = tmp;
	}
	return head;
}

// ��������
typedef struct ListNode ListNode;

bool isPalindrome(struct ListNode* head)
{
	// ֻ��һ���ڵ�Ĵ���
	if (head->next == NULL)
	{
		return true;
	}
	ListNode* front_part_head = NULL;
	ListNode* back_part_head = NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	// ��������Ѱ���м�ڵ㣬����ǰ�벿�ֽڵ�ͷ���������һ������
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
	// ȷ���󲿷ֵ�ͷ
	if (fast)
	{
		back_part_head = slow->next;
	}
	else
	{
		back_part_head = slow;
	}
	// ��ǰ�벿��ͷ����ɵ������ԭ�����벿�ֵ�val���бȽ�
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
