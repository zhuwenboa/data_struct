#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lcs_long(int num[][100], char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	int dir[100][100] = {0};
	int i, j;
	int max_len;
	for(i = 1; i <= len1; i++)
	{
		for(j = 1; j <= len2; j++)
		{
			if(str1[i - 1] == str2[j - 1])
			{
				dir[i][j] = dir[i - 1][j - 1] + 1;
				num[i][j] = 0;
			}
			else if(dir[i - 1][j] > dir[i][j - 1])
			{
				dir[i][j] = dir[i - 1][j];
				num[i][j] = 1;
			}
			else
			{
				dir[i][j] = dir[i][j - 1];
				num[i][j] = -1;
			}
		}
	}
	max_len = dir[len1][len2];
	/*
	for(i = 0; i <= len1; i++)
	{
		for(j = 0; j <= len2; j++)
			if(dir[i][j] > max_len)
				max_len = dir[i][j];
	}
	*/
	return max_len;
}

void print_lcs(int num[][100], char *str1, int i, int j)
{
	if(i == 0 || j == 0)
		return;
	if(num[i][j] == 0)
	{
		print_lcs(num, str1, i - 1, j - 1);
		printf("%c ", str1[i - 1]);
	}
	else if(num[i][j] == 1)
		print_lcs(num, str1, i - 1, j);
	else
		print_lcs(num, str1, i, j - 1);
}

int main(void)
{
	char str1[100] = {0};
	char str2[100] = {0};
	int i,length1,length2,len;
	printf("请输入第一个字符串：");
	scanf("%s", str1);
	printf("请输入第二个字符串：");
	scanf("%s", str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	int num[100][100] = {0};

	len=lcs_long(num, str1,str2);
	printf("最长公共子序列的长度为：%d\n",len);
	printf("最长公共子序列为：");
	print_lcs(num,str1,length1,length2);
	printf("\n");


	return 0;
}


