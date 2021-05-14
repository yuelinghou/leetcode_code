#define _CRT_SECURE_NO_WARNINGS 1

// 两个数组的交集 II
class Solution {
public:
	// 双指针法
	// 先给数组排序
	// 定义两个指针分别指向两个数组第一个元素
	// 如果相等，放入ret中
	// 不相等，小的下标往后挪
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

// 加一
class Solution {
public:
	// 两个数相加简化版
	// 每一位上的数字对应相加，没有数了就加0
	// 最后要是否还有进位
	// 逆置得到最终结果
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

// 移动零
class Solution {
public:
	// 双指针法
	// 一开始两个指针都指向第一个元素
	// front去找非0元素
	// 找到了，和back交换，二者都自增
	// 找不到，back不动，front继续往前找
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