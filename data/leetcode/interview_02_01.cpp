#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//方法一 利用哈希表存储已经出现的数字
class Solution 
{
public:
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        unordered_set<int> judge;
        if(head == NULL)
            return head;
        ListNode* pre = head;
        ListNode* q = head->next;
        judge.insert(head->val);
        while(q)
        {
            if(judge.count(q->val))
            {
                pre->next = q->next;
            }
            else
            {   
                pre = pre->next;
                judge.insert(q->val);
            }
            q = q->next;
        }       
        return head;
    }
};