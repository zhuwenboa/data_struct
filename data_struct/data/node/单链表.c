#include <stdio.h>
#include <stdlib.h>
struct a
{
	int sum;
	struct a *next;
};
void  creat(struct a **head)
{
	struct a *p, *temp;
	int i;
	printf("输入次数\n");
	scanf("%d", &i);
	int j;
	for(j = 1; j<= i; j++)
	{
		if(j == 1)
		{
			p = (struct a*)malloc(sizeof(struct a));
			*head = p;
			printf("请输入第%d次数据\n", j);
			scanf("%d", &p->sum);
		}	
		else
		{	
			temp = p;
			p = (struct a*)malloc(sizeof(struct a));
			printf("请输第%d次数据\n", j);
			scanf("%d", &p->sum);
			temp -> next = p;
			p->next = NULL;
		}
	}
}

struct a* delete(struct a* head)
{
	
}

void print(struct a*head)
{
	struct a *temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->sum);
		temp = temp->next;
	}
}
int main()
{
	struct a * head = NULL;
	creat(&head);
	print(head);
}
