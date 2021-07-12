#define _CRT_SECURE_NO_WARNINGS 1

// 矩阵中的路径
class Solution {
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
	{
		// 越界和当前位置不是对应字符时，结束这条路径
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
		{
			return false;
		}
		// k已经遍历完了
		if (k == word.size() - 1)
		{
			return true;
		}
		// 下一次前后上下找路径前，先把该位置置为\0
		board[i][j] = '\0';
		bool ret = dfs(board, word, i + 1, j, k + 1)
			|| dfs(board, word, i - 1, j, k + 1)
			|| dfs(board, word, i, j + 1, k + 1)
			|| dfs(board, word, i, j - 1, k + 1);
		// 还原该位置字符
		board[i][j] = word[k];
		return ret;
	}
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		// 遍历每一个位置，找是否存在路径
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (dfs(board, word, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
};

// 机器人的运动范围
class Solution {
	// 得到行标或列标的各个位数的和
	int GetSum(int num)
	{
		int ret = 0;
		while (num)
		{
			ret += num % 10;
			num /= 10;
		}
		return ret;
	}

	int dfs(int m, int n, int k, vector<vector<bool>>& board, int i, int j)
	{
		int sum = GetSum(i) + GetSum(j);
		// 下标越界、下标各个位数的和大于k，该位置已经走过这三种情况就返回0
		if (i >= m || j >= n || sum > k || board[i][j])
		{
			return 0;
		}
		// 该位置可以走，就标记为true
		board[i][j] = true;
		// 继续往下和往右走
		return 1 + dfs(m, n, k, board, i + 1, j) + dfs(m, n, k, board, i, j + 1);
	}
public:
	int movingCount(int m, int n, int k)
	{
		vector<vector<bool>> board(m, vector<bool>(n, false));
		// 从(0,0)位置开始走
		return dfs(m, n, k, board, 0, 0);
	}
};

// 切绳子
// 方法一：贪心算法
// 尽可能三段三段的切
class Solution {
public:
	int cuttingRope(int n)
	{
		// 1、长度小于等于三时，就切一段
		if (n < 4)
		{
			return n - 1;
		}
		// 2、大于大于4时
		int ret = 1;
		while (n > 4)
		{
			ret *= 3;
			n -= 3;
		}
		return ret * n;
	}
};

// 方法二：动态规划
// 小于等于3的单独处理，大于大于4的每种情况的处理前都要记录前面处理情况的最大值
class Solution {
public:
	int cuttingRope(int n)
	{
		// 1、绳子长度小于等于3时都切1段
		if (n <= 3)
		{
			return n - 1;
		}
		// 2、绳子长度大于大于4时
		vector<int> ret(n + 1, 0);
		// 规定切下来的一部分长度小于等于3时就不用切了
		ret[1] = 1;
		ret[2] = 2;
		ret[3] = 3;
		// 开始切
		for (int i = 4; i <= n; ++i)
		{
			for (int j = 1; j <= i / 2; ++j)
			{
				ret[i] = max(ret[i], ret[j] * ret[i - j]);
			}
		}
		return ret[n];
	}
};