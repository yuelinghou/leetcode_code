#define _CRT_SECURE_NO_WARNINGS 1

// 从前序与中序序列构造二叉树
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
		// 1、前序遍历的第一个就是根节点
		TreeNode* root = new TreeNode(preorder[preBegin]);
		// 2、找到中序遍历中根节点所在位置，并计算出左子树的长度
		int rootOfInorder = inIndex[root->val];
		int leftLength = rootOfInorder - inBegin;
		// 3、通过左子树的长度对数组进行划分，构造左右子树
		root->left = _buildTree(preorder, inorder, preBegin + 1, preBegin + leftLength, inBegin, rootOfInorder - 1);
		root->right = _buildTree(preorder, inorder, preBegin + leftLength + 1, preEnd, rootOfInorder + 1, inEnd);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		// 映射中序遍历中节点数据对应的数组的下标
		for (int i = 0; i < inorder.size(); ++i)
		{
			inIndex[inorder[i]] = i;
		}
		return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};

// 从中序与后序遍历序列构造二叉树
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
		// 1、区间没有节点了就返回空
		if (postBegin > postEnd)
		{
			return nullptr;
		}
		// 2、后序的最后一个值就是根节点
		TreeNode* root = new TreeNode(postorder[postEnd]);
		// 3、拿到中序中根节点所在的下标
		int rootOfInorder = inIndex[root->val];
		// 4、确定左子树的长度
		int leftLength = rootOfInorder - inBegin;
		// 5、根据左子树的长度对两个数组进行划分，递归构建左右子树
		root->left = _buildTree(inorder, postorder, inBegin, rootOfInorder - 1, postBegin, postBegin + leftLength - 1);
		root->right = _buildTree(inorder, postorder, rootOfInorder + 1, inEnd, postBegin + leftLength, postEnd - 1);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		// 映射中序遍历中节点的值和其对应的下标
		for (int i = 0; i < inorder.size(); ++i)
		{
			inIndex[inorder[i]] = i;
		}
		return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
};

// 根据前序和后序遍历构造二叉树
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
		// 1、如果区间没有元素了，就返回空
		if (preBegin > preEnd)
		{
			return nullptr;
		}
		// 2、前序的第一个元素就是根节点的值，创建根节点
		TreeNode* root = new TreeNode(preorder[preBegin]);
		// 注意如果只有一个元素了，必须要现在就结束并返回刚刚创建的根节点
		// 因为第三步里需要找左子树的根节点：preBegin + 1
		// 这时如果不返回会越界
		if (preBegin == preEnd)
		{
			return root;
		}
		// 3、记录在后序中左子树的根所在的下标
		int leftRootOfPost = postIndex[preorder[preBegin + 1]];
		// 4、记录左子树长度
		int leftLength = leftRootOfPost - postBegin + 1;
		// 5、根据左子树长度对两个数组进行分组，递归构建左右子树
		root->left = _constructFromPrePost(preorder, postorder, preBegin + 1, preBegin + leftLength, postBegin, postBegin + leftLength - 1);
		root->right = _constructFromPrePost(preorder, postorder, preBegin + leftLength + 1, preEnd, postBegin + leftLength, postEnd - 1);
		return root;
	}

public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
	{
		// 1、映射后序中节点的值和下标
		for (int i = 0; i < postorder.size(); ++i)
		{
			postIndex[postorder[i]] = i;
		}
		return _constructFromPrePost(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
	}
};
