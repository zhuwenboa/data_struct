#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int value;
	struct node *next;
};

void creat(struct node **head, int value)
{
	struct node * now;
	struct node *preveious;
	struct node *new;
	now = *head;
	preveious = NULL;
	while(now != NULL && now->value < value)
	{
		preveious = now;
		now = now->next;
	}
	new = (struct node *)malloc(sizeof(struct node));
	new->value = value;
	new->next = now;
	if(preveious == NULL)
	{
		*head  = new;
	}
	else
	{
		preveious->next = new;

	}
	free(now);
}
void print(struct node *head)
{
	struct node * temp;
	temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
int main(void)
{
	struct node *head = NULL;
	int p;
	while(1)
	{
		printf("输入（-1）退出\n");
		scanf("%d", &p);
		if(p == -1)
		{
			break;
		}
		else
		{
			 creat(&head, p);
			print(head);
		}
	}
	return 0;
}
