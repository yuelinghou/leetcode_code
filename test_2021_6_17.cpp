#define _CRT_SECURE_NO_WARNINGS 1

// ���ݶ����������ַ���
class Solution {
public:
	string tree2str(TreeNode* root)
	{
		string s;
		// �����ͷ��ؿմ�
		if (!root)
		{
			return s;
		}
		// 1���ȰѸ��ڵ��ֵ�ӵ��ַ�����
		s += to_string(root->val);
		// 2���������ӵ��ַ�����
		if (root->left)
		{
			s += '(';
			s += tree2str(root->left);
			s += ')';
		}
		else if (root->right)// ע���������Ϊ����������Ϊ�գ�������ǰҪ�Ӹ���������
		{
			s += "()";
		}

		// 3���������ӵ��ַ�����
		if (root->right)
		{
			s += '(';
			s += tree2str(root->right);
			s += ')';
		}
		return s;
	}
};

// �������Ĳ������I
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> vv;
		// �����Ļ��ͷ��ؿն�ά����
		if (!root)
		{
			return vv;
		}
		queue<TreeNode*> q;
		// �ȰѸ��ڵ������
		q.push(root);
		while (!q.empty())
		{
			// ��¼��ǰ���ж��ٸ��ڵ�
			int levelSize = q.size();
			// �洢��ǰ��Ľڵ������
			vector<int> v;
			// �ѵ�ǰ��ڵ���������ηŵ�v����ýڵ������
			// ��ǰ������ˣ�Ҳ����forѭ����������һ��Ľڵ�Ҳȫ�������
			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			// �ѵ�ǰ��ڵ�����ݼӵ�vv��
			vv.push_back(v);
		}
		return vv;
	}
};

// �������Ĳ������II
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> vv;
		// �����Ļ��ͷ��ؿն�ά����
		if (!root)
		{
			return vv;
		}
		queue<TreeNode*> q;
		// �ȰѸ��ڵ������
		q.push(root);
		while (!q.empty())
		{
			// ��¼��ǰ���ж��ٸ��ڵ�
			int levelSize = q.size();
			// �洢��ǰ��Ľڵ������
			vector<int> v;
			// �ѵ�ǰ��ڵ���������ηŵ�v����ýڵ������
			// ��ǰ������ˣ�Ҳ����forѭ����������һ��Ľڵ�Ҳȫ�������
			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			// �ѵ�ǰ��ڵ�����ݼӵ�vv��
			vv.push_back(v);
		}
		// ��reverse��תvv���õ��ľ��ǵ���ı���
		reverse(vv.begin(), vv.end());
		return vv;
	}
};
