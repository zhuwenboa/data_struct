#include<stdio.h>
#include<stdlib.h>

typedef struct Heap
{
	int size;
	int now;
	int *elements;
}heap;

heap *create(int size)
{
	heap *p;
	if(size < 1)
	{
		perror("erro size input");
		exit(1);
	}	
	p = (heap *)malloc(sizeof(heap));
	if(p == NULL)
	{
		perror("erro malloc");
		exit(0);
	}

	p->now = 0;
	p->elements[0] = 0;
	return p;
}

void insert(heap *p, int num)
{
	int i;
	if(p == NULL)
	{
		perror("erro pointer");
		exit(0);
	}
	for(i = ++p->now; p->elements[i / 2] > num; i /= 2)
		p->elements[i] = p->elements[i / 2];
	p->elements[i] = num;
}  

int delete(heap *p)
{
	int child; //孩子结点中较小/较大的
	int i;     //下滤空穴的当前位置
	int Minelement, Lastelement; //要删除最小的结点和完全二叉树最后一个孩子的值
	Minelement = p->elements[1];
	Lastelement = p->elements[p->size--];
	for(i = 1; i * 2 <= p->size; i = child)
	{
		/*找出要删除结点的最小的孩子*/
		child = i * 2;
		if(child != p->size && p->elements[child + 1] < p->elements[child])
			child++;
		if(Lastelement > p->elements[child])
			p->elements[i] = p->elements[child];
		else
			break;
	}
	p->elements[i] = Lastelement;
	return Minelement;

}


int main()
{
	int array[10] = {2, 1, 7, 3, 6, 4, 8, 9, 0, 5};
	heap *p = create(11);
	for(int i = 0; i < 10; i++)
	{
		insert(p, array[i]);
	}
	delete(p);
	for(int i = 0; i < 10; i++)
	{
		array[i] = delete(p);
		printf("%d\t", array [i]);
	}
	printf("\n");
}
