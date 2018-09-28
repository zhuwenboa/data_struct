#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int long_sum(int a[], int len)
{
	int dir[len];
	memset(dir, 0, sizeof(dir));
	int res = 0;
	int i;
	dir[0] = a[0];
	for(i = 1; i < len + 1; i++)
	{
		if(dir[i - 1] + a[i] > 0)
			dir[i] = dir[i - 1] + a[i];
	}
	for(i = 0; i < len; i++)
	{
		if(res < dir[i])
			res = dir[i];
	}
	return res;
}

int main(void)
{
	int a[] = {1, -2, 4, 6, -8, 2, 3, 4, 5};
	int len = sizeof(a) / sizeof(int);
	int res = long_sum(a, len);
	printf("最长连续子序列和为 %d\n", res);

	return 0;
}
