#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*找出中间值*/
int center(int a[], int low, int high)
{
	int mid = (low + high)/ 2;
	if(a[low] > a[mid])
		swap(&a[low], &a[mid]);
	if(a[low] > a[high])
		swap(&a[low], &a[high]);
	if(a[mid] > a[high])
		swap(&a[mid], &a[high]);

	swap(&a[mid], &a[high - 1]);
	return a[high - 1];
}

/*插入排序 当数组元素非常小时，插入排序最快*/
void insert(int a[], int len)
{
	int i, j;
	int temp;
	for(i = 1; i < len; i++)
	{
		temp = a[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(temp < a[j])
				a[j + 1] = a[j]; 
			else
				break;
		}
		a[j + 1] = temp;
	}
}

/*三数中值法快速排序*/
void Qsort(int a[], int low, int high)
{
	int i, j;
	int pivot;
	if(low + 2 < high)
	{
		
		pivot = center(a, low, high);
		i = low, j = high - 1;
		for(;;)
		{
			while(a[++i] < pivot);
			while(a[--j] > pivot);
			if(i < j)
				swap(&a[i], &a[j]);
			else
				break;
		}
		swap(&a[i], &a[high - 1]);
		Qsort(a, low, i - 1);
		Qsort(a, i + 1, high);
	}
	/*当分割到一组元素小于等于三个时，用插入排序进行排序*/
	else
		insert(a + low, high - low + 1);
}

int main()
{
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	Qsort(a, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
