/*********************************
    > File Name: shell_Sort.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月09日 星期三 15时24分50秒
 ********************************/
#include<stdio.h>
#define LT(a, b) ((a) < (b))
void shellSort(int arrary[], int arrLength, int stepSizeArr[], int stepSizeArrlength);
void shellInsert(int arrary[], int arrLength, int stepSize);//声明有无先后的关系
int main()
{
	int i = 0;
	int arr[8] = { 0, 9, 2, 3, 1, 5, 6, 8}	;//arr[0] 不存数据
	int stepSize[3] = {5, 3, 1};
	shellSort(arr, 7, stepSize, 3);
	for(i = 1; i <= 7; i++)
		printf(" %d\t", arr[i]);
	printf("%c", '\n');
}
void shellSort(int array[], int arrLength, int stepSizeArr[], int stepSizeArrLength)
{
	int i;
	for(i = 0; i < stepSizeArrLength; i++)
		shellInsert(array, arrLength, stepSizeArr[i]);
}//shellSort
void shellInsert(int array[],int arrLength, int stepSize)
{
	int i = 0;
	int j = 0;
	for(i = stepSize + 1; i <= arrLength; ++i )
		if(LT(array[i], array[i - stepSize]))
		{
			array[0] = array[i];	
			for(j = i - stepSize; j > 0 && LT(array[0], array[j]); j -= stepSize)
				array[j + stepSize] = array[j];
			array[j + stepSize] = array[0];
		}
}
