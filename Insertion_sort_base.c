/*********************************
> File Name: Insertion_sort_base.c
> Author: Zeno
> Mail:340562424@qq.com
> Created Time: 2015年09月03日 星期四 16时42分20秒
********************************/
#include<stdio.h>
void insertionSort(int array[]);
int main()
{
	int i;
	int arr[6] = { 4, 1,1,1,1, 1 };
	insertionSort(arr);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}

void insertionSort(int array[])
{
	//newPoi待确定位置的数组元素的下标，逐渐递减，直到数组的最后一个元素
	//current为array[newPoi]的前驱的元素的下标，逐渐递减，来定位要与array[newPoi]比较的元素值
	int len = 0;
	len = sizeof(array)/sizeof(array[0]);
	int newPoi = 0, current = 0, tempNew = 0, tempVal = 0;
	for (newPoi = 1; newPoi < len; newPoi++)
	{
		tempNew = newPoi;
		tempVal = array[newPoi];
		current = newPoi - 1;
		int flag = 0;
		while (array[current] > tempVal)
		{
			//循环交换
			array[tempNew] = array[current];
			if (current == 0)//防止下標越界
			{
				array[current] = tempVal;
				flag = 1;
				break;
			}
			else
			{
				tempNew--;
				current--;
			}
		}
		if(flag == 0)//防止重複賦值，與if(current == 0)互斥的語句;开始写的是if(current != 0),发现1， 5， 1， 4, 6,不能很好排序
			//用flag解决了两个if语句互斥的问题
		array[current + 1] = tempVal;
	}
	
}


