#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> st1;
        stack<int> st2;
        while(l1 != NULL)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }        
        while(l2 != NULL)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* p = NULL;
        int count = 0;
        while(!st1.empty() && !st2.empty())
        {
            int num1 = st1.top();
            st1.pop();
            int num2 = st2.top();
            st2.pop();
            int sum = num1 + num2 + count;
            if(sum >= 10)
            {
                count = sum / 10;
                sum %= 10;
            }
            else
                count = 0;
            ListNode* temp = new ListNode(sum);
            temp->next = p;
            p = temp;
        }
        while(!st1.empty())
        {
            int num = st1.top();
            st1.pop();
            int sum = num + count;
            if(sum >= 10)
            {
                count = sum / 10;
                sum %= 10;
            }
            else
                count = 0;
            ListNode* temp = new ListNode(sum);
            temp->next = p;
            p = temp;
        }
        while(!st2.empty())
        {
            int num = st2.top();
            st2.pop();
            int sum = num + count;
            if(sum >= 10)
            {
                count = sum / 10;
                sum %= 10;
            }
            else   
                count = 0;
            ListNode* temp = new ListNode(sum);
            temp->next = p;
            p = temp;
        }
        if(count > 0)
        {
            ListNode* temp = new ListNode(count);
            temp->next = p;
            p = temp;
        }
        return p;
    }
};

int main()
{
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(3);
    ListNode* l3 = new ListNode(7);
    l3->next = l2;
    l2 = l3;
    Solution res;
    ListNode* p = res.addTwoNumbers(l1, l2);
    while(p != NULL)
    {
        cout << p->val << "\n";
        p = p->next;
    }
}