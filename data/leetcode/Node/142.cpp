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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            //第一次相遇证明有环，则接着前进找到相交链表的第一个节点
            if(fast == slow)
            {
                //一个节点从头结点出发，另一个节点从相遇节点接着走，两者相遇的节点就是链表成环的首节点
                ListNode* ptr = head;
                while(ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};