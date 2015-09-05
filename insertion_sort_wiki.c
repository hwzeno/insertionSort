/*********************************
    > File Name: insertion_sort_wiki.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月04日 星期五 16时11分19秒
 ********************************/
#include<stdio.h>
void insertion_sort(int array[], int first, int last);
int main()
{
	int i;
	int arr[10] = {5, 3, 4, 2, 1, 2, 6, 7, 8, 9};
	insertion_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	for(i = 0; i< sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d\t", arr[i]);

	}
	printf("\n");
	return 0;
}


void insertion_sort(int array[], int first, int last)
{
	int i, j, temp;
	for(i = first + 1; i<= last; i++)
	{
		temp = array[i];//与已排序的数逐一比较，大于temp时，该数向后移
		for(j = i - 1; j >= first && array[j] > temp; j--)
		//当first=0,j循环到-1时，由于短路求值，不会运算array[-1]
		{
			array[j + 1] = array[j];
			array[j] = temp;//被排序数放到正确的位置
		}
	}
}
