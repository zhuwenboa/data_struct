#include<iostream>
#include<memory>
#include<vector>
using namespace std;

struct Listnode
{
    int val;
    Listnode* next;
    Listnode(int x) : val(x), next(NULL) {}
};


class solution
{
public:  
    /*
    快慢指针解决
    先让快指针走n步。然后让快慢指针一起走，当快指针到达链表尾时，慢指针就到倒数第n+1个结点，删除慢指针->next即可
    */
    Listnode* RemoveNthFromEnd(Listnode* head, int n)
    {
        Listnode* fast = head;
        Listnode* slow = head;
        while(n--)
        {
            //先走n步
            if(fast->next != NULL)
                fast = fast->next;
            //如果先走n步到达链表尾，则直接删除头结点
            else
            {
                //返回头结点下一个结点即可
                return head->next;   
            }
            
        }
        //然后同时走
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //删除倒数第n个结点
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    
}