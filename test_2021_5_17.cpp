#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		// 遍历tokens
		// 遇到数字字符串，把它转化为数字压栈
		// 遇到字符，把栈内的两个数据拿出来运算，最后的运算结果还要压栈
		for (auto& str : tokens)
		{
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))
			{
				// 不能str.c_str()-"0"，因为当字符串大于9时，差值的结果不再是纯数字的差值
				// 也不能str[0]-'0'，因为要运算的数字大于9时就错误了
				st.push(atoi(str.c_str()));
			}
			else
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (str[0])
				{
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left*right);
					break;
				case '/':
					st.push(left / right);
					break;
				}
			}
		}
		return st.top();
	}
};

int main()
{
	vector<string> v;
	v.push_back("4");
	v.push_back("13");
	v.push_back("5");
	v.push_back("/");
	v.push_back("+");
	Solution s;
	cout << s.evalRPN(v) << endl;
	return 0;
}
