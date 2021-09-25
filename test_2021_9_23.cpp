#define _CRT_SECURE_NO_WARNINGS 1

// 字符串排序
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int M = 0;
	cin >> M;
	string s;// 获取每个字符串样本
	multiset<int> ms;// ms用来存储后六位数字并排序
	while (M--)
	{
		cin >> s;
		// 1、先通过substr得到后六位纯数字的子串
		// 2、再通过stoi把该子串转为整型并插入到ms中
		ms.insert(stoi(s.substr(s.size() - 6)));
	}
	// 最后遍历ms即可得到排序好的数据
	for (auto& e : ms)
	{
		cout << e << endl;
	}
	return 0;
}
