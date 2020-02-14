#include<iostream>
#include<memory>

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* pre = NULL;
        while(curr != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre =curr;
            curr = temp;
        }
    }
};