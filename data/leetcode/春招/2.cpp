#include<iostream>
#include<vector>
#include<algorithm>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummHead = new ListNode();
        ListNode* p = dummHead;
        int count_ = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1 == NULL) ? 0 : l1->val;
            int y = (l2 == NULL) ? 0 : l2->val;
            int sum = x + y + count_;
            count_ = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(count_)
        {
            p->next = new ListNode(count_);
        }
        return dummHead->next;
        /*
        代码冗余
        while(l1 != NULL && l2 != NULL)
        {
            int cur_sum = l1->val + l2->val + count_;
            if(cur_sum >= 10)
            {
                count_ = 1;
                cur_sum -= 10;
            }
            else    
                count_ = 0;
            ListNode* node = new ListNode(cur_sum);
            p->next = node;
            p = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            int cur_sum = l1->val + count_;
            if(cur_sum >= 10)
            {
                count_ = 1;
                cur_sum -= 10;
            }
            else    
                count_ = 0;
            ListNode* node = new ListNode(cur_sum);
            p->next = node;
            p = node;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            int cur_sum = l2->val + count_;
            if(cur_sum >= 10)
            {
                count_ = 1;
                cur_sum -= 10;
            }
            else    
                count_ = 0;
            ListNode* node = new ListNode(cur_sum);
            p->next = node;
            p = node;
            l2 = l2->next;
        }
        if(count_ != 0)
        {
            ListNode* node = new ListNode(count_);
            p->next = node;
        }
        return dummHead->next;
        */
    }
};