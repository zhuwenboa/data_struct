#include<iostream>
#include<vector>
#include<algorithm>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int count_A = 0;
        int count_B = 0;
        ListNode* p = headA;
        ListNode* p2 = headB;
        while(p != NULL)
        {
            count_A++;
            p = p->next;
        }        
        while(p2 != NULL)
        {
            count_B++;
            p2 = p2->next;
        }
        p = headA;
        p2 = headB;   
        if(count_A > count_B)
        {
            int step = count_A - count_B;
            while(step--)
            {
                p = p->next;
            }
        }    
        else 
        {
            int step = count_B - count_A;
            while(step--)
            {
                p2 = p2->next;
            }
        }
        while(p != p2)
        {
            p = p->next;
            p2 = p2->next;
        }
        return p;
    }
};