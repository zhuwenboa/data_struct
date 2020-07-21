#include<iostream>
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

void print(ListNode* head)
{
    ListNode* temp = head;
    while(temp != NULL)
    {
        std::cout << temp->val << "    ";
        temp = temp->next;
    }
    std::cout << "\n";
}

class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* pre = head;
        ListNode* n = head;
        ListNode* n1 = head->next;
        int count = 1;
        while(n1 != NULL)
        {
            if(count % 2 == 1)
            {
                n1 = n1->next;
                n = n->next;
            }
            else 
            {
                n->next = n1->next;
                n1->next = pre->next;
                pre->next = n1;
                pre = pre->next;
                n1 = n->next;
                print(head);
            }
            count++;
        }
        return head;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    int i = 2;
    while(i <= 5)
    {
        ListNode* p = new ListNode(i);
        temp->next = p;
        temp = p;
        ++i;
    }
    Solution res;
    head = res.oddEvenList(head);
}