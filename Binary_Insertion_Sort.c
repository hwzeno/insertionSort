/********************************
    > File Name: Binary_Insertion_Sort.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月07日 星期一 10时40分53秒
 ********************************/
#include<stdio.h>
void BInsertSort(int array[], int length);
int main()
{
	int i = 0;
	int arr[] = {5, 2, 2, 1, 7, 6, 8, 9, 4};
	int r[10];
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)//要转换一下，数组的第一个位置不能存放数据
		r[i+1] = arr[i];
	BInsertSort(r, sizeof(arr)/sizeof(arr[0]));
	for(i = 1; i <  sizeof(r)/sizeof(r[0]); ++i)
		printf("%d\t", r[i]);
	printf("\n");
	return 0;
}//main
void BInsertSort(int array[], int length)//所谓的折半，是对已经排好序的部分折半
{
	int i = 0;
	int j = 0;
	int low = 0;
	int high = 0;
	int m = 0;
	for(i = 2; i <= length; ++i)
	{
		array[0] = array[i]; 
		low = 1;
		high = i -1;
		while(low <= high)
		{
			m = (low+high)/2;
			if(array[0] < array[m])
				high = m - 1;
			else
				low = m + 1;
		}//while
		for(j = i - 1; j >= high + 1; --j)
			array[j + 1] = array[j];
		array[high + 1] = array[0];
	}//for
}//BInsertSort
