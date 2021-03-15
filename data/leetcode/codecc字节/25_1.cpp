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
    pair<ListNode*, ListNode*> reverse_node(ListNode* head, ListNode* tail)
    {
        ListNode* pre = tail->next;
        ListNode* p = head;
        while(pre != tail)
        {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        while(head != NULL)
        {
            ListNode* last = head;
            for(int i = 1; i < k; ++i)
            {
                if(last->next == NULL)
                    return dummyHead->next;
                last = last->next;
            }    
            ListNode* last_next = last->next;
            pair<ListNode*, ListNode*> tmp = reverse_node(head, last);
            p->next = tmp.first;
            tmp.second->next = last_next;
            p = tmp.second;
            head = last_next;
        }
        return dummyHead->next;        
    }
};
