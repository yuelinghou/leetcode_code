#define _CRT_SECURE_NO_WARNINGS 1

// �������е��ƶ�ƽ��ֵ
class MovingAverage
{
private:
	queue<int> _q;
	int _curSize;
	int _allSize;
	int _sum;

public:
	MovingAverage(int size)
		:_curSize(0)
		, _allSize(size)
		, _sum(0)
	{}

	double next(int val)
	{
		_q.push(val);
		_sum += val;
		++_curSize;
		if (_curSize > _allSize)
		{
			_sum -= _q.front();
			_q.pop();
			--_curSize;
		}
		return (double)_sum / _curSize;
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

// ���ѭ������
class MyCircularQueue
{
private:
	vector<int> _q;
	int _allSize;
	int _head;
	int _tail;

public:
	MyCircularQueue(int k)
		:_q(k + 1)
		, _allSize(k + 1)
		, _head(0)
		, _tail(0)
	{}

	bool enQueue(int value)
	{
		if (isFull())
		{
			return false;
		}
		_q[_tail] = value;
		_tail = (_tail + 1) % _allSize;
		return true;
	}

	bool deQueue()
	{
		if (isEmpty())
		{
			return false;
		}
		_head = (_head + 1) % _allSize;
		return true;
	}

	int Front()
	{
		if (isEmpty())
		{
			return -1;
		}
		return _q[_head];
	}

	int Rear()
	{
		if (isEmpty())
		{
			return -1;
		}
		int prevTail = _tail - 1;
		if (!(_tail))
		{
			prevTail = _allSize - 1;
		}
		return _q[prevTail];
	}

	bool isEmpty()
	{
		return _head == _tail;
	}

	bool isFull()
	{
		return (_tail + 1) % _allSize == _head;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// �����������л��ͷ����л�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		// ǰ������ķ�ʽ���л�������
		// Ϊ����Ϸ����л��������ڵ��ֵ֮���ÿո�ָ�
		if (root == nullptr)
		{
			return "nullptr";
		}
		return to_string(root->val) +
			' ' + serialize(root->left) +
			' ' + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* _deserialize(istringstream& ss)
	{
		// ǰ�������ԭ������
		string tmp;
		ss >> tmp;// ss�൱��һ�������������ÿ������������Կո���
		if (tmp == "nullptr")
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(tmp));
		root->left = _deserialize(ss);
		root->right = _deserialize(ss);
		return root;
	}

	TreeNode* deserialize(string data)
	{
		// �����л����ַ�������ʼ��һ��istringstream����
		istringstream ss(data);
		return _deserialize(ss);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
