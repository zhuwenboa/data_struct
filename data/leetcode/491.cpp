#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL)
            return head;
        vector<int> vec;
        ListNode* p = head;
        while(p != NULL)
        {
            vec.emplace_back(p->val);
            p = p->next;
        }
        int count = vec.size();
        int step;
        if(k > count)
            step = k % count;
        else 
            step = k;
        p = head;
        for(int i = 0; i < step; ++i)
        {
            p->val = vec[count - step + i];
            p = p->next;
        }
        for(int i = step; i < count; ++i)
        {
            p->val = vec[i - step];
            p = p->next;
        }
        return head;
    }
};