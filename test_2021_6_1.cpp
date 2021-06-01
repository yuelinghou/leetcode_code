#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool _isBalanced(TreeNode* root, int& i)
	{
		// ����Ҳ��ƽ�������
		if (!root)
		{
			++i;
			return true;
		}
		// �ж��������ǲ���ƽ�������
		int lefthigh = 0;
		if (!_isBalanced(root->left, lefthigh))
		{
			return false;
		}
		// �ж��������ǲ���ƽ�������
		int rightgigh = 0;
		if (!_isBalanced(root->right, rightgigh))
		{
			return false;
		}
		// �ѵ�ǰ���ĸ߶ȷ���
		i = max(lefthigh, rightgigh) + 1;
		// �жϵ�ǰ���Ƿ���ƽ�������
		return abs(lefthigh - rightgigh) <= 1;
	}

	bool isBalanced(TreeNode* root)
	{
		int i = 0;
		return _isBalanced(root, i);
	}
};
