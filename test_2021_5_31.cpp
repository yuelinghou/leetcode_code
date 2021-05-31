#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isUnivalTree(TreeNode* root)
	{
		// ���ڵ�Ϊ������Ĵ���
		if (!root)
		{
			return true;
		}
		// �����ӣ��������Ӳ����ڸ���val�Ͳ��ǵ�ֵ������
		if (root->left&&root->left->val != root->val)
		{
			return false;
		}
		// ���к��ӣ������к��ӵ�ֵ�����ڸ��Ͳ��ǵ�ֵ������
		if (root->right&&root->right->val != root->val)
		{
			return false;
		}
		// ���õ��ڵĴ����Լ����ݹ���������
		return isUnivalTree(root->left) && isUnivalTree(root->right);
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root)
	{
		// ���ڵ�Ϊ������Ĵ���
		if (!root)
		{
			return 0;
		}
		// ȡ������ȴ���Ǹ������������1���������߶�
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root)
	{
		// ���ڵ�Ϊ�գ��ͷ���nullptr
		if (!root)
		{
			return nullptr;
		}
		// ��ת��������
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// �ݹ鷭ת��������
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

class Solution {
public:
	bool _isSymmetric(TreeNode* leftTree, TreeNode* rightTree)
	{
		// �����������գ���Գ�
		if (!leftTree && !rightTree)
		{
			return true;
		}
		// һ���գ�����һ�����գ����Գ�
		if (!leftTree || !rightTree)
		{
			return false;
		}
		// �����յ������ǵ�ֵ��һ����Ҳ����Գ�
		if (leftTree->val != rightTree->val)
		{
			return false;
		}
		// �����������Ƕ�Ӧ����λ�õ���
		return _isSymmetric(leftTree->left, rightTree->right)
			&& _isSymmetric(leftTree->right, rightTree->left);
	}

	bool isSymmetric(TreeNode* root)
	{
		// 1�������Ļ���Ҳ��Գ�
		if (!root)
		{
			return true;
		}
		// 2���ǿ������ж����������Ƿ�Գ�
		return _isSymmetric(root->left, root->right);
	}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		// ����Ϊ�վ���ͬ
		if (!p && !q)
		{
			return true;
		}
		// ����һ��Ϊ�գ���һ����Ϊ�վͲ���ͬ
		if (!p || !q)
		{
			return false;
		}
		// �����յĻ���val����Ҳ�Ͳ���ͬ
		if (p->val != q->val)
		{
			return false;
		}
		// �����ݹ����ǵ���������������
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

class Solution {
public:
	void _preorderTraversal(TreeNode* root, vector<int>& v)
	{
		// �սڵ�ֱ���˳�
		if (!root)
		{
			return;
		}
		// �ǿո��ڵ��������
		v.push_back(root->val);
		// ���������о�����������
		_preorderTraversal(root->left, v);
		_preorderTraversal(root->right, v);
	}

	vector<int> preorderTraversal(TreeNode* root)
	{
		// ����int���͵�vector����Ϊ��󷵻صĽ��
		vector<int> ret;
		// �����Ļ��ֽڷ��ؿ�vector
		if (!root)
		{
			return ret;
		}
		// �ǿ���ǰ�����
		_preorderTraversal(root, ret);
		return ret;
	}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		// ����Ϊ�վ���ͬ
		if (!p && !q)
		{
			return true;
		}
		// ����һ��Ϊ�գ���һ����Ϊ�վͲ���ͬ
		if (!p || !q)
		{
			return false;
		}
		// �����յĻ���val����Ҳ�Ͳ���ͬ
		if (p->val != q->val)
		{
			return false;
		}
		// �����ݹ����ǵ���������������
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}

	bool isSubtree(TreeNode* root, TreeNode* subRoot)
	{
		// ����ݹ������սڵ�ʱ�Ĵ���
		if (!root)
		{
			return false;
		}
		if (isSameTree(root, subRoot))
		{
			return true;
		}
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
};

class Solution {
public:
	void _inorderTraversal(TreeNode* root, vector<int>& v)
	{
		if (!root)
		{
			return;
		}
		_inorderTraversal(root->left, v);
		v.push_back(root->val);
		_inorderTraversal(root->right, v);
	}

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		if (!root)
		{
			return ret;
		}
		_inorderTraversal(root, ret);
		return ret;
	}
};

class Solution {
public:
	void _postorderTraversal(TreeNode* root, vector<int>& v)
	{
		if (!root)
		{
			return;
		}
		_postorderTraversal(root->left, v);
		_postorderTraversal(root->right, v);
		v.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		if (!root)
		{
			return ret;
		}
		_postorderTraversal(root, ret);
		return ret;
	}
};
