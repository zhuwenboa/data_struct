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
 
/*
解题思路：
    重排链表: 所以可以先找到中间节点，然后将链表分为两部分。l1 l2。
    然后将l2进行反转，那l2就为 Ln. Ln-1.....Lmid+1
    L1为 L0. L1 ... Lmid。
    然后根据题意，我们将链表进行交叉合并就能得到结果。
*/

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        if(head == nullptr)
            return;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
    //找到链表的中间节点
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //反转链表
    ListNode* reverseList(ListNode* list)
    {
        ListNode* pre = nullptr;
        ListNode* cur = list;
        while(cur != NULL)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    void mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while(l1 != nullptr && l2 != nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};