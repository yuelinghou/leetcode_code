#define _CRT_SECURE_NO_WARNINGS 1

// ������II
class Solution {
public:
	int cuttingRope(int n)
	{
		if (n < 4)
		{
			return n - 1;
		}
		long ret = 1;
		while (n > 4)
		{
			ret = (ret * 3 % 1000000007);
			n -= 3;
		}
		ret = ret * n % 1000000007;
		return (int)ret;
	}
};

// ��ת�ַ���II
class Solution {
public:
	string reverseStr(string s, int k)
	{
		int begin = 0;
		int n = s.size();
		// ������߽���ڣ��ſ��Է�ת
		while (begin < n)
		{
			int end = min(begin + k - 1, n - 1);// �õ���ת������ұ߽�
			reverse(s.begin() + begin, s.begin() + end + 1);
			begin += 2 * k;// ������߽�
		}
		return s;
	}
};

// ����������
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
	// prevIҪ�����ã������������ĸ��ڵ㣬�ڵݹ鴴�������������Ҫ��������ֵ������������
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prevI, int inBegin, int inEnd)
	{
		// û������Ҳ��û�нڵ�
		if (inBegin > inEnd)
		{
			return nullptr;
		}
		// �������ڵ�
		TreeNode* root = new TreeNode(preorder[prevI]);
		// ���������ҵ�����val
		int inI = inBegin;
		while (inorder[inI] != preorder[prevI])
		{
			++inI;
		}
		// ����������
		if (inBegin <= inI - 1)
		{
			root->left = _buildTree(preorder, inorder, ++prevI, inBegin, inI - 1);
		}
		else
		{
			root->left = nullptr;
		}
		// ����������
		if (inI + 1 <= inEnd)
		{
			root->right = _buildTree(preorder, inorder, ++prevI, inI + 1, inEnd);
		}
		else
		{
			root->right = nullptr;
		}
		// ���ظ�
		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int prevI = 0;// ���ڵ��val
		return _buildTree(preorder, inorder, prevI, 0, inorder.size() - 1);
	}
};
