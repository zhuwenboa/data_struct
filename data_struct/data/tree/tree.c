#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void creat(struct node **head)
{
	int num;
	printf("请输入数据\n");
	scanf("%d", &num);
	if(num == 0)
		*head = NULL;
	else
	{
		*head = (struct node *)malloc(sizeof(struct node));
		(*head)->data = num;
		creat(&(*head)->left);
		creat(&(*head)->right);
	}

}
/*
void print(struct node *head)
{
	struct node *temp = head;
	if(temp != NULL)
	{
		printf("%d\n", temp->data);
		print(temp->left);
		print(temp->right);
	}
}
*/
void print(struct node *head)
{
	struct node *temp = head;
	if(temp != NULL)
	{
		print(temp->left);
		printf("%d\n", temp->data);
		print(temp->right);
	}
}
int main()
{
	struct node *head;
	head = NULL;
 	creat(&head);
	print(head);
	
}
