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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(n--)
        {
            //先走n步
            if(fast->next != NULL)
                fast = fast->next;
            //如果先走n步到达链表尾，则直接删除头结点
            else
            {
                return head->next;   
            }
            
        }
        //然后同时走
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};