#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        if(T.size() == 0)
            return {};
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> st;
        st.push({0, T[0]});
        for(int i = 1; i < T.size(); ++i)
        {
            while(!st.empty())
            {
                auto temp = st.top();
                if(T[i] > temp.second)
                {
                    res[temp.first] = i - temp.first;
                    st.pop();
                }
                else 
                    break;
            }
            st.push({i, T[i]});
        }
        return res;
    }
};