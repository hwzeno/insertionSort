/*********************************
    > File Name: BInsertionSort_randonNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月08日 星期二 18时02分26秒
 ********************************/
#include<stdio.h>
#include<time.h>
#define N 100001
int arr[N]; //大数组定义为全局变量
void BInsertSort(int array[], int lenght);
int main()
{
	int i = 1;
	FILE *fr;
	fr = fopen("randomNum.txt", "r");
	for(i = 1; i < N; i ++)
	{
		fscanf(fr, "%d", &arr[i]);
	}
	//while(fscanf(fr, "%d", &arr[i]) != EOF)
	//{
	//	i++;
	//}
	clock_t bg, ed;
	bg = clock();
	BInsertSort(arr, N - 1);
	ed = clock();
	printf("cost time for:%.15f\n", (double)(ed - bg)/CLOCKS_PER_SEC);
	FILE *fw;
	fw = fopen("afterSort.txt", "w");
	for(i = 1; i < N; i++ )
	{
		fprintf(fw, "%d\t", arr[i]);
		if(i%10 == 0)
			fprintf(fw, "%c", '\n');
	}
	fclose(fr);
	fclose(fw);
	return 0;
	
}

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



