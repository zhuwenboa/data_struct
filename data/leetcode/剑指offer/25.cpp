#include<iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* temp = dummyhead;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else 
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1 != NULL)
            temp->next = l1;
        else 
            temp->next = l2;
        return dummyhead->next;
    }
};