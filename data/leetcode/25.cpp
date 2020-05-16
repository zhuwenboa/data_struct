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
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while(prev != tail)
        {
            ListNode* temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        return {tail, head};
    }


    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        while(head)
        {
            ListNode* tail = pre;
            for(int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if(!tail)
                    return new_head->next;
            }
            ListNode* temp = tail->next;
            auto res = reverse(head, tail);
            head = res.first;
            tail = res.second;
            pre->next = head;
            tail->next = temp;
            pre = tail;
            head = tail->next;
        }
        return new_head->next;
    }
};