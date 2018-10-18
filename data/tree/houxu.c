//后序非递归遍历二叉树
int NoPostOrderTraverse(BiTree t)
{
    SqStack s;
    InitStack(&s);
 
    BiTree cur;     //当前结点  
    BiTree pre = NULL;      //前一次访问的结点
    BiTree tmp;
 
    if(t == NULL)
    {
        fprintf(stderr, "the tree is null.\n");
        return ERROR;
    }
 
    Push(&s, t);
    while(IsEmpty(&s) != 1)
    {
        GetTop(&s, &cur);//
        if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
        {
            printf("%c ", cur->data);    //如果当前结点没有孩子结点或者孩子结点都已被访问过
            Pop(&s, &tmp);
            pre = cur;
        }
        else
        {
            if(cur->rchild != NULL)
            {
                Push(&s, cur->rchild);
            }
            if(cur->lchild != NULL)
            {
                Push(&s, cur->lchild);
            }
        }
    }
    return OK;
}
