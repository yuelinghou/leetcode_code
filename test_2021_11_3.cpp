#define _CRT_SECURE_NO_WARNINGS 1
// 图像渲染
class Solution
{
	int distance[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		// 1、创建一个存储下标的队列，把（sr，sc）先入队列，从这里开始搜索
		int curColor = image[sr][sc];
		if (curColor == newColor)
		{
			return image;
		}
		int row = image.size();
		int col = image[0].size();
		queue<pair<int, int>> q;
		q.push(make_pair(sr, sc));
		image[sr][sc] = newColor;
		// 2、BFS向上下左右搜索curColor
		while (!q.empty())
		{
			pair<int, int> front = q.front();
			q.pop();
			int i = front.first;
			int j = front.second;
			for (int d = 0; d < 4; ++d)
			{
				int ni = i + distance[d][0];
				int nj = j + distance[d][1];
				if (ni >= 0 && ni < row && nj >= 0 && nj < col && image[ni][nj] == curColor)
				{
					q.push(make_pair(ni, nj));
					image[ni][nj] = newColor;
				}
			}
		}
		// 3、最后返回图像
		return image;
	}
};

// 01 矩阵
class Solution
{
	int constExr[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		// 1、创建
		// 最终返回的结果矩阵ret
		// 用来标志多路径源集合的矩阵super，一开始把mat中值为0的下标对应到super中标志为1
		// bfs时用到的存储下标键值对的队列，一开始把所有值为0的下标入队列
		int row = mat.size();
		int col = mat[0].size();
		vector<vector<int>> ret(row, vector<int>(col));
		vector<vector<int>> super(row, vector<int>(col));
		queue<pair<int, int>> q;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (mat[i][j] == 0)
				{
					q.push(make_pair(i, j));
					super[i][j] = 1;
				}
			}
		}
		// 2、进行多路径的广度优先搜索
		while (!q.empty())
		{
			pair<int, int> front = q.front();
			int i = front.first;
			int j = front.second;
			q.pop();
			for (int d = 0; d < 4; ++d)
			{
				int ni = i + constExr[d][0];
				int nj = j + constExr[d][1];
				if (ni >= 0 && ni < row && nj >= 0 && nj < col && !super[ni][nj])
				{
					q.push(make_pair(ni, nj));
					ret[ni][nj] = ret[i][j] + 1;
					super[ni][nj] = 1;
				}
			}
		}
		// 返回结果矩阵ret
		return ret;
	}
};
