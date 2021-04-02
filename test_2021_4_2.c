#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//思路：
//两个非负整数相加，结果不会超过两个数中最大位数+1 //999+999=1998（最多也就四位数）
//开辟两个数最大位数+1的空间，用来存放它们的和
//从个位开始，两个数对应的位数相加再加进位（0或者1）
//没位数加得的结果倒着存放（即个位放在下标为0的位置上...），最后把存放的数再倒置

//形参说明：
 //A：数组的首元素地址
 //ASize：数组元素个数
 //k：需要相加的非负整数
 //returnSize：malloc空间的元素个数
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	//记录K的位数
//	int KSize = 0;
//	int tmp = K;
//	while (tmp)
//	{
//		KSize++;
//		tmp /= 10;
//	}
//	//malloc开辟空间
//	int len = KSize > ASize ? KSize + 1 : ASize + 1;
//	int* arr = (int*)malloc(sizeof(int)*len);
//	//A数组的下标
//	int Aflag = ASize - 1;
//	//进位
//	int next = 0;
//	//开辟空间的下标
//	int arr_flag = 0;
//	//两个数开始每位的相加
//	while (Aflag >= 0 || K != 0)
//	{
//		//一个位置上K的数字
//		int Kval = K % 10;
//		K /= 10;
//		//一个位置上A的数字
//		int Aval = 0;
//		if (Aflag >= 0)
//		{
//			Aval = A[Aflag--];
//		}
//		//对应为上的数字相加
//		int sum = Aval + Kval + next;
//		//判断加得的结果是否大于大于10
//		if (sum >= 10)
//		{
//			sum -= 10;
//			next = 1;
//		}
//		else
//		{
//			next = 0;
//		}
//		//相加之后的结果放入开辟的空间中
//		arr[arr_flag++] = sum;
//	}
//	//判断最后一次相加是否有进位
//	if (next)
//	{
//		arr[arr_flag++] = next;
//	}
//	//开始将结果倒置
//	int begin = 0;
//	int end = arr_flag - 1;
//	while (begin < end)
//	{
//		int tmp_num = arr[begin];
//		arr[begin] = arr[end];
//		arr[end] = tmp_num;
//		begin++;
//		end--;
//	}
//	//输出型参数，告诉外界相加得到的结果有几位数
//	*returnSize = arr_flag;
//	//返回开辟的空间的地址给外界
//	return arr;
//}

//#include<stdio.h>
//
//
//void rotate(int* nums, int numsSize, int k)
//{
//	int time = numsSize;
//	int cur_flag = 0;
//	int dest_flag = (cur_flag + k) % numsSize;
//	int pre_num = nums[cur_flag];
//	while (time--)
//	{
//		int tmp = nums[dest_flag];
//		nums[dest_flag] = pre_num;
//		cur_flag = dest_flag;
//		dest_flag = (cur_flag + k) % numsSize;
//		pre_num = tmp;
//	}
//}
//
//int main()
//{
//	int arr[] = { -1,-100,3,99 };
//	rotate(arr,  4, 2);
//	return 0;
//}

#include<stdio.h>

int main()
{

	r
}