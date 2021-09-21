#define _CRT_SECURE_NO_WARNINGS 1

// ���������ֳ��ֵĴ���
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;// ���յķ���ֵ��һ��ʼ����Ϊ0
		// ͳ������Ԫ��32��bitλ��ÿһλ1���ֵĴ���
		// �Ѵ���%3�������0˵��ֻ����һ�ε��Ǹ����ָ�λΪ0���������1����ô��λ����1
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

// ���е����ֵ
class MaxQueue {
private:
	// �����ͨ�Ķ��в���
	queue<int, list<int>> q;
	// �����洢�������ֵ
	list<int> ls;

public:
	MaxQueue()
	{}

	int max_value()
	{
		return ls.empty() == true ? -1 : ls.front();
	}

	// ԭ�������ͷ����δ����ǰ���е����ֵ
	// ����Ҫ�����²���һ������value
	// ���value > ls.front()����������գ��ٲ�������µ�����
	// ���value < ls.front()���������ܾ���֮ǰ��������ȫ����ȥ��Ľ����������ֵ��Ҫ������β�����������ݱȽϡ�
	// ���value == ls.front()��ֱ��β�嵽����
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
