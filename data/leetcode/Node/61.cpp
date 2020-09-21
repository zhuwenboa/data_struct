#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//用数组存储链表节点的值然后将其重新赋值到链表中。空间复杂度为O(N)
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL)
            return head;
        vector<int> vec;
        ListNode* p = head;
        while(p != NULL)
        {
            vec.emplace_back(p->val);
            p = p->next;
        }
        int count = vec.size();
        int step;
        if(k > count)
            step = k % count;
        else 
            step = k;
        p = head;
        for(int i = 0; i < step; ++i)
        {
            p->val = vec[count - step + i];
            p = p->next;
        }
        for(int i = step; i < count; ++i)
        {
            p->val = vec[i - step];
            p = p->next;
        }
        return head;
    }
};

class Solution2
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        int n = 0;
        for(ListNode* p = head; p; p = p->next)
            ++n;
        k %= n;
        ListNode* first = head;
        ListNode* second = head;
        //移动到第一个需要移动的节点
        while(k--)
        {
            first = first->next;   
        }
        /*
        这一步执行完： 
            first指针指向链表尾节点
            second指针指向最后一个不需要移动的节点
        */
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        /*
            这是最巧妙也是最核心的一步
            将尾节点连接到头结点
            然后就只需要将最后一个移动的节点设为头结点
        */
        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;
    }
};