#define _CRT_SECURE_NO_WARNINGS 1

// 根据二叉树创建字符串
class Solution {
public:
	string tree2str(TreeNode* root)
	{
		string s;
		// 空树就返回空串
		if (!root)
		{
			return s;
		}
		// 1、先把根节点的值加到字符串中
		s += to_string(root->val);
		// 2、把左树加到字符串中
		if (root->left)
		{
			s += '(';
			s += tree2str(root->left);
			s += ')';
		}
		else if (root->right)// 注意如果左树为空且右树不为空，加右树前要加个空括号先
		{
			s += "()";
		}

		// 3、把右树加到字符串中
		if (root->right)
		{
			s += '(';
			s += tree2str(root->right);
			s += ')';
		}
		return s;
	}
};

// 二叉树的层序遍历I
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> vv;
		// 空树的话就返回空二维数组
		if (!root)
		{
			return vv;
		}
		queue<TreeNode*> q;
		// 先把根节点入队列
		q.push(root);
		while (!q.empty())
		{
			// 记录当前层有多少个节点
			int levelSize = q.size();
			// 存储当前层的节点的数据
			vector<int> v;
			// 把当前层节点的数据依次放到v里，随后该节点出队列
			// 当前层出完了（也就是for循环结束）下一层的节点也全入队列了
			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			// 把当前层节点的数据加到vv里
			vv.push_back(v);
		}
		return vv;
	}
};

// 二叉树的层序遍历II
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> vv;
		// 空树的话就返回空二维数组
		if (!root)
		{
			return vv;
		}
		queue<TreeNode*> q;
		// 先把根节点入队列
		q.push(root);
		while (!q.empty())
		{
			// 记录当前层有多少个节点
			int levelSize = q.size();
			// 存储当前层的节点的数据
			vector<int> v;
			// 把当前层节点的数据依次放到v里，随后该节点出队列
			// 当前层出完了（也就是for循环结束）下一层的节点也全入队列了
			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			// 把当前层节点的数据加到vv里
			vv.push_back(v);
		}
		// 用reverse反转vv，得到的就是倒序的遍历
		reverse(vv.begin(), vv.end());
		return vv;
	}
};
