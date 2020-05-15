#include<iostream>
#include<vector>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL)
            return head;
        ListNode* pre = head;
        ListNode* p = head->next;
        if(p == NULL)
            return head;
        ListNode* q = NULL;
        head = p;
        while(p != NULL)
        {
            pre->next = p->next;
            p->next = pre;
            if(q)
                q->next = p;
            q = pre;
            pre = pre->next;
            if(pre == NULL)
                break;
            p = pre->next;
        }
        return head;
    }
};