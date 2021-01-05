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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tmp = head;
        ListNode* pre = dummyHead;
        while(tmp != NULL)
        {
            ListNode* p = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            tmp = p;
        }
        return dummyHead->next;
    }
};