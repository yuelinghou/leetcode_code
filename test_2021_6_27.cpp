#define _CRT_SECURE_NO_WARNINGS 1

// ��ֵ�������η�
class Solution {
public:
	double myPow(double x, int n)
	{
		// ���ָ���Ǹ����Ļ���xҪ��Ϊ��������ĸ����Ϊ0�����������ȴ���
		if (x == 0)
		{
			return 0;
		}
		// Ϊ���ܴ洢INT_MIN���෴������������ת����long
		long exponent = n;
		if (n < 0)
		{
			x = 1 / x;
			exponent = -exponent;// ����exponent=-n����n=INT_MINʱ-nΪint���ʹ治��
		}
		double ret = 1.0;
		// n��Ϊ������תʮ���ƵĹ�ʽ������
		while (exponent > 0)
		{
			if (exponent & 1)
			{
				ret *= x;
			}
			x *= x;
			exponent >>= 1;
		}
		return ret;
	}
};

// �ַ������
class Solution {
public:
	string multiply(string num1, string num2)
	{
		// ����һ��Ϊ0�ͷ���"0"
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		int len1 = num1.size();
		int len2 = num2.size();
		string ret(len1 + len2, '0');
		// ģ��˷��Ĺ���
		for (int i = len1 - 1; i >= 0; --i)
		{
			for (int j = len2 - 1; j >= 0; --j)
			{
				// һ������ȥ������һ�����ֻ�Ҫ���Ͻ�λ
				int part = (num1[i] - '0') * (num2[j] - '0') + (ret[i + j + 1] - '0');
				// ת�����ַ��ŵ���Ӧλ��
				ret[i + j + 1] = part % 10 + '0';
				// ������һ��λ�õĽ�λ
				ret[i + j] = (ret[i + j] - '0') + part / 10 + '0';
			}
		}
		// ȥ��ǰ������0
		for (int i = 0; i < len1 + len2; ++i)
		{
			if (ret[i] != '0')
			{
				return ret.substr(i);
			}
		}
		return "0";
	}
};

// ɾ�����������е��ظ���
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		// i�±��ǰ�����������
		// index��0�±꿪ʼ
		// ���nums[i]!=nums[index]���Ͱ�i��Ӧ��ֵ���ǵ�++indexλ��
		// ���index+1����ɾ����������³���,���numsΪ�վ�Ҫ��������
		if (nums.size() == 0)
		{
			return 0;
		}
		int index = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[index] != nums[i])
			{
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};
