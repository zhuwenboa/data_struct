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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int countA = 0, countB = 0;
        ListNode* tmpA = headA;
        while(tmpA != NULL)
        {
            tmpA =  tmpA->next;
            countA++;
        }
        ListNode* tmpB = headB;
        while(tmpB != NULL)
        {
            tmpB = tmpB->next;
            countB++;
        }
        if(countA > countB)
        {
            int k = countA - countB;
            while(k--)
                headA = headA->next;   
        }
        else 
        {
            int k = countB - countA;
            while(k--)
                headB = headB->next;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};