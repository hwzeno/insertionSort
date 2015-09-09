/*********************************
    > File Name: shell_Sort_randomNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月09日 星期三 17时14分43秒
 ********************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LT(a, b) ((a) < (b))
#define N 100001
int arr[N] = {0};
void shellSort(int arrary[], int arrLength, int stepSizeArr[], int stepSizeArrlength);
void shellInsert(int arrary[], int arrLength, int stepSize);//声明有无先后的关系
int main()
{
	int i = 0;
	int stepSize[7] = {19001, 4025, 836, 182, 34, 9, 1};
	FILE *fr;
	fr = fopen("randomNum.txt", "r");
	if(fr == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	for(i = 1; i <= N; i++)//能到100001
	{
		fscanf(fr, "%d", &arr[i]);
	}
	clock_t bg, ed;
	bg = clock();
	shellSort(arr, N, stepSize, 7);
	ed = clock();
	printf("cost time for: %.15f", (double)(ed - bg)/CLOCKS_PER_SEC);
	

	FILE *fw;
	fw = fopen("afterSort.txt", "w");
	for(i = 1; i < N; i++)
	{
		fprintf(fw, "%d\t", arr[i]);
		if(i%10 == 0)
			fprintf(fw, "%c", '\n');
	}
	printf("%c", '\n');
}//main
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
	for(i = stepSize + 1; i < arrLength; ++i )//i < arrLength;数组的长度是100001,但是数组的下标只能到100000
		if(LT(array[i], array[i - stepSize]))
		{
			array[0] = array[i];	
			for(j = i - stepSize; j > 0 && LT(array[0], array[j]); j -= stepSize)//也用到了短路求值
				array[j + stepSize] = array[j];
			array[j + stepSize] = array[0];
		}
}//shellInsert
