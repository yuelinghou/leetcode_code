#define _CRT_SECURE_NO_WARNINGS 1

// 从前序与中序遍历序列构造二叉树
class Solution {
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& preI, int inBegin, int inEnd)
	{
		// 空树情况的处理
		if (inBegin > inEnd)
		{
			return nullptr;
		}
		// 创建根节点
		TreeNode* root = new TreeNode(preorder[preI]);
		// 记录中序的树的根节点的下标
		int inI = inBegin;
		while (inorder[inI] != preorder[preI])
		{
			++inI;
		}
		// 创建并连接左子树
		if (inBegin <= inI - 1)
		{
			root->left = _buildTree(preorder, inorder, ++preI, inBegin, inI - 1);
		}
		else
		{
			root->left = nullptr;
		}
		// 创建并连接右子树
		if (inI + 1 <= inEnd)
		{
			root->right = _buildTree(preorder, inorder, ++preI, inI + 1, inEnd);
		}
		else
		{
			root->right = nullptr;
		}
		return root;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		// 记录前序的树的根节点的下标
		int preI = 0;
		return _buildTree(preorder, inorder, preI, 0, inorder.size() - 1);
	}
};

// 二叉树的最近公共祖先
class Solution {
	// 查找节点是否在树中
	bool Find(TreeNode* root, TreeNode* x)
	{
		if (root == nullptr)
		{
			return false;
		}
		return root == x || Find(root->left, x) || Find(root->right, x);
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// 空树才找不到返回空指针
		if (!root)
		{
			return nullptr;
		}
		// 1、根节点就是其中的一个的话，根节点就是他们的最近公共祖先
		if (root == p || root == q)
		{
			return root;
		}
		bool pLeft, pRight, qLeft, qRight;
		pLeft = Find(root->left, p);
		pRight = !pLeft;
		qLeft = Find(root->left, q);
		qRight = !qLeft;
		// 2、两个节点分别在根节点的左右子树的话，根节点就是他们的最近公共祖先
		if ((pLeft&&qRight) || (pRight&&qLeft))
		{
			return root;
		}
		else if (pLeft&&qLeft)// 3、两个节点都在左子树，递归到左子树中去找
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (pRight&&qRight)// 4、两个节点都在右子树，递归到右子树中去找|
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else// 5、不存在，就返回空指针
		{
			return nullptr;
		}
	}
};

// 在排序数组中查找数字I
class Solution {
	int BinarySearch(vector<int>& nums, int target, int left, int right)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			// 递归统计target出现的次数
			if (nums[mid] == target)
			{
				return BinarySearch(nums, target, left, mid - 1) + BinarySearch(nums, target, mid + 1, right) + 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return 0;
	}

public:
	// 多次二分查找
	int search(vector<int>& nums, int target)
	{
		return BinarySearch(nums, target, 0, nums.size() - 1);
	}
};
