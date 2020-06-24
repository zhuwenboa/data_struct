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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* t = head;

        //是否进位
        int count = 0;

        while(l1 != NULL && l2 != NULL)
        {
            int temp = l1->val + l2->val + count;
            count = 0;
            if(temp >= 10)
            {
                count = 1;
                temp %= 10;
            }
            ListNode* p = new ListNode(temp);
            t->next = p;
            t = p;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* node;
        if(l1 != NULL)
            node = l1;
        else
            node = l2;
        while(node != NULL)
        {
            int temp = node->val + count;
            count = 0;
            if(temp >= 10)
            {
                count = 1;
                temp %= 10;
            }
            ListNode* p = new ListNode(temp);
            t->next = p;
            t = p;
            node = node->next;
        }
        if(count == 1)
        {
            ListNode* p = new ListNode(count);
            t->next = p;
        }
        return head->next;
    }
};