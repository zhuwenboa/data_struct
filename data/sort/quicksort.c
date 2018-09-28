#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int p(int a[], int low, int high)
{
	int p1;
    p1 = a[low];
	while(low < high)
	{
		while(low < high && a[high] >= p1)
		{
			high--;
		}
		swap(&a[low], &a[high]);
		while(low < high && a[low] <= p1)
		{
			low++;
		}
		swap(&a[low], &a[high]);
	}
	return low;
}
void paixu(int a[], int low, int high)
{
 	if(low < high)
	{
		int n = p(a, low, high);
		paixu(a, low , n - 1);
		paixu(a, n + 1, high);
	}	

}
int main(void)
{
	
	int a[10] = {3, 4, 6, 9, 10, 5, 13, 3, 1, 0};
	int low = 0;
	int high = 9;
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	paixu(a, low, high);
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
