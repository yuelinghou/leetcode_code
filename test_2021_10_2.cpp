#define _CRT_SECURE_NO_WARNINGS 1

// �����������ĵ�k��ڵ�
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
	int ret = 0;

	void _InOrder(TreeNode* root, int k, int& count)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->right, k, count);
		++count;
		// �ҵ��ˣ���ֵ��ret��Ϳ���ֱ���˳���
		if (count == k)
		{
			ret = root->val;
			return;
		}
		_InOrder(root->left, k, count);
	}
public:
	int kthLargest(TreeNode* root, int k)
	{
		int count = 0;
		_InOrder(root, k, count);
		return ret;
	}
};
