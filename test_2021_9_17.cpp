#define _CRT_SECURE_NO_WARNINGS 1

// 礼物的最大值 
class Solution {
public:
	// 动态规划法
	// 遍历棋盘，记录当前位置的礼物的最大值
	// 礼物的最大值等于当前位置的值加上max（上面位置， 左边位置）
	// 特殊情况：
	//    1、起始位置不用管最大值就是它自己
	//    2、i==0 && j！=0时，没有上边位置
	//    3、i!=0 && j==0时，没有左边位置
	// 最后，右下角的值就是礼物的最大值 
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

// 把数组排成最小的数
class Solution {
	// 先把这些数字转化为字符串
	// 不能单纯按数字大小和字符串的比较规则来排排，需要自定义比较规则来比较这些字符串：s1+s2 < s2+s1，说明s1小，最后排数字时s1应该排在s2前面
	// 用sort来排序，并且传入自定义的比较的仿函数
	// 最后把排序好的字符串数组从前往后拼接起来
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

// 把数字翻译成字符串
class Solution {
public:
	// 动态规划法
	// 把数字转化为字符串，从1位置开始遍历字符串
	// c代表当前位置有多少种翻译方法，即f(n)
	// b代表前一个位置有多少种翻译方法，即f(n-1)
	// a代表前一个位置的前一个位置有多少种翻译方法，即f(n-2)
	// 没有数字也算一种翻译翻译方法，因为从1位置开始遍历，说明第0个位置已经处理完毕，所以开始a=1，b=1，c=1；
	// 遍历一个位置时，组合它的前一个位置看看是否满足>=0 && <=25，如果满足说明它可以和前一个位置的数组合成一个字母，那么当前位置的翻译数就为f(n-1) + f(n-2)，如果不满足说明当前这个位置的数字对前面没有任何贡献，翻译数对于f(n-1)
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