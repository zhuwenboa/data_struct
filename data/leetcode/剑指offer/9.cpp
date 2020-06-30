#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class CQueue 
{
public:
    CQueue() 
    {

    }
    
    void appendTail(int value) 
    {
        append.push(value);
    }
    
    int deleteHead() 
    {
        if(del.empty() && append.empty())
            return -1;
        if(del.empty())
        {
            while(!append.empty())
            {
                del.push(append.top());
                append.pop();
            }
        }
        int value = del.top();
        del.pop();
        return value;
    }
    stack<int> append;
    stack<int> del;
};
