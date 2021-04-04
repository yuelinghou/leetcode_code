#define _CRT_SECURE_NO_WARNINGS 1

//思路：使用三次逆转法，让数组旋转k次
//保证k要小于数组长度，如果大于的话k%=size
//1. 先整体逆转[0, size-1]
//2. 逆转子数组[0, k - 1]
//3. 逆转子数组[k, size - 1]


void reserve(int* arr, int begin, int end)
{
	while (begin < end)
	{
		int tmp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = tmp;
		begin++;
		end--;
	}
}

void rotate(int* nums, int numsSize, int k) 
{
	if (k >= numsSize)
	{
		k %= numsSize;
	}
	reserve(nums, 0, numsSize - 1);
	reserve(nums, 0, k - 1);
	reserve(nums, k, numsSize - 1);
}

//思路：
//从后往前合并，一个元素一个元素的比较，谁大就放上去
//PS：不能从前往后合并，由于是合并到num1数组里的，num1元素会被num2并下来的元素覆盖
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	//end1：nums1的最大下标
//	//end2：nums2的最大下标
//	//end：合并之后的数组的最大下标
//	int end1 = m - 1;
//	int end2 = n-1;
//	int end = m + n - 1;
//	//从后往前合并，直到其中一个数组的元素合并完了为止
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (nums1[end1] > nums2[end2])
//		{
//			nums1[end--] = nums1[end1--];
//		}
//		else
//		{
//			nums1[end--] = nums2[end2--];
//		}
//	}
//	//处理没有合并的剩下来的元素
//	while (end1 >= 0)
//	{
//		nums1[end--] = nums1[end1--];
//	}
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}