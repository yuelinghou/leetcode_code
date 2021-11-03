#define _CRT_SECURE_NO_WARNINGS 1
// ͼ����Ⱦ
class Solution
{
	int distance[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		// 1������һ���洢�±�Ķ��У��ѣ�sr��sc��������У������￪ʼ����
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
		// 2��BFS��������������curColor
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
		// 3����󷵻�ͼ��
		return image;
	}
};

// 01 ����
class Solution
{
	int constExr[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		// 1������
		// ���շ��صĽ������ret
		// ������־��·��Դ���ϵľ���super��һ��ʼ��mat��ֵΪ0���±��Ӧ��super�б�־Ϊ1
		// bfsʱ�õ��Ĵ洢�±��ֵ�ԵĶ��У�һ��ʼ������ֵΪ0���±������
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
		// 2�����ж�·���Ĺ����������
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
		// ���ؽ������ret
		return ret;
	}
};
