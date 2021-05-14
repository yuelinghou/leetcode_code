#define _CRT_SECURE_NO_WARNINGS 1

// ��������Ľ��� II
class Solution {
public:
	// ˫ָ�뷨
	// �ȸ���������
	// ��������ָ��ֱ�ָ�����������һ��Ԫ��
	// �����ȣ�����ret��
	// ����ȣ�С���±�����Ų
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> ret;
		int flag1 = 0;
		int flag2 = 0;
		while (flag1 < nums1.size() && flag2 < nums2.size())
		{
			if (nums1[flag1] == nums2[flag2])
			{
				ret.push_back(nums1[flag1]);
				++flag1;
				++flag2;
			}
			else
			{
				if (nums1[flag1] < nums2[flag2])
				{
					++flag1;
				}
				else
				{
					++flag2;
				}
			}
		}
		return ret;
	}
};

// ��һ
class Solution {
public:
	// ��������Ӽ򻯰�
	// ÿһλ�ϵ����ֶ�Ӧ��ӣ�û�����˾ͼ�0
	// ���Ҫ�Ƿ��н�λ
	// ���õõ����ս��
	void ReserveArray(vector<int>& digits)
	{
		int left = 0;
		int right = digits.size() - 1;
		while (left < right)
		{
			swap(digits[left++], digits[right--]);
		}
	}
	vector<int> plusOne(vector<int>& digits)
	{
		int num = 1;
		int carry = 0;
		vector<int> ret;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (i != digits.size() - 1)
			{
				num = 0;
			}
			int sum = digits[i] + num + carry;
			if (sum > 9)
			{
				sum -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			ret.push_back(sum);
		}
		if (carry)
		{
			ret.push_back(carry);
		}
		ReserveArray(ret);
		return ret;
	}
};

// �ƶ���
class Solution {
public:
	// ˫ָ�뷨
	// һ��ʼ����ָ�붼ָ���һ��Ԫ��
	// frontȥ�ҷ�0Ԫ��
	// �ҵ��ˣ���back���������߶�����
	// �Ҳ�����back������front������ǰ��
	void moveZeroes(vector<int>& nums)
	{
		int front = 0;
		int back = 0;
		while (front < nums.size())
		{
			if (nums[front])
			{
				swap(nums[front++], nums[back++]);
			}
			else
			{
				++front;
			}
		}
	}
};