#define _CRT_SECURE_NO_WARNINGS 1

//class Solution {
//public:
//	bool isPalindrome(int x)
//	{
//		//�������ǻ�����
//		if (x < 0)
//		{
//			return false;
//		}
//		//���һλΪ0�ķ�0���������ǻ�����
//		else if (x != 0 && x % 10 == 0)
//		{
//			return false;
//		}
//		else
//		{
//			//numΪx��β��ʼͷ��,xҲ����βɾ
//			//ֱ��num���ڵ���xΪֹ
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
// //�������飬�������
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
