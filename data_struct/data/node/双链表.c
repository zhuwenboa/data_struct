#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int num;
	char name[10];
	int grade;
	struct node *next;
	struct node *last;
};
void creat(struct node  **head,struct node **final)
{
	struct node *p, *temp;
	p = (struct node *)malloc(sizeof(struct node));
	int i;
	printf("请输入数据次数\n");
	scanf("%d", &i);
	int j;                                  
	for(j = 1; j <= i ; j++)
	{
		if(j == 1)
		{
			printf("请输入学号\n");
			scanf("%d", &p->num);
			printf("请输入学生姓名\n");
			scanf("%s", p->name);
			printf("请输入学生成绩\n");
			scanf("%d", &p->grade);
			*head = p;
			p->next = NULL;
			p->last = NULL;
		}	
		else
		{
			temp = p;
			p = (struct node*)malloc(sizeof(struct node));
			printf("请输入学号\n");
			scanf("%d", &p->num);
			printf("请输入学生姓名\n");
			scanf("%s", p->name);
			printf("请输入学生成绩\n");
			scanf("%d", &p->grade);
			temp->next = p;
			p->last = temp;
			temp->next = p;
		}
	}
	p->next = NULL;
	*final = p;
}
void print(struct node *head)
{
	struct node *temp;
	temp = head;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		printf("学号为%d\n", temp->num);
		printf("姓名为%s\n", temp->name);
		printf("成绩为%d\n", temp->grade);
		temp = temp->next;
	}
}
		
void prin(struct node *head)
{
	struct node *temp;
	temp = head;
	printf("\n");
	printf("学生的倒序排法\n");
	while(temp != NULL)
	{
		printf("学号为%d\n", temp->num);
		printf("姓名为%s\n", temp->name);
		printf("成绩为%d\n", temp->num);
		temp = temp->last;
	}
}
int main(void)
{
	struct node *head;
	struct node *final;
	head = final = NULL;
	creat(&head, &final);
	print(head);
	prin(final);
	return 0;
}
