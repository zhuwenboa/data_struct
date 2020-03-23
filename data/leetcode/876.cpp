#include<iostream>
#include<algorithm>
#include<memory>

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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(true)
        {
            if(fast->next == NULL)
            {
                return slow;
            }
            else if(fast->next->next == NULL)
            {
                return slow->next;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i < 6; ++i)
    {
        ListNode* temp = new ListNode(i);
        p->next = temp;
        p = p->next;
    }
    Solution res;
    ListNode* temp = res.middleNode(head);
    std::cout << temp->val << "\n";
    p = head;
    while(head != NULL)
    {
        head = head->next;
        delete(p);
        p = head;
    }
}