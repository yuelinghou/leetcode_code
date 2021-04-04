#define _CRT_SECURE_NO_WARNINGS 1

//˼·��ʹ��������ת������������תk��
//��֤kҪС�����鳤�ȣ�������ڵĻ�k%=size
//1. ��������ת[0, size-1]
//2. ��ת������[0, k - 1]
//3. ��ת������[k, size - 1]


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

//˼·��
//�Ӻ���ǰ�ϲ���һ��Ԫ��һ��Ԫ�صıȽϣ�˭��ͷ���ȥ
//PS�����ܴ�ǰ����ϲ��������Ǻϲ���num1������ģ�num1Ԫ�ػᱻnum2��������Ԫ�ظ���
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	//end1��nums1������±�
//	//end2��nums2������±�
//	//end���ϲ�֮������������±�
//	int end1 = m - 1;
//	int end2 = n-1;
//	int end = m + n - 1;
//	//�Ӻ���ǰ�ϲ���ֱ������һ�������Ԫ�غϲ�����Ϊֹ
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
//	//����û�кϲ���ʣ������Ԫ��
//	while (end1 >= 0)
//	{
//		nums1[end--] = nums1[end1--];
//	}
//	while (end2 >= 0)
//	{
//		nums1[end--] = nums2[end2--];
//	}
//}