#define _CRT_SECURE_NO_WARNINGS 1

// ����
class Solution {
public:
	int nthUglyNumber(int n)
	{
		vector<int> v;// ��ų���
		v.push_back(1);// �Ȳ����һ������1
		int p2 = 0;// ��ָ�������û�г�2
		int p3 = 0;// ��ָ�������û�г�3
		int p5 = 0;// ��ָ�������û�г�5
		while (--n)
		{
			// 1���ҵ���һ������ĳ���
			int tmp = min(v[p2] * 2, v[p3] * 3);
			int lastNum = min(tmp, v[p5] * 5);
			v.push_back(lastNum);
			// 2���������ĸ�ָ��˳����ģ��ҵ���++
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
