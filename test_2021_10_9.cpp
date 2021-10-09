#define _CRT_SECURE_NO_WARNINGS 1

// 岛屿数量
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

// 门与墙
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
		// 1、先把所有的门都入队列
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
		// 2、依次拿出队列里的坐标，看看该位置的上下左右是否有空房间
		// 如果有空房间，那么空房间的最近门距离就是该位置的值+1，完成后原来空房间的坐标入队列
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