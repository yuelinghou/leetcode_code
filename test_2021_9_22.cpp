#define _CRT_SECURE_NO_WARNINGS 1

// ��1+2+...+n
// ����һ
class Solution {
public:
	// �߼����� + �ݹ�
	// �����߼�������Ķ�·��������Ϊ�Ƿ�����ݹ������
	// && һ��ʼΪ��Ż��������һ��
	// || һ��ʼΪ�ٲŻ��������һ��
	int sumNums(int n)
	{
		//n && (n+=(sumNums(n-1)));
		!n || (n += (sumNums(n - 1)));
		return n;
	}
};

// ������
class Count
{
public:
	// ��̬��Ա�Ǹ�������������
	// ÿ����һ�����󶼻����һ�ι��캯��������n������ͻ����n��
	// �ڹ��캯���Ծ�̬��Ա���������������������ۼ�
	// ���������൱��ģ��ѭ��
	Count()
	{
		++number;
		sum += number;
	}
	static int number;
	static int sum;
};
int Count::number = 0;// ��̬��ԱҪ�������ʼ��
int Count::sum = 0;

class Solution
{
public:
	int sumNums(int n)
	{
		vector<Count> tmp(n);// ����n��Count���󣬵���n�ι��캯��
		int ret = Count::sum;
		Count::number = 0;// ��̨�ܲ�������Ҫ��ε���Solution������ÿ������һ���������������Ǿ�����Count��ľ�̬��Ա
		Count::sum = 0;
		return ret;
	}
};

