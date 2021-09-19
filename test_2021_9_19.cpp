#define _CRT_SECURE_NO_WARNINGS 1

// 丑数
class Solution {
public:
	int nthUglyNumber(int n)
	{
		vector<int> v;// 存放丑数
		v.push_back(1);// 先插入第一个丑数1
		int p2 = 0;// 所指向的数还没有乘2
		int p3 = 0;// 所指向的数还没有乘3
		int p5 = 0;// 所指向的数还没有乘5
		while (--n)
		{
			// 1、找到下一个插入的丑数
			int tmp = min(v[p2] * 2, v[p3] * 3);
			int lastNum = min(tmp, v[p5] * 5);
			v.push_back(lastNum);
			// 2、看看是哪个指针乘出来的，找到后++
			if (lastNum == v[p2] * 2)
			{
				++p2;
			}

			if (lastNum == v[p3] * 3)
			{
				++p3;
			}

			if (lastNum == v[p5] * 5)
			{
				++p5;
			}
		}
		return v.back();
	}
};
