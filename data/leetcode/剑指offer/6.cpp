#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<int> reversePrint(ListNode* head) 
    {
        stack<int> st;
        vector<int> ans;
        while(head != NULL)
        {
            st.push(head->val);
            head = head->next;
        }
        ans.reserve(st.size());
        while(!st.empty())
        {
            ans.emplace_back(st.top());
            st.pop();
        }
        return ans;
    }
};