#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//˼·��
//�����Ǹ�������ӣ�������ᳬ�������������λ��+1 //999+999=1998�����Ҳ����λ����
//�������������λ��+1�Ŀռ䣬����������ǵĺ�
//�Ӹ�λ��ʼ����������Ӧ��λ������ټӽ�λ��0����1��
//ûλ���ӵõĽ�����Ŵ�ţ�����λ�����±�Ϊ0��λ����...�������Ѵ�ŵ����ٵ���

//�β�˵����
 //A���������Ԫ�ص�ַ
 //ASize������Ԫ�ظ���
 //k����Ҫ��ӵķǸ�����
 //returnSize��malloc�ռ��Ԫ�ظ���
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	//��¼K��λ��
//	int KSize = 0;
//	int tmp = K;
//	while (tmp)
//	{
//		KSize++;
//		tmp /= 10;
//	}
//	//malloc���ٿռ�
//	int len = KSize > ASize ? KSize + 1 : ASize + 1;
//	int* arr = (int*)malloc(sizeof(int)*len);
//	//A������±�
//	int Aflag = ASize - 1;
//	//��λ
//	int next = 0;
//	//���ٿռ���±�
//	int arr_flag = 0;
//	//��������ʼÿλ�����
//	while (Aflag >= 0 || K != 0)
//	{
//		//һ��λ����K������
//		int Kval = K % 10;
//		K /= 10;
//		//һ��λ����A������
//		int Aval = 0;
//		if (Aflag >= 0)
//		{
//			Aval = A[Aflag--];
//		}
//		//��ӦΪ�ϵ��������
//		int sum = Aval + Kval + next;
//		//�жϼӵõĽ���Ƿ���ڴ���10
//		if (sum >= 10)
//		{
//			sum -= 10;
//			next = 1;
//		}
//		else
//		{
//			next = 0;
//		}
//		//���֮��Ľ�����뿪�ٵĿռ���
//		arr[arr_flag++] = sum;
//	}
//	//�ж����һ������Ƿ��н�λ
//	if (next)
//	{
//		arr[arr_flag++] = next;
//	}
//	//��ʼ���������
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
//	//����Ͳ��������������ӵõ��Ľ���м�λ��
//	*returnSize = arr_flag;
//	//���ؿ��ٵĿռ�ĵ�ַ�����
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