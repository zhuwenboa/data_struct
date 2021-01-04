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
    ListNode* deleteNode(ListNode* head, int val) 
    {
        ListNode* tmp = head;
        ListNode* pre = NULL;
        while(tmp != NULL)
        {
            if(tmp->val == val)
            {
                if(pre == NULL)
                    return head->next;
                else 
                {
                    pre->next = tmp->next;
                    tmp->next = NULL;
                }
            }
            pre = tmp;
            tmp = tmp->next;
        }
        return head;
    }
};