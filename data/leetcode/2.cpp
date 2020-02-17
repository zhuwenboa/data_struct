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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = head;
        int carry = 0;
        while(p != NULL || q != NULL)
        {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(p != NULL) 
                p = p->next;
            if(q != NULL)
                q = q->next;
        }
        //如果最后相加后该位上还有数字，则在分配一个结点存储数据
        if(carry > 0)
            curr->next = new ListNode(carry);
        return head->next;
    }
};