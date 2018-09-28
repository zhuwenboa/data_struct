#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	int num;
	struct Tree *left;
	struct Tree *right;
}*tree;

void creat(tree *head)
{
	*head = (tree)malloc(sizeof(struct Tree));
	printf("请输入数据\n");
	int data;
	scanf("%d", &data);
	if(data == 0)
	{
		*head = NULL;
	}
	else
	{
		(*head)->num = data;
		creat(&(*head)->left);
		creat(&(*head)->right);
	}
}

void print(tree head)
{
	tree temp = head;
	if(temp != NULL)
	{
		/*先续遍历*/
		printf("%d\n", temp->num);  
		print(temp->left);
		print(temp->right);
		/*中续遍历*/
		/*
		print(temp->left);
		printf("%d\n", temp->num);
		print(temp->left);
		*/ 
		/*后续遍历*/
		/*
		print(temp->lef);
		print(temp->right);
		printf("%d\n", temp->num);
		*/
	}
}

tree findmin(tree head)
{
	tree p = head;
	if(p == NULL)
		return NULL;
	else if(p->left == NULL)
		return p;
	else
		return findmin(p->left);
}

tree find(tree head, int a)
{
	tree p = head;
	if(p == NULL)
		return NULL;
	if(a > p->num)
	{
		return find(p->right, a);
	}
	if(a < p->num)
	{
		return find(p->left, a);
	}
	return head;
}

tree add(tree head, int data)
{
	if(head == NULL)
	{
		head = (tree)malloc(sizeof(struct Tree));
		head->num = data;
		head->left = head->right = NULL;
	}
	else if(data > head->num)
	{
		head->right = add(head->right, data);
	}
	else if(data < head->num)
	{
		head->left = add(head->left, data);
	}
	return head;
}

tree delete(tree head, int data)
{
 	tree temp = head;
	tree p;                                 
	if(temp == NULL)
	{
		perror("not found");
	}
	else if(data < temp->num)
		temp->left = delete(temp->left, data);
	else if(data > temp->num)
		temp->right = delete(temp->right, data);
	else if(temp->left && temp->right)                    //判断要删除的结点是否有两个孩子
	{
		p = findmin(temp->right);                     //找出要删除的结点其右结点中最小的数
		temp->num = p->num;
		temp->right = delete(temp, temp->num);
	}
	else
	{
		if(temp->left == NULL)
			temp = temp->right;
		if(temp->right == NULL)
		       temp = temp->left;
		free(p);	
	}
	return head;
}
int main()
{
	tree head;
	creat(&head);
	print(head);
	int a;
	printf("请输入你想查找的数\n");
	scanf("%d", &a);
	tree p = find(head, a);
	printf("%d\n", p->num);
	printf("请输入你想要插入的数\n");
	int data;
	scanf("%d", &data);
	tree p1 = add(head, data);
	print(p1);
}
