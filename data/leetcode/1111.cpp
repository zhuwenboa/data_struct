#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        //stack<char> st;
        int depth = 0;
        vector<int> res(seq.size(), 0);
        for(int i = 0; i < seq.size(); ++i)
        {
            if(seq[i] == '(')
            {
                //st.push(seq[i]);
                depth++;
                res[i] = depth % 2;                
            }
            else
            {
                res[i] = depth % 2;
                --depth;
            }
        }
        return res;
    }
};