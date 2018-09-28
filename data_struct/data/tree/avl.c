#include<stdio.h>
#include<stdlib.h>

typedef struct avl_tree
{
	int data; 		//值域
	int height;		//深度
	struct avl_tree *left;	//左孩子
	struct avl_tree *right;	//右孩子
}avl;

int max(int a, int b)
{
	return a > b ? a : b;	
}

/*创建搜索二叉树的头结点*/
void create(avl **head, int data)
{
	avl *p = (avl *)malloc(sizeof(avl));
	p->data = data;
	p->height = 1;
	p->left = p->right = NULL;
	*head = p;
}

/*LL型不平衡树*/
avl *left_left_rotation(avl *tree)
{
	avl *p = tree->left;
	tree->left = p->rigth;
	p->rigth = tree;
	tree->height = max(tree->left->height, tree->right->height) + 1;
	p->height = max(p->left->height, p->right->height) + 1;
	return p;
}

/*RR型不平衡树*/
avl *rigth_right_rotation(avl *tree)
{
	avl *p = tree->left;
	tree->left = p->rigth;
	p->rigth = tree;
	tree->height = max(tree->left->height, tree->right->height) + 1;
	p->height = max(p->left->height, p->right->height) + 1;
	return p;
}

/*RL 型不平衡树*/
avl *right_left_rotation(avl *tree)
{
	tree = left_left_rotation(tree);
	return right_right_rotation(tree);
}

/*LR型不平衡树*/
avl *left_right_rotation(avl *tree)
{
	tree = right_right_rotation(tree);
	return left_left_rotation(tree);
}


/*向搜索树中插入结点*/
avl *avltree_insert(avl *p, int data)
{
	if(p == NULL)
	{
		p = (avl *)malloc(sizeof(avl));
		p->data = data;
		p->height = 
	}
	else if(data > p->data)
	{
		p->right = avltree_insert(p->right, data);
		if(p->right->height - p->left->height == 2)
		{
			if(data < p->right->data)
				p = right_right_rotation(p);
			else
				p = rigth_left_rotation(p);
		}
	}
	else if(data < p->data)
	{
		p->left = avltree_insert(p->left, data);
		if(p->left->height - p->right->height == 2)
		{
			if(data < p->left->data)
				left_left_rotation(p);
			else
				left_rigth_rotation(p);
		}
	}
}

/*   */
