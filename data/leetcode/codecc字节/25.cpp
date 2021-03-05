#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        while(head)
        {
            ListNode* tail = pre;
            for(int i = 0; i < k; ++i)
            {
                tail = tail->next;
                //如果长度不足以反转链表 直接返回
                if(tail == NULL)
                    return dummyhead->next;
            }
            ListNode* next_start = tail->next; 
            pair<ListNode*, ListNode*> res = reverse_node(head, tail);
            pre->next = res.first;
            res.second->next = next_start;
            pre = res.second;
            head = next_start;
        }
        return dummyhead->next;
    }

    pair<ListNode*, ListNode*> reverse_node(ListNode* start, ListNode* last)
    {
        ListNode* pre = last->next;
        ListNode* p = start;
        while(pre != last)
        {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return {last, start};
    }
};