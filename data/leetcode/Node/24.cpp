#include<iostream>
#include<algorithm>
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
        if(!head || !head->next)
            return head;
        ListNode* pre = NULL;
        ListNode* n1 = head;
        ListNode* last = head->next;
        head = last;
        while(true)
        {
            n1->next = last->next;
            last->next = n1;
            if(pre != NULL)
                pre->next = last;
            pre = n1;
            n1 = last;
            last = pre;
            if(!last->next || !last->next->next)
            {
                break;
            }
            else 
            {
                n1 = n1->next->next;
                last = last->next->next;
            }
        }
        return head;
    }
};