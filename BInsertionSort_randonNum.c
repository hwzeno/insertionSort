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
void insertionSort(int array[], int len);
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
	insertionSort(arr, N - 1);
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
void insertionSort(int array[], int len)
{
	//newPoi待确定位置的数组元素的下标，逐渐递减，直到数组的最后一个元素
	//current为array[newPoi]的前驱的元素的下标，逐渐递减，来定位要与array[newPoi]比较的元素值
	int newPoi = 0, current = 0, tempNew = 0, tempVal = 0;
	for (newPoi = 2; newPoi <= len; newPoi++)//<=
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


