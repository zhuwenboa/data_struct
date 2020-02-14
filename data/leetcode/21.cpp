#include<iostream>
#include<memory>

/*
  Definition for singly-linked list.
*/  
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//想在一个链表上操作，不增加新的空间
class Solution {
public:
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2 != NULL)
        {
            return l2;   
        }
        else if(l1 != NULL && l2 == NULL)
        {
            return l1;   
        }

        ListNode* head;
        ListNode* l2_temp = l2;
        ListNode* l1_temp = l1;
        if(l2->val < l1->val)
        {
            l2 = l2->next;
            l2_temp->next = l1;
            l1_temp = l2_temp;
            head = l2_temp;
        }
        else 
            head = l1;
        while (l1 != NULL && l2 != NULL)
        {        
            while(l1!= NULL && l1->val < l2->val)
            {
                l1_temp = l1;
                l1 = l1->next;
            }
            if(l1 == NULL)
            {
                l1_temp->next = l2;
                return head;
            }
            else
            {
                l2_temp = l2;
                l2 = l2->next;
                l2_temp->next = l1_temp->next;
                l1_temp->next = l2_temp;
                l1_temp = l2_temp;
            }
        }
        return head;          
    }
    */
   //分治思想
       ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode* head = new ListNode(0);
            ListNode* pre = head;
            while(l1 != NULL && l2 != NULL)
            {
                if(l1->val < l2->val) 
                {
                    pre->next = l1;
                    l1 = l1->next;
                }
                else 
                {
                    pre->next = l2;
                    l2 = l2->next;
                }
                pre = pre->next;
            }
            pre->next = l1 != NULL ? l1 : l2;
            return head->next;
        }
};