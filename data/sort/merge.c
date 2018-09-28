#include<stdio.h>
#include<stdlib.h>

void merge(int array[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	int *temp;
	temp = (int *)malloc(sizeof(int) * (high - low + 1));
	while(i <= mid && j <= high)                                       //合并数组
	{
		temp[k++] = (array[i] < array[j]) ? array[i++] : array[j++]; 
	}
	while(i <= mid)	 //如果第一个数组不为空，将其输入到数组temp中
	{
		temp[k++] = array[i++];
	}
	while(j <= high) //如果第二个数组不为空，将其输入到数组temp中
	{
		temp[k++] = array[j++];
	}
	for(k = 0, i = low; i < high + 1; i++, k++)
		array[i] = temp[k];
}

void mergesort(int array[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		mergesort(array, low, mid);
		mergesort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

int main()
{
	int a[] = {3, 6, 1, 7, 9, 2, 0};
	int low = 0;
	int high = 6;
	mergesort(a, low, high);
	int i;
	for(i = 0; i < high + 1; i++)
	printf("%d\t", a[i]);
	printf("\n");	
}
