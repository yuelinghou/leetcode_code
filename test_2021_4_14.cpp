#define _CRT_SECURE_NO_WARNINGS 1

//class Solution {
//public:
//	bool isPalindrome(int x)
//	{
//		//负数不是回文数
//		if (x < 0)
//		{
//			return false;
//		}
//		//最后一位为0的非0正整数不是回文数
//		else if (x != 0 && x % 10 == 0)
//		{
//			return false;
//		}
//		else
//		{
//			//num为x从尾开始头插,x也跟着尾删
//			//直到num大于等于x为止
//			int num = 0;
//			while (num < x)
//			{
//				num = num * 10 + x % 10;
//				x /= 10;
//			}
//			return num == x || (num /= 10) == x;
//		}
//	}
//};
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// //遍历数组，暴力求解
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	for (int i = 0; i < numsSize; i++)
//	{
//		int flag = 0;
//		for (int j = i + 1; j < numsSize; j++)
//		{
//			if (nums[i] + nums[j] == target)
//			{
//				flag = 1;
//				ret[0] = i;
//				ret[1] = j;
//				break;
//			}
//		}
//		if (flag)
//		{
//			break;
//		}
//	}
//	*returnSize = 2;
//	return ret;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = -12;
//	cout << a / 10 << endl;
//	return 0;
//}
