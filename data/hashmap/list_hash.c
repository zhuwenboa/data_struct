#include<stdio.h>
#include<stdlib.h>

/*分离链接散列表*/

/*结点结构*/
typedef struct Listnode
{
	int element;
	struct Listnode *next;
}listnode;

/*hash表结构*/
typedef struct Hashtable
{
	int tablesize;                  //哈希表大小
	listnode **list;				

}hashtable;

hashtable *init(int size);
listnode *find(int key, hashtable *h);
void insert(int key, hashtable *h);
int hash(int key, int size);

/*初始化hash表*/
hashtable *init(int size)
{
	hashtable *point;
	if(size < 1)
	{
		perror("small size to init");
		exit(0);
	}
	point = (hashtable *)malloc(sizeof(hashtable));
	point->tablesize = size;
	if(point == NULL)
	{
		perror("erro pointer");
		exit(0);
	}

	point->list = (listnode **)malloc(sizeof(listnode *) *size);
	if(point->list == NULL)
	{
		perror("small size to init");
		exit(0);
	}

	for(int i = 0; i < size; i++)
	{
		point->list[i] = (listnode *)malloc(sizeof(listnode));
		if(point->list[i] == NULL)
		{
			perror("small size to init");
			exit(0);
		}
		else
			point->list[i]->next = NULL;
	}
	return point;
}

listnode *find(int key, hashtable *h)
{
	listnode *p;
	listnode *head;
	head = h->list[hash(key, h->tablesize)];
	p = head->next;
	while(p != NULL && p->element != key)
		p = p->next;
	return p;
}


void insert(int key, hashtable *h)
{
	listnode *p, *temp;
	listnode *l;
	temp = find(key, h);
	if(temp == NULL)          /*key is not found*/
	{
		p = (listnode *)malloc(sizeof(listnode));
		l = h->list[hash(key, h->tablesize)];
		/*头插法*/
		p->element = key;
		p->next = l->next;
		l->next = p;
	}
}


int hash(int key, int size)
{
	int flag;
	flag = key % size;
	return flag;
}

void print(listnode **list, int size)
{	
	listnode *p;
	for(int i = 0; i < size; i++)
	{
		p = list[i]->next;
		while(p != NULL)
		{
			printf("%d\t", p->element);
			p = p->next;
		}
		printf("\n");
	}
}	

int main()
{
	hashtable *h = init(10);
	int key;
	while(1)
	{
		scanf("%d", &key);
		if(key == 0)
			break;
		else
			insert(key, h);
	}
	print(h->list, h->tablesize);
	return 0;
}
