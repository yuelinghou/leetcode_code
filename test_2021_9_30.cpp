#define _CRT_SECURE_NO_WARNINGS 1

// ƽ�������
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
	bool _isBalanced(TreeNode* root, int& high)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHigh = 0;
		int rightHigh = 0;
		bool bLeft = _isBalanced(root->left, leftHigh);
		bool bRight = _isBalanced(root->right, rightHigh);
		high = max(leftHigh, rightHigh) + 1;// ���¸����׽ڵ�����ĸ߶�
		return bLeft && bRight && abs(leftHigh - rightHigh) < 2;// ���ظ����׽ڵ㣬�����Ƿ���ƽ����
	}

public:
	bool isBalanced(TreeNode* root)
	{
		// 1�����ڵ�Ϊ��Ҳ��ƽ����
		if (root == nullptr)
		{
			return true;
		}
		// 2�����ڵ㲻Ϊ�գ��������������������¼���������ĸ߶�
		int leftHigh = 0;
		int rightHigh = 0;
		return _isBalanced(root->left, leftHigh)
			&& _isBalanced(root->right, rightHigh)
			&& abs(leftHigh - rightHigh) < 2;
	}
};
