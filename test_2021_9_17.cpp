#define _CRT_SECURE_NO_WARNINGS 1

// ��������ֵ 
class Solution {
public:
	// ��̬�滮��
	// �������̣���¼��ǰλ�õ���������ֵ
	// ��������ֵ���ڵ�ǰλ�õ�ֵ����max������λ�ã� ���λ�ã�
	// ���������
	//    1����ʼλ�ò��ù����ֵ�������Լ�
	//    2��i==0 && j��=0ʱ��û���ϱ�λ��
	//    3��i!=0 && j==0ʱ��û�����λ��
	// ������½ǵ�ֵ������������ֵ 
	int maxValue(vector<vector<int>>& grid)
	{
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 && j == 0)
				{
				}
				else if (i == 0 && j != 0)
				{
					grid[i][j] += grid[i][j - 1];
				}
				else if (i != 0 && j == 0)
				{
					grid[i][j] += grid[i - 1][j];
				}
				else
				{
					grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
				}
			}
		}
		return grid[row - 1][col - 1];
	}
};

// �������ų���С����
class Solution {
	// �Ȱ���Щ����ת��Ϊ�ַ���
	// ���ܵ��������ִ�С���ַ����ıȽϹ��������ţ���Ҫ�Զ���ȽϹ������Ƚ���Щ�ַ�����s1+s2 < s2+s1��˵��s1С�����������ʱs1Ӧ������s2ǰ��
	// ��sort�����򣬲��Ҵ����Զ���ıȽϵķº���
	// ��������õ��ַ��������ǰ����ƴ������
private:
	struct Compare
	{
		bool operator()(string& s1, string& s2)
		{
			return s1 + s2 < s2 + s1;
		}
	};
public:
	string minNumber(vector<int>& nums)
	{
		vector<string> v;
		for (auto& e : nums)
		{
			v.push_back(to_string(e));
		}
		sort(v.begin(), v.end(), Compare());
		string s;
		for (auto& e : v)
		{
			s += e;
		}
		return s;
	}
};

// �����ַ�����ַ���
class Solution {
public:
	// ��̬�滮��
	// ������ת��Ϊ�ַ�������1λ�ÿ�ʼ�����ַ���
	// c����ǰλ���ж����ַ��뷽������f(n)
	// b����ǰһ��λ���ж����ַ��뷽������f(n-1)
	// a����ǰһ��λ�õ�ǰһ��λ���ж����ַ��뷽������f(n-2)
	// û������Ҳ��һ�ַ��뷭�뷽������Ϊ��1λ�ÿ�ʼ������˵����0��λ���Ѿ�������ϣ����Կ�ʼa=1��b=1��c=1��
	// ����һ��λ��ʱ���������ǰһ��λ�ÿ����Ƿ�����>=0 && <=25���������˵�������Ժ�ǰһ��λ�õ�����ϳ�һ����ĸ����ô��ǰλ�õķ�������Ϊf(n-1) + f(n-2)�����������˵����ǰ���λ�õ����ֶ�ǰ��û���κι��ף�����������f(n-1)
	int translateNum(int num)
	{
		string s(to_string(num));
		int a = 1;
		int b = 1;
		int c = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			a = b;
			b = c;
			string tmp(s.substr(i - 1, 2));
			if (tmp >= "10" && tmp <= "25")
			{
				c += a;
			}
		}
		return c;
	}
};