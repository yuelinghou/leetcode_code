#define _CRT_SECURE_NO_WARNINGS 1

// �����������
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
	int maxDepth(TreeNode* root)
	{
		// �ݹ����������������߶�Ϊ0
		if (root == nullptr)
		{
			return 0;
		}
		// ���յĻ������Լ�����һ���߶ȣ��ټ������������и��ߵ��ǿ����ĸ߶Ⱦ���������ĸ߶�
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
