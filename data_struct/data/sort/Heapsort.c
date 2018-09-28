#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void percdown(int a[], int i, int n)
{
	int child;        //孩子结点
	int temp;		  //临时变量
	/*对堆进行整理*/
	for(temp = a[i]; i * 2 + 1 < n; i = child)
	{
		child = i * 2 + 1; 								//当前结点的左孩子结点
		if(child  != n - 1 && a[child] < a[child + 1])  //比较左孩子和右孩子谁大
			child++;
		if(temp < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = temp; 
}

void heapsort(int a[], int n)  //n为数组长度
{
	int i;
	/*初始化堆*/
	for(i = n / 2; i >= 0; i--)
		percdown(a, i, n);
	for(i = n - 1; i >=0 ; i--)
	{
		swap(&a[0], &a[i]);           //将堆顶沉入堆底，并且将堆长度减一
		percdown(a, 0, i); 
	}
	
}

int main()
{
	int a[10] = {1, 3, 2, 9 ,6 ,8, 7, 5, 0, 4};
	int n = 10;
	printf("原数组为： ");
	for(int i = 0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
	heapsort(a, n);
	printf("排序后的数组为: ");
	for(int i = 0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
