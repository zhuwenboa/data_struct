#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int x) 
    {
        st.push(x);
        if(min_.empty() || x <= min_.top())
            min_.push(x);
    }
    
    void pop() 
    {
        if(st.size() == 0)
            return;
        if(st.top() == min_.top())
        {
            min_.pop();
        }
        st.pop();
    }
    
    int top() 
    {
        if(st.size() == 0)
            return INT32_MIN;
        return st.top();
    }
    
    int min() 
    {
        if(st.size() == 0)
            return INT32_MIN;
        return min_.top();
    }
private:   
    stack<int> st;
    stack<int> min_;
};
