#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare
{
    bool operator () (const ListNode*a, const ListNode* b)
    {
        return a->val > b->val;
    }
};
//采用优先队列(构建小顶堆)的方法合并K个排序链表
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        //将每组链表的第一个结点加入优先队列中
        for(auto a : lists)
        {
            if(a)
                mem.push(a);
        }
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(!mem.empty())
        {
            ListNode* temp = mem.top();
            mem.pop();
            p->next = temp;
            p = temp;
            if(temp->next != NULL)
                mem.push(temp->next);
        }
        return head->next;        
    }
private:
    //小顶堆
    priority_queue<ListNode*, vector<ListNode*>, compare> mem;
};

//分治的方法（类似于归并排序的合并阶段）, 链表两两合并
class Solution2
{
public:
    ListNode* merge_list(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        while(l1 != NULL)
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        
        return head->next;
    } 
    ListNode* merge(vector<ListNode*>& lists, int low, int high)
    {
        if(low == high)
            return lists[low];
        int mid = (low + high) / 2;
        ListNode* l1 = merge(lists, low, mid);
        ListNode* l2 = merge(lists, mid + 1, high);
        return merge_list(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return nullptr;
        return merge(lists, 0, lists.size() -1);
    }
};