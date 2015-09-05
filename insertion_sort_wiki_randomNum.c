/*********************************
    > File Name: insertion_sort_wiki_randomNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月04日 星期五 16时35分09秒
 ********************************/
#include<stdio.h>
#include<time.h>
void insertion_sort(int array[], int first, int last);
int main()
{
	int i = 0;
	int arr[100000] = {0};
	FILE *fr;
	fr = fopen("randomNum.txt", "r");
	while(fscanf(fr, "%d", &arr[i]) != EOF)
	{	
		i++;
	}

	clock_t bg, ed;
	bg = clock();
	insertion_sort(arr, 0, sizeof(arr)/sizeof(arr[0]-1));
	ed = clock();
	printf("cost time for:%0.15f\n", (double)(ed-bg)/CLOCKS_PER_SEC);

	FILE * fw;
	fw = fopen("aftersort.txt", "w");
	for(i = 0; i < 100000; i++)
	{
		fprintf(fw, "%d\t", arr[i]);
		if((i+1)%10 == 0)
			fprintf(fw, "%c", '\n');
			
	}
	return 0;
}
void insertion_sort(int array[], int first, int last)
{
	int i, j, temp;
	for(i = first + 1; i <= last; i++)
	{
		temp = array[i];
		for(j = i - 1; j >= first && array[j] > temp; j--)
			array[j + 1] = array[j];
		array[j] = temp;
	}
}
