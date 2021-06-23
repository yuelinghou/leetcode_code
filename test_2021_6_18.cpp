#define _CRT_SECURE_NO_WARNINGS 1

// ��ǰ��������������й��������
class Solution {
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& preI, int inBegin, int inEnd)
	{
		// ��������Ĵ���
		if (inBegin > inEnd)
		{
			return nullptr;
		}
		// �������ڵ�
		TreeNode* root = new TreeNode(preorder[preI]);
		// ��¼��������ĸ��ڵ���±�
		int inI = inBegin;
		while (inorder[inI] != preorder[preI])
		{
			++inI;
		}
		// ����������������
		if (inBegin <= inI - 1)
		{
			root->left = _buildTree(preorder, inorder, ++preI, inBegin, inI - 1);
		}
		else
		{
			root->left = nullptr;
		}
		// ����������������
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
		// ��¼ǰ������ĸ��ڵ���±�
		int preI = 0;
		return _buildTree(preorder, inorder, preI, 0, inorder.size() - 1);
	}
};

// �������������������
class Solution {
	// ���ҽڵ��Ƿ�������
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
		// �������Ҳ������ؿ�ָ��
		if (!root)
		{
			return nullptr;
		}
		// 1�����ڵ�������е�һ���Ļ������ڵ�������ǵ������������
		if (root == p || root == q)
		{
			return root;
		}
		bool pLeft, pRight, qLeft, qRight;
		pLeft = Find(root->left, p);
		pRight = !pLeft;
		qLeft = Find(root->left, q);
		qRight = !qLeft;
		// 2�������ڵ�ֱ��ڸ��ڵ�����������Ļ������ڵ�������ǵ������������
		if ((pLeft&&qRight) || (pRight&&qLeft))
		{
			return root;
		}
		else if (pLeft&&qLeft)// 3�������ڵ㶼�����������ݹ鵽��������ȥ��
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (pRight&&qRight)// 4�������ڵ㶼�����������ݹ鵽��������ȥ��|
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else// 5�������ڣ��ͷ��ؿ�ָ��
		{
			return nullptr;
		}
	}
};

// �����������в�������I
class Solution {
	int BinarySearch(vector<int>& nums, int target, int left, int right)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			// �ݹ�ͳ��target���ֵĴ���
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
	// ��ζ��ֲ���
	int search(vector<int>& nums, int target)
	{
		return BinarySearch(nums, target, 0, nums.size() - 1);
	}
};
