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
		// ����tokens
		// ���������ַ���������ת��Ϊ����ѹջ
		// �����ַ�����ջ�ڵ����������ó������㣬������������Ҫѹջ
		for (auto& str : tokens)
		{
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))
			{
				// ����str.c_str()-"0"����Ϊ���ַ�������9ʱ����ֵ�Ľ�������Ǵ����ֵĲ�ֵ
				// Ҳ����str[0]-'0'����ΪҪ��������ִ���9ʱ�ʹ�����
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
