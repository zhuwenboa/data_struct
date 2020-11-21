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

//归并排序
class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        return sortList(head, NULL);
    }
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if(head == NULL)    
            return head;
        if(head->next == tail)
        {
            head->next = NULL;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail)
                fast = fast->next;
        }
        ListNode* mid = slow;
        return mergeList(sortList(head, mid), sortList(mid, tail));
    }
    ListNode* mergeList(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        ListNode* tmp1 = head1, *tmp2 = head2;
        while(tmp1 != NULL && tmp2 != NULL)
        {
            if(tmp1->val < tmp2->val)
            {
                temp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else 
            {
                temp->next = tmp2;
                tmp2 = tmp2->next;
            }
            temp = temp->next;
        }
        while(tmp1 != NULL)
        {
            temp->next = tmp1;
            tmp1 = tmp1->next;
            temp = temp->next;
        }
        while(tmp2 != NULL)
        {
            temp->next = tmp2;
            tmp2 = tmp2->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};