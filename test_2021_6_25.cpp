#define _CRT_SECURE_NO_WARNINGS 1

// �����е�·��
class Solution {
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
	{
		// Խ��͵�ǰλ�ò��Ƕ�Ӧ�ַ�ʱ����������·��
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
		{
			return false;
		}
		// k�Ѿ���������
		if (k == word.size() - 1)
		{
			return true;
		}
		// ��һ��ǰ��������·��ǰ���ȰѸ�λ����Ϊ\0
		board[i][j] = '\0';
		bool ret = dfs(board, word, i + 1, j, k + 1)
			|| dfs(board, word, i - 1, j, k + 1)
			|| dfs(board, word, i, j + 1, k + 1)
			|| dfs(board, word, i, j - 1, k + 1);
		// ��ԭ��λ���ַ�
		board[i][j] = word[k];
		return ret;
	}
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		// ����ÿһ��λ�ã����Ƿ����·��
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

// �����˵��˶���Χ
class Solution {
	// �õ��б���б�ĸ���λ���ĺ�
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
		// �±�Խ�硢�±����λ���ĺʹ���k����λ���Ѿ��߹�����������ͷ���0
		if (i >= m || j >= n || sum > k || board[i][j])
		{
			return 0;
		}
		// ��λ�ÿ����ߣ��ͱ��Ϊtrue
		board[i][j] = true;
		// �������º�������
		return 1 + dfs(m, n, k, board, i + 1, j) + dfs(m, n, k, board, i, j + 1);
	}
public:
	int movingCount(int m, int n, int k)
	{
		vector<vector<bool>> board(m, vector<bool>(n, false));
		// ��(0,0)λ�ÿ�ʼ��
		return dfs(m, n, k, board, 0, 0);
	}
};

// ������
// ����һ��̰���㷨
// �������������ε���
class Solution {
public:
	int cuttingRope(int n)
	{
		// 1������С�ڵ�����ʱ������һ��
		if (n < 4)
		{
			return n - 1;
		}
		// 2�����ڴ���4ʱ
		int ret = 1;
		while (n > 4)
		{
			ret *= 3;
			n -= 3;
		}
		return ret * n;
	}
};

// ����������̬�滮
// С�ڵ���3�ĵ����������ڴ���4��ÿ������Ĵ���ǰ��Ҫ��¼ǰ�洦����������ֵ
class Solution {
public:
	int cuttingRope(int n)
	{
		// 1�����ӳ���С�ڵ���3ʱ����1��
		if (n <= 3)
		{
			return n - 1;
		}
		// 2�����ӳ��ȴ��ڴ���4ʱ
		vector<int> ret(n + 1, 0);
		// �涨��������һ���ֳ���С�ڵ���3ʱ�Ͳ�������
		ret[1] = 1;
		ret[2] = 2;
		ret[3] = 3;
		// ��ʼ��
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