#define _CRT_SECURE_NO_WARNINGS 1

// 字符串归一化
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	// count用来统计26个英文字母出现的次数
	vector<int> count(26);
	// 1、遍历字符串，把各个字符出现的次数映射到count中
	for (auto& e : s)
	{
		++count[e - 'a'];
	}
	// 2、遍历count数组并叠加字符ch，打印归一化后的结果
	char ch = 'a';
	for (auto& e : count)
	{
		if (e)
		{
			cout << ch << e;
		}
		++ch;
	}
	cout << endl;
	return 0;
}


