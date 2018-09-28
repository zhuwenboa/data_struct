#include<stdio.h>
void shellsort(int a[], int len)
{
	int k = len / 2;
	int i, j;
	int temp;
	while(k > 0)
	{
		for(i = k; i < len; i++)
		{
			temp = a[i];
			for(j = i - k; j>=0 && a[j] > temp; j-= k)
				a[j + k] = a[j];
			a[j + k] = temp;
		}
		k /= 2;
	}
}
int main()
{
	int i;
	int a[] = {3, 1, 5, 9, 6, 2};
	int len = 6;
	shellsort(a, len);
	for(i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
