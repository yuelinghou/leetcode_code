#define _CRT_SECURE_NO_WARNINGS 1

// 求1+2+...+n
// 方法一
class Solution {
public:
	// 逻辑运算 + 递归
	// 利用逻辑运算符的短路性质来作为是否继续递归的条件
	// && 一开始为真才会继续看下一个
	// || 一开始为假才会继续看下一个
	int sumNums(int n)
	{
		//n && (n+=(sumNums(n-1)));
		!n || (n += (sumNums(n - 1)));
		return n;
	}
};

// 方法二
class Count
{
public:
	// 静态成员是该类对象所共享的
	// 每创建一个对象都会调用一次构造函数，创建n个对象就会调用n次
	// 在构造函数对静态成员变量进行自增操作，并累加
	// 整个过程相当于模拟循环
	Count()
	{
		++number;
		sum += number;
	}
	static int number;
	static int sum;
};
int Count::number = 0;// 静态成员要在类外初始化
int Count::sum = 0;

class Solution
{
public:
	int sumNums(int n)
	{
		vector<Count> tmp(n);// 构造n个Count对象，调用n次构造函数
		int ret = Count::sum;
		Count::number = 0;// 后台跑测试用例要多次调用Solution，所以每次跑完一个测试用例，我们就重置Count类的静态成员
		Count::sum = 0;
		return ret;
	}
};

