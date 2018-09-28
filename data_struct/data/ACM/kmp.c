#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str1[11] = "abcabcaefg";
	char str2[10] = {0};
	char str3[20] = {0};
	scanf("%s", str2);
	printf("%s\n", str2);
	int next[10] = {0};
	int i, j, k = 0, temp = 0;
	for(i = 0, j = 0; i < 10; i++)
	{
		if(str1[i] == str2[0])
			next[j++] = i;
	}
	for(i = 0; i < 10; i++)
		printf("%d\n", next[i]);
	for(i = 0, j = next[0]; i < 11 && j < strlen(str2); i++, j++)
	{
		if(str1[i] != str2[j])
		{	
			memset(str3, 0, sizeof(str3));
			temp = 0;
			i = next[++k];
			if(i == 0)
			{
				printf("没有查到\n");
				break;
			}
			j = 0;
		}
		str3[temp++] = str1[i];
	}
	printf(" str3 = %s\n", str3);
	if(j == strlen(str2) - 1)
		printf("找到了\n");
	return 0;
}
