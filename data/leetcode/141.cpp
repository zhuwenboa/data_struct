#include<iostream>
#include<memory>
#include<map>
using namespace std;

 struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/*
    找到环中的位置
    bool hasCycle(ListNode *head) 
    {
        ListNode *temp = head->next;
        map<ListNode*, int>flag;
        int count = 0;
        flag.insert({head, count});
        while(temp != NULL)
        {
            ++count;
            auto a = flag.insert({temp, count});  
            
            //证明该元素已经存在，找到环的结点
            if(!a.second)
            {
                return flag[temp];
            } 
        }     
*/
    bool hasCycle(ListNode *head)
    {
        if((head == NULL) || (head->next == NULL))
            return false;
        ListNode *fast, *slow;
        slow = head;
        fast = head->next;
        
        while(fast != slow)
        {
            if(fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;

        }
        return true;
    }
};