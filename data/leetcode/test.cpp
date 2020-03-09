#include<iostream>


struct Treenode
{
    Treenode(int a) : x(a) {}
    int x;
    Treenode *next;
};


void func(Treenode *head)
{
    Treenode *temp = new Treenode(1);
    head->next = temp;
}

int main()
{
    Treenode *head = new Treenode(0);
    printf("%p\n", &head);
    func(head);
}