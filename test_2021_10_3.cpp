#define _CRT_SECURE_NO_WARNINGS 1

// ��ǰ�����������й��������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
	unordered_map<int, int> inIndex;

	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd)
	{
		if (preBegin > preEnd)
		{
			return nullptr;
		}
		// 1��ǰ������ĵ�һ�����Ǹ��ڵ�
		TreeNode* root = new TreeNode(preorder[preBegin]);
		// 2���ҵ���������и��ڵ�����λ�ã���������������ĳ���
		int rootOfInorder = inIndex[root->val];
		int leftLength = rootOfInorder - inBegin;
		// 3��ͨ���������ĳ��ȶ�������л��֣�������������
		root->left = _buildTree(preorder, inorder, preBegin + 1, preBegin + leftLength, inBegin, rootOfInorder - 1);
		root->right = _buildTree(preorder, inorder, preBegin + leftLength + 1, preEnd, rootOfInorder + 1, inEnd);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		// ӳ����������нڵ����ݶ�Ӧ��������±�
		for (int i = 0; i < inorder.size(); ++i)
		{
			inIndex[inorder[i]] = i;
		}
		return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};

// �����������������й��������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
	unordered_map<int, int> inIndex;

	TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd)
	{
		// 1������û�нڵ��˾ͷ��ؿ�
		if (postBegin > postEnd)
		{
			return nullptr;
		}
		// 2����������һ��ֵ���Ǹ��ڵ�
		TreeNode* root = new TreeNode(postorder[postEnd]);
		// 3���õ������и��ڵ����ڵ��±�
		int rootOfInorder = inIndex[root->val];
		// 4��ȷ���������ĳ���
		int leftLength = rootOfInorder - inBegin;
		// 5�������������ĳ��ȶ�����������л��֣��ݹ鹹����������
		root->left = _buildTree(inorder, postorder, inBegin, rootOfInorder - 1, postBegin, postBegin + leftLength - 1);
		root->right = _buildTree(inorder, postorder, rootOfInorder + 1, inEnd, postBegin + leftLength, postEnd - 1);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		// ӳ����������нڵ��ֵ�����Ӧ���±�
		for (int i = 0; i < inorder.size(); ++i)
		{
			inIndex[inorder[i]] = i;
		}
		return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
};

// ����ǰ��ͺ���������������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
	unordered_map<int, int> postIndex;

	TreeNode* _constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int preBegin, int preEnd, int postBegin, int postEnd)
	{
		// 1���������û��Ԫ���ˣ��ͷ��ؿ�
		if (preBegin > preEnd)
		{
			return nullptr;
		}
		// 2��ǰ��ĵ�һ��Ԫ�ؾ��Ǹ��ڵ��ֵ���������ڵ�
		TreeNode* root = new TreeNode(preorder[preBegin]);
		// ע�����ֻ��һ��Ԫ���ˣ�����Ҫ���ھͽ��������ظոմ����ĸ��ڵ�
		// ��Ϊ����������Ҫ���������ĸ��ڵ㣺preBegin + 1
		// ��ʱ��������ػ�Խ��
		if (preBegin == preEnd)
		{
			return root;
		}
		// 3����¼�ں������������ĸ����ڵ��±�
		int leftRootOfPost = postIndex[preorder[preBegin + 1]];
		// 4����¼����������
		int leftLength = leftRootOfPost - postBegin + 1;
		// 5���������������ȶ�����������з��飬�ݹ鹹����������
		root->left = _constructFromPrePost(preorder, postorder, preBegin + 1, preBegin + leftLength, postBegin, postBegin + leftLength - 1);
		root->right = _constructFromPrePost(preorder, postorder, preBegin + leftLength + 1, preEnd, postBegin + leftLength, postEnd - 1);
		return root;
	}

public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
	{
		// 1��ӳ������нڵ��ֵ���±�
		for (int i = 0; i < postorder.size(); ++i)
		{
			postIndex[postorder[i]] = i;
		}
		return _constructFromPrePost(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
	}
};
