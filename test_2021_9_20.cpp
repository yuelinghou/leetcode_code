#define _CRT_SECURE_NO_WARNINGS 1

// 数组中数字出现的次数
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;// 最终的返回值，一开始先置为0
		// 统计数组元素32个bit位中每一位1出现的次数
		// 把次数%3如果等于0说明只出现一次的那个数字该位为0，如果等于1，那么该位就是1
		for (int i = 0; i < 32; ++i)
		{
			int count = 0;
			for (auto& e : nums)
			{
				if (e &  (1 << i))
				{
					++count;
				}
			}
			if (count % 3)
			{
				ret |= (1 << i);
			}
		}
		return ret;
	}
};

// 队列的最大值
class MaxQueue {
private:
	// 完成普通的队列操作
	queue<int, list<int>> q;
	// 用来存储队列最大值
	list<int> ls;

public:
	MaxQueue()
	{}

	int max_value()
	{
		return ls.empty() == true ? -1 : ls.front();
	}

	// 原来链表的头就是未插入前队列的最大值
	// 现在要队列新插入一个数据value
	// 如果value > ls.front()，把链表清空，再插入这个新的数据
	// 如果value < ls.front()，那他可能就是之前队列数据全部出去后的接下来的最大值，要和链表尾部的其他数据比较。
	// 如果value == ls.front()，直接尾插到链表
	void push_back(int value)
	{
		q.push(value);
		if (ls.empty())
		{
			ls.push_back(value);
		}
		else if (value > ls.front())
		{
			ls.clear();
			ls.push_back(value);
		}
		else
		{
			while (ls.back() < value)
			{
				ls.pop_back();
			}
			ls.push_back(value);
		}
	}

	int pop_front()
	{
		if (q.empty())
		{
			return -1;
		}
		int value = q.front();
		q.pop();
		if (value == ls.front())
		{
			ls.pop_front();
		}
		return value;
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
