#define _CRT_SECURE_NO_WARNINGS 1

// �������������������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
	TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// 1�������жϵ�ǰ�ڵ�Ϊ�ջ��ߵ�ǰ�ڵ����p��q�Ļ������ص�ǰ�ڵ�
		if (!root || root->val == p->val || root->val == q->val)
		{
			return root;
		}
		// 2�������ǰ�ڵ㼴����Ҳ����p��q�Ļ�����������������ȥ��
		TreeNode* leftTree = _lowestCommonAncestor(root->left, p, q);
		TreeNode* rightTree = _lowestCommonAncestor(root->right, p, q);
		// 3����������������ɺ���������
		//     a:����������������ֱ�ӷ������������ҵ��������������
		//     b:����������������ֱ�ӷ������������ҵ��������������
		//     c:�����������ҵ�һ����˵���ýڵ���������������
		if (leftTree && !rightTree)
		{
			return leftTree;
		}
		else if (!leftTree && rightTree)
		{
			return rightTree;
		}
		else if (leftTree && rightTree)
		{
			return root;
		}
		// ʵ�ʲ����ߵ����Ϊ�����㺯�������շ���ֵ��д��
		return nullptr;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		return _lowestCommonAncestor(root, p, q);
	}
};

// �������ľ���
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
	TreeNode* _mirrorTree(TreeNode* root)
	{
		if (!root)
		{
			return nullptr;
		}
		swap(root->left, root->right);
		_mirrorTree(root->left);
		_mirrorTree(root->right);
		return root;
	}

public:
	TreeNode* mirrorTree(TreeNode* root)
	{
		return _mirrorTree(root);
	}
};

// �ԳƵĶ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
	bool _isSymmetric(TreeNode* subL, TreeNode* subR)
	{
		if (subL == nullptr && subR == nullptr)// 1�������ڵ㶼Ϊ��Ҳ��Գ�
		{
			return true;
		}
		else if (subL == nullptr || subR == nullptr)// 2������һ��Ϊ�գ���һ�����գ����Գ�
		{
			return false;
		}
		else if (subL->val != subR->val)// 3�������ڵ㶼���գ���val��һ��Ҳ���Գ�
		{
			return false;
		}
		// 4�������ڵ㶼������val��ȣ������µݹ鿴���ǵĺ����Ƿ�Գ�
		return _isSymmetric(subL->left, subR->right) && _isSymmetric(subL->right, subR->left);
	}
public:
	bool isSymmetric(TreeNode* root)
	{
		return _isSymmetric(root, root);
	}
};