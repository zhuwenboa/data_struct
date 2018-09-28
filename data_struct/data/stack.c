#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack *next;
}stack;

stack * creat(void)
{
	stack * top;
	top  = (stack *)malloc(sizeof(stack));
	top->next = NULL;
	return top;
}

void push(stack *top, int num)                   //入栈
{
	stack * temp;
	temp = (stack *)malloc(sizeof(stack));
	temp->data = num;
	temp->next = top->next;
	top->next = temp;
}

void pop(stack *top)
{
	stack *temp;
	temp = (stack *)malloc(sizeof(stack));
	temp = top->next;
	top->next = temp->next;
	printf("%d\n", temp->data);
	free(temp);
}

int main()
{
	stack  *temp;
	stack *top = creat();
	int a[5] = {1, 2, 3, 4 ,5};
	int i;
	for(i = 0; i < 5; i++)
		push(top, a[i]);
	pop(top);

}

