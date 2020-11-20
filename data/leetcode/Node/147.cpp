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
 

//时间复杂度 O(N2) 空间复杂度O(N)
class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        vector<ListNode*> vec;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            vec.push_back(tmp);
            tmp = tmp->next;
        }
        for(int i = 0; i < vec.size(); ++i)
        {
            ListNode* cur = vec[i];
            //ListNode* tmp = cur->next;
            int j = i-1;
            for(; j >= 0; --j)
            {
                if(cur->val < vec[j]->val)
                {
                    //vec[j]->next = tmp;
                    //tmp = vec[j];
                    vec[j+1] = vec[j];
                }
                else 
                    break;
            }
            vec[j+1] = cur;
        }
        for(int i = 0; i < vec.size()-1; ++i)
        {
            vec[i]->next = vec[i+1];
        }
        vec[vec.size()-1]->next = NULL;
        return vec[0];
    }
};


//时间复杂度O(N2) 空间复杂度O(1)
class Solution2 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if(!head)
            return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastSorted = head;        //指向插入排序的最后一个已排序好的节点
        ListNode* currSort = head->next;    //指向当前需要进行插入排序的节点
        while(currSort != NULL)
        {
            if(lastSorted->val <= currSort->val)
            {
                lastSorted = lastSorted->next;
            }
            else 
            {
                ListNode* pre = dummyHead;
                while(pre->next->val <= currSort->val)
                {
                    pre = pre->next;
                }
                lastSorted->next = currSort->next;
                currSort->next = pre->next;
                pre->next = currSort;
            }
            currSort = lastSorted->next;
        }
        return dummyHead->next;
    }
};