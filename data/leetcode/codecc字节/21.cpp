#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* pre = dummyHead;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else 
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 == NULL ? l2 : l1;
        return dummyHead->next;
    }
};