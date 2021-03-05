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
        if(!headA || !headB)
            return NULL;
        ListNode* A_tmp = headA;
        ListNode* B_tmp = headB;
        ListNode* pre_A = NULL;
        ListNode* pre_B = NULL;
        int A_count = 0;
        int B_count = 0;
        while(A_tmp != NULL)
        {
            A_count++;
            pre_A = A_tmp;
            A_tmp = A_tmp->next;
        }
        while(B_tmp != NULL)
        {
            B_count++;
            pre_B = B_tmp;
            B_tmp = B_tmp->next;
        }
        if(pre_A != pre_B)
            return NULL;
        if(A_count > B_count)
            return find_intersect(headA, headB, A_count - B_count);
        else 
            return find_intersect(headB, headA, B_count - A_count);
    }
    ListNode* find_intersect(ListNode* A, ListNode* B, int step_skip)
    {
        while(step_skip--)
        {
            A = A->next;
        }
        while(A && B)
        {
            if(A == B)
                return A;
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
};