#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> st;
        int pop_index = 0;
        for(int i = 0; i < pushed.size(); ++i)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[pop_index])
            {
                st.pop();
                pop_index++;
            }
        }
        while(!st.empty())
        {
            if(st.top() != popped[pop_index])
                return false;
            st.pop();
            pop_index++;
        }
        return true;
    }
};