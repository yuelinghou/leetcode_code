#define _CRT_SECURE_NO_WARNINGS 1

// ��������
class Solution
{
private:
	int around[4][2] =
	{
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1}
	};

public:
	int numIslands(vector<vector<char>>& grid)
	{
		int ret = 0;
		queue<pair<int, int>> q;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == '1')
				{
					q.push(make_pair(i, j));
					++ret;
					while (!q.empty())
					{
						int row = q.front().first;
						int col = q.front().second;
						grid[row][col] = '0';
						q.pop();
						for (int k = 0; k < 4; ++k)
						{
							int newRow = row + around[k][0];
							int newCol = col + around[k][1];
							if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != '1')
							{
								continue;
							}
							grid[newRow][newCol] = '0';
							q.push(make_pair(newRow, newCol));
						}
					}
				}
			}
		}
		return ret;
	}
};

// ����ǽ
class Solution
{
private:
	int around[4][2] =
	{
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1}
	};

public:
	void wallsAndGates(vector<vector<int>>& rooms)
	{
		queue<pair<int, int>> q;
		int m = rooms.size();
		int n = rooms[0].size();
		// 1���Ȱ����е��Ŷ������
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (rooms[i][j] == 0)
				{
					q.push(make_pair(i, j));
				}
			}
		}
		// 2�������ó�����������꣬������λ�õ����������Ƿ��пշ���
		// ����пշ��䣬��ô�շ��������ž�����Ǹ�λ�õ�ֵ+1����ɺ�ԭ���շ�������������
		while (!q.empty())
		{
			pair<int, int> pr = q.front();
			q.pop();
			int row = pr.first;
			int col = pr.second;
			for (int i = 0; i < 4; ++i)
			{
				int newRow = row + around[i][0];
				int newCol = col + around[i][1];
				if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != INT_MAX)
				{
					continue;
				}
				rooms[newRow][newCol] = rooms[row][col] + 1;
				q.push(make_pair(newRow, newCol));
			}
		}
	}
};