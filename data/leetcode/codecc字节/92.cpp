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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(!head)
            return NULL;
        if(left == right)
            return head;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* pre = dummyHead;
        pre->next = head;
        ListNode* tail = pre;
        ListNode* last = NULL;
        for(int i = 0; i < left; ++i)
        {
            if(tail->next == NULL)
                return head;
            pre = tail;
            tail = tail->next;
        }
        last = tail;
        for(int i = 0; i < right - left; ++i)
        {
            if(last->next == NULL)
                return head;
            last = last->next;
        }
        auto res = reverse_node(tail, last);
        pre->next = res.first;
        return dummyHead->next;
    }
    pair<ListNode*, ListNode*> reverse_node(ListNode* tail, ListNode* last)
    {
        ListNode* pre = last->next;
        ListNode* p = tail;
        while(pre != last)
        {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return {last, tail};
    }
};